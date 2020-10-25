/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#include "angelia/send.h"

#include "angelia/tcp_headers.h"

int AngeliaSend(const int socket_desc, const void* buffer,
                const uint32_t size) {
#if defined(__linux__) || defined(__APPLE__)
  return send(socket_desc, buffer, size, 0);
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
  return -1;
#else
  Log(error, "OS not supported");
  return -1;
#endif
}
