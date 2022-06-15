/*
  ** @file           : doip_server.h
  ** @brief          : data server header file
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
  **                 date: 2022-06-12
  **                 author: Jex
  **                 note: first create 
  ******************************************************************
*/


#ifndef __DOIP_SERVER_H__
#define __DOIP_SERVER_H__


#include "data_types.h"


#define     UDP_DISCOVERY_PORT                          (13400)
#define     TCP_DIAGNOSIS_PORT                          (13400)
#define     UDP_DISCOVERY_IPADDR                        (255.255.255.255)
/* doip timer parameter . ms */
#define     DOIP_CTRL                                   (2000)
#define     DOIP_ANNOUNCE_WAIT                          (200)
#define     DOIP_ANNOUNCE_INTERVAL                      (500)
#define     DOIP_DIAGNOSIS_MESSAGE                      (50)
#define     DOIP_DIAGNOSIS_MESSAGE_TIMEOUT              (2000)
/* 5 minutes */
#define     TCP_GENERAL_INACTIVITY                      (5000 * 60)
#define     TCP_INITIAL_INACTIVITY                      (2000)
#define     TCP_ALIVE_CHECK                             (500)
#define     PROCESS_TIME                                (2000)
#define     VEHICLE_DISCOVERY_TIMER                     (5000)


#endif


/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/