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


#define     log_debug(...)             log_base(LOG_DEBUG_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define     log_info(...)              log_base(LOG_INFO_LEVEL,  __FILE__, __LINE__, __VA_ARGS__)
#define     log_notice(...)            log_base(LOG_NOTICE_LEVEL,  __FILE__, __LINE__, __VA_ARGS__)
#define     log_warning(...)           log_base(LOG_WARNING_LEVEL,  __FILE__, __LINE__, __VA_ARGS__)
#define     log_err(...)               log_base(LOG_ERR_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define     log_crit(...)              log_base(LOG_ERR_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define     log_alert(...)             log_base(LOG_CRIT_LEVEL, __FILE__, __LINE__, __VA_ARGS__) 
#define     log_emerg(...)             log_base(LOG_EMERG_LEVEL, __FILE__, __LINE__, __VA_ARGS__)


typedef struct log_handle {
  char * log_buf;
  char * log_temp_buf;
  UINT32 log_len;
  UINT32 log_temp_len;
  UINT32 log_max_size;
  UINT32 log_temp_max_size;
  pthread_mutex_t log_mutex;
  pthread_cond_t log_cond;
} log_handle;

typedef struct log_file_handle {
  log_handle log;
  char * log_file_name;
  FILE * log_file;
  log_level level;
  pthread_t log_pthread;
  pthread_mutex_t log_file_mutex;
} log_file_handle;


UINT8 log_file_handle_init(char * file_name);
UINT8 set_log_level(log_level level);
UINT8 log_base(log_level level, const char * file, int line, const char * fmt, ...);  


#endif



/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/
