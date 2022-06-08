/*
  ** @file           : main.c
  ** @brief          : main source file
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
  **                 date: 2022-06-08
  **                 author: Jex
  **                 note: first create 
  ******************************************************************
*/


#include <stdio.h>
#include <unistd.h>
#include "log.h"
#include "execute_result.h"


int main(int argc, char * argv[])
{
  UINT8 res = FAILURE;

  res = log_file_handle_init("./demo.log");
  if (SUCCESS != res) {
    printf("log file handle init failure\n");
    return -1;
  }

  res = set_log_level(LOG_DEBUG_LEVEL);
  if (SUCCESS != res) {
    printf("set log level failure\n");
    return -1;
  }

  while(1) {
    log_debug("test");
    sleep(1);
  }

  return 0;
}


/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/