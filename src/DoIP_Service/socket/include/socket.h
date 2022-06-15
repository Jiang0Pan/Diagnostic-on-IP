/*
  ** @file           : soad_socket.h
  ** @brief          : soad socket header file
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
  **                 date: 2022-06-10
  **                 author: Jex
  **                 note: first create 
  ******************************************************************
*/


#ifndef  __SOCKET_H__
#define  __SOCKET_H__


#include "data_types.h"


 
typedef struct socket_handle {
  int handle;
  int connect_handle;
  int target_address;
  int target_port;
  int state;
  int socker_type;
}socker_handle;


#endif


/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/
