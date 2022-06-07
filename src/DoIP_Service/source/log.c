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


static UINT8 log_handle_init(log_handle * log);

log_file_handle * log_file_handle_init(const char * file_name)
{
	int res = 0;

	log_file_handle * log_file_handle = malloc(sizeof(log_file_handle));
	if (NULL == log_file_handle) {
		return NULL;
	}

	log_file_handle->log_file_name = file_name;
	pthread_mutex_init(&(log_file_handle->log_file_mutex), NULL);

	return log_file_handle;
}


static UINT8 log_handle_init(log_handle * log)
{
	log->log_buf = malloc(sizeof(UINT8) * LOG_BUF_SIZE);
	if (NULL == log->log_buf)
		return FAILURE;
	
	log->log_temp_buf = malloc(sizeof(UINT8) * LOG_TEMP_BUFF_SIZE);
	if (NULL == log->log_temp_buf)
		return FAILURE;

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


/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/
