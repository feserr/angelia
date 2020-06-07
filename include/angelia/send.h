/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#ifndef ANGELIA_SEND_H_
#define ANGELIA_SEND_H_

#include <inttypes.h>

int AngeliaSend(const int socket_desc, const void* buffer, const uint32_t size);

#endif  // ANGELIA_SEND_H_