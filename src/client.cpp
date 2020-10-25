/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#include "angelia/client.h"

#include <hephaestus/log.h>
#include <stdio.h>
#include <stdlib.h>

#include "angelia/tcp_headers.h"

int AngeliaClient(const char *ip, const int port_no, int *socket_desc) {
#if defined(__linux__) || defined(__APPLE__)
  *socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (*socket_desc < 0) {
    Log(error, "Could not open the socket.\n");
    return 1;
  }

  struct hostent *server = gethostbyname(ip);
  if (server == NULL) {
    Log(error, "No such host.\n");
    return 2;
  }

  struct sockaddr_in serv_addr;
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = port_no;

  /* Now connect to the server */
  if (connect(*socket_desc, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) <
      0) {
    Log(error, "Could not connect to the server.\n");
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

int AngeliaClientClose(int *socket_desc) { return close(*socket_desc); }
