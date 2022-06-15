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
#include <pthread.h>
#include "log.h"
#include "execute_result.h"


void * log_loop(void * arg)
{
  while(1) {
     log_debug("test0\n");   
  }
}


int main(int argc, char * argv[])
{
  UINT8 res = FAILURE;
  pthread_t log_test;

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

  pthread_create(&log_test, NULL, log_loop, NULL);

  while(1) {
    log_debug("test1\n");
  }

  return 0;
}


/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/