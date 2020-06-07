/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#include "angelia/recv.h"

#include "angelia/tcp_headers.h"

int AngeliaRecv(const int socket_desc, const uint32_t size, void** buffer) {
#if defined(__linux__) || defined(__APPLE__)
  return recv(socket_desc, *buffer, size, 0);
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
  return -1;
#else
  Log(error, "OS not supported");
  return -1;
#endif
}
