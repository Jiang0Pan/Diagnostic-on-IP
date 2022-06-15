/*
  ** @file           : socket.h
  ** @brief          : socket header file
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



#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "execute_result.h"
#include "log.h"
#include "socket.h"


#define     LISTEN_MAX              (2)


UINT8 open_udp_server()
{
	int sock = socket()

	// socket();

	return SUCCESS;
}


UINT8 open_tcp_server(UINT8 socknr, int target_addr, int port)
{
	struct sockaddr_in serv_addr;
	int ret = -1;
	int optval = 1;
  int optlen = sizeof(optval);

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sock) {
		log_err("socket create\n");
	}

	ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, optlen);
  if (-1 == ret) {
		log_err("setsockopt SOL_SOCKET SO_REUSEADDR\n");
  }

  /* Nagle disable */
	ret = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &optval, optlen);
  if (-1 == ret) {
		log_err("setsockopt IPPROTO_TCP SO_REUSEADDR\n");
  }  

  /* keepalive */
  ret = setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);
  if (-1 == ret) {
		log_err("setsockopt SOL_SOCKET SO_KEEPALIVE\n");
  }

  optval = 5;
  ret = setsockopt(sock, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
  if (-1 == ret) {
		log_err("setsockopt SOL_TCP TCP_KEEPCNT\n");
  }

  optval = 1;
  ret = setsockopt(sock, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
  if (-1 == ret) {
		log_err("setsockopt SOL_TCP TCP_KEEPIDLE\n");
  }

  optval = 1;
  ret = setsockopt(sock, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);  
  if (-1 == ret) {
		log_err("setsockopt SOL_TCP TCP_KEEPINTVL\n");
  }

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	

	listen();

	return SUCCESS;
}


/*
  ** (C) COPYRIGHT ChengDuHangke END OF FILE
*/