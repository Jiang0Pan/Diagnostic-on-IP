/********************************************************************************************
*    Copyright (c) 2022, by Jex.All rights reserved
*********************************************************************************************
*********************************************************************************************
  ** file name      : log.c
  ** purpose        : log source file
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


#ifdef __cplusplus
extern "C" {
#endif 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "log.h"


#define     FIIL_NAME_SIZE             (20)
#define     MESSAGE_SIZE               (512)


typedef strcut {   
    FILE * fp;
    LOG_LEVEL level;
}log_info;

static log_info log = {
    .fp = NULL;
    .level = LOG_OFF_LEVEL;
};


uint8 init_log(const char * log_file)
{
    if (NULL == log_file) {
        log_debug("log file is NULL\n");
        return -1;
    }

    log.fp = fopen(log_file, "wb+");
    if (NULL == log.fp) {
        log_err("log init failure\n");
        return -1;
    }
    else {
        log_debug();
    }

    return 0;
}


uint8 set_log_level(LOG_LEVEL level)
{
    log.level = level;

    return 0;
}


uint8 log_base(LOG_LEVEL level, const char *file, int line, const char *fmt, ...)
{
    if (log.level > level) 
        return -1;

    int file_len = strlen(file);
    const char * file_name  = file_len > FIIL_NAME_SIZE ? file + file_len - FIIL_NAME_SIZE : file;

    struct timeval now;
    gettimeofdata(&now, NULL);

    char msg_buf[MESSAGE_SIZE] = {0x00};

    sprintf(msg_buf,"[%02ld.%06ld %s:%d]", now.tv_sec % 60, now.tv_usec, fileName, line);

    va_list args;
    va_start(args, fmt);

    vsprintf(msg_buf + strlen(msg_buf), fmt, args);
    va_end(args);

    if (NULL != log.fp) {
        fprintf(g_log_file, s_msgBuf);
        fprintf(g_log_file, "\n");
        fflush(g_log_file);
        int fd = fileno(g_log_file);
        fsync(fd);
    }
    else {
        printf("%s\n", msg_buf);
    }

    return 0;
}


#ifdef __cplusplus
}
#endif 


/********************************************************************************************
* (C) COPYRIGHT ShangHaiHeQian END OF FILE
*********************************************************************************************/
