/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#include "angelia/server.h"

#include <hephaestus/log.h>
#include <stdio.h>
#include <stdlib.h>

#include "angelia/tcp_headers.h"

int AngeliaServer(const int port_no, int *socket_desc) {
#if defined(__linux__) || defined(__APPLE__)
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    Log(error, "Could not open the socket.\n");
    return 1;
  }

  // Initialize socket structure.
  struct sockaddr_in serv_addr;
  bzero((char *)&serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = port_no;

  // Now bind the host address using bind() call.
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    Log(error, "Could not bind the host to the address.\n");
    return 2;
  }

  // Now start listening for the clients, here process will
  // go in sleep mode and will wait for the incoming connection.
  listen(sockfd, 5);
  struct sockaddr_in cli_addr;
  unsigned int clilen = sizeof(cli_addr);

  // Accept actual connection from the client.
  *socket_desc = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (*socket_desc < 0) {
    Log(error, "Could not accept the client.\n");
    return 3;
  }
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
  return -1;
#else
  Log(error, "OS not supported");
  return -1;
#endif

  return 0;
}

int AngeliaServerClose(int *socket_desc) { return close(*socket_desc); }
