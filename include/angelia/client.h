/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#ifndef ANGELIA_CLIENT_H_
#define ANGELIA_CLIENT_H_

#include "angelia/recv.h"
#include "angelia/send.h"

int AngeliaClient(const char* ip, const int port_no, int* socket_desc);

int AngeliaClientClose(int* socket_desc);

#endif  // ANGELIA_CLIENT_H_
