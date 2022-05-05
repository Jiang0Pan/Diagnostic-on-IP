/********************************************************************************************
*    Copyright (c) 2022, by Jex.All rights reserved
*********************************************************************************************
*********************************************************************************************
  ** file name      : log.h
  ** purpose        : log header file
  ** author         : JexJiang
  ** version        : v0.0.1
  ** compiler       : gcc
  ** created time   : 2022-5-5
  ** function list  :
*********************************************************************************************
  ** Note：
  ** Copyright (c) 2022 Jex.
  ** Revision History:
                   1.Date: 2022-5-5
                     Author: JexJiang
                     Modification: File created

*********************************************************************************************/


#ifndef  __LOG_H__
#define  __LOG_H__


#ifdef __cplusplus
extern "C" {
#endif 


#include "data_types.h"


typedef enum {
    LOG_EMERG_LEVEL = 0,
    LOG_ALERT_LEVEL,
    LOG_CRIT_LEVEL,
    LOG_ERR_LEVEL,
    LOG_WARNING_LEVEL,
    LOG_NOTICE_LEVEL,
    LOG_INFO_LEVEL,
    LOG_DEBUG_LEVEL,
    LOG_OFF_LEVEL,
}LOG_LEVEL;


uint8 init_log(const char * log_file);
uint8 set_log_level(LOG_LEVEL level);
uint8 log_base(LOG_LEVEL level, const char *file, int line, const char *fmt, ...);


#define         Log_emerg(...)           log_base(LOG_EMERG_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define         log_alert(...)           log_base(LOG_ALERT_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define         log_crit(...)            log_base(LOG_CRIT_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define         log_err(...)             log_base(LOG_ERR_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define         log_warning(...)         log_base(LOG_WARNING_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define         log_notice(...)          log_base(LOG_NOTICE_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define         log_info(...)            log_base(LOG_INFO_LEVEL, __FILE__, __LINE__, __VA_ARGS__)
#define         log_debug(...)           log_base(LOG_DEBUG_LEVEL, __FILE__, __LINE__, __VA_ARGS__)


#ifdef __cplusplus
}
#endif 


#endif


/********************************************************************************************
* (C) COPYRIGHT ShangHaiHeQian END OF FILE
*********************************************************************************************/
