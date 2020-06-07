/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#ifndef ANGELIA_SERVER_H_
#define ANGELIA_SERVER_H_

#include "angelia/recv.h"
#include "angelia/send.h"

int AngeliaServer(const int port_no, int* socket_desc);

int AngeliaServerClose(int* socket_desc);

#endif  // ANGELIA_SERVER_H_
