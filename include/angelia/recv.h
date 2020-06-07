/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#ifndef ANGELIA_RECV_H_
#define ANGELIA_RECV_H_

#include <inttypes.h>

int AngeliaRecv(const int socket_desc, const uint32_t size, void** buffer);

#endif  // ANGELIA_RECV_H_