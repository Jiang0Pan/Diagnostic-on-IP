/*
  ** @file           : log.h
  ** @brief          : log header file
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


#ifndef  __LOG_H__
#define  __LOG_H__


#include <pthread.h>
#include "data_types.h"


#define     LOG_BUF_SIZE              (2048)
#define     LOG_FILE_NAME_SIZE        (200)
#define     LOG_TEMP_BUFF_SIZE        (512)


typedef enum {
    LOG_OFF_LEVEL = 0,
    LOG_DEBUG_LEVEL,
    LOG_INFO_LEVEL,
    LOG_NOTICE_LEVEL,
    LOG_WARNING_LEVEL,
    LOG_ERR_LEVEL,
    LOG_CRIT_LEVEL,
    LOG_ALERT_LEVEL,
    LOG_EMERG_LEVEL,
}log_level;

typedef struct log_handle {
  UINT8 * log_buf;
  UINT8 * log_temp_buf;
  UINT32 log_len;
  UINT32 log_temp_len;
  UINT32 log_max_size;
  UINT32 log_temp_max_size;
  pthread_mutex_t log_mutex;
  pthread_cond_t log_cond;
} log_handle;

typedef struct log_file_handle {
  log_handle log;
  UINT8 * log_file_name;
  FILE * log_file_handle;
  pthread_mutex_t log_file_mutex;
} log_file_handle;


log_file_handle * log_file_handle_init(const char * file_name);  


#endif



/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/
