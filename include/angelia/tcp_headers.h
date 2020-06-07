/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#if defined(__linux__) || defined(__APPLE__)
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
