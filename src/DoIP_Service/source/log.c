/*
  ** @file           : log.c
  ** @brief          : log source file
  **
  ** @attention
  **
  ** Copyright (c) 2022 Jex.
  ** All rights reserved.
  **
  ** This software is licensed by Jex under Ultimate Liberty license
  **
  ** Release notes:
  ******************************************************************
  **                 date: 2022-06-07
  **                 author: Jex
  **                 note: first create 
  ******************************************************************
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "execute_result.h"
#include "log.h"


static log_file_handle * g_log_fhandle = NULL;

static UINT8 log_handle_init(log_handle * log);
static void * log_file_pthread(void * arg);
static UINT8 write_log_file(log_file_handle * log_fhandle);

UINT8 log_file_handle_init(char * file_name)
{
	UINT8 res = 0;
  int ret = 0;

	g_log_fhandle = malloc(sizeof(log_file_handle));
	if (NULL == g_log_fhandle) {
		return FAILURE;
	}

	g_log_fhandle->log_file_name = file_name;
	ret = pthread_mutex_init(&(g_log_fhandle->log_file_mutex), NULL);
  if (ret != 0) {
    free(g_log_fhandle);  
    g_log_fhandle = NULL;
    g_log_fhandle->log_file_name = NULL;

    return FAILURE;
  }

  res = log_handle_init(&(g_log_fhandle->log));
  if (SUCCESS != res) {
      free(g_log_fhandle);
      g_log_fhandle = NULL;
      g_log_fhandle->log_file_name = NULL;
      pthread_mutex_destroy(&(g_log_fhandle->log_file_mutex));

      return FAILURE;
  }

  g_log_fhandle->level = LOG_OFF_LEVEL;
  pthread_create(&(g_log_fhandle->log_pthread), NULL, log_file_pthread, (void *)g_log_fhandle);

	return SUCCESS;
}


UINT8 set_log_level(log_level level)
{
  if (NULL == g_log_fhandle) {
    return FAILURE;
  }

  g_log_fhandle->level = level;

  return SUCCESS;  
}


UINT8 log_base(log_level level, const char * file, int line, const char * fmt, ...)
{
  if (NULL == g_log_fhandle) {
    return FAILURE;
  }

  if (((g_log_fhandle->level) == LOG_OFF_LEVEL) || (level < (g_log_fhandle->level))) {
    return FAILURE;
  }
  else {
    if (pthread_mutex_lock(&(g_log_fhandle->log.log_mutex)) == 0) {
      time_t temp_time;
      temp_time = time(NULL);

      memset(g_log_fhandle->log.log_temp_buf, 0, g_log_fhandle->log.log_temp_len);

      sprintf(g_log_fhandle->log.log_temp_buf, "[%s] %s %d:", ctime(&temp_time), file, line);
      g_log_fhandle->log.log_temp_len = strlen(g_log_fhandle->log.log_temp_buf);
      g_log_fhandle->log.log_temp_buf[g_log_fhandle->log.log_temp_len - 1] = '\0';

      va_list args;
      va_start(args, fmt);
      vsprintf((g_log_fhandle->log.log_temp_buf + strlen(g_log_fhandle->log.log_temp_buf)), fmt, args);
      va_end(args);

      g_log_fhandle->log.log_temp_len = strlen(g_log_fhandle->log.log_temp_buf);

      memcpy(g_log_fhandle->log.log_buf, g_log_fhandle->log.log_temp_buf, g_log_fhandle->log.log_temp_len);
      g_log_fhandle->log.log_len = g_log_fhandle->log.log_temp_len;
      
      pthread_mutex_unlock(&(g_log_fhandle->log.log_mutex));
      pthread_cond_signal(&(g_log_fhandle->log.log_cond));
    }
  }

  return SUCCESS;
}


static UINT8 log_handle_init(log_handle * log)
{
	log->log_buf = malloc(sizeof(UINT8) * LOG_BUF_SIZE);
	if (NULL == log->log_buf)
		return FAILURE;
	
	log->log_temp_buf = malloc(sizeof(UINT8) * LOG_TEMP_BUFF_SIZE);
	if (NULL == log->log_temp_buf) {
        free(log->log_buf);
        log->log_buf = NULL;
        return FAILURE;
  }

	log->log_max_size = LOG_BUF_SIZE;
	log->log_len = 0;
	log->log_temp_max_size = LOG_TEMP_BUFF_SIZE;
	log->log_temp_len = 0;
	memset(log->log_buf, 0, log->log_max_size);
	memset(log->log_temp_buf, 0, log->log_temp_max_size);

	pthread_mutex_init(&(log->log_mutex), NULL);
	pthread_cond_init(&(log->log_cond), NULL);

	return SUCCESS;
}


static void * log_file_pthread(void * arg)
{
  log_file_handle * log_fhandle = (log_file_handle *)arg;

  while(1) {
    if (pthread_mutex_lock(&(log_fhandle->log.log_mutex)) == 0) {
      if(pthread_cond_wait(&(log_fhandle->log.log_cond), &(log_fhandle->log.log_mutex)) == 0) {
        write_log_file(g_log_fhandle);
        pthread_mutex_unlock(&(log_fhandle->log.log_mutex));
      }
    }
  }

  return NULL;
}

static UINT8 write_log_file(log_file_handle * log_fhandle)
{
  int ret = 0;
  UINT8 res = FAILURE;

  if(pthread_mutex_lock(&(log_fhandle->log_file_mutex)) == 0) {

    log_fhandle->log_file = fopen(log_fhandle->log_file_name, "a+");
    if (NULL != log_fhandle->log_file) {
      ret = fwrite(log_fhandle->log.log_buf, log_fhandle->log.log_len, 1, log_fhandle->log_file);
      if (ret == log_fhandle->log.log_len) {
        memset(log_fhandle->log.log_buf, 0, log_fhandle->log.log_len);
        log_fhandle->log.log_len = 0;
        fclose(log_fhandle->log_file);
        log_fhandle->log_file = NULL;

        res = SUCCESS;
      }
      else {
        res = FAILURE;
      }
    }

    pthread_mutex_unlock(&(log_fhandle->log_file_mutex));
  }

  return res;
}

/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/
