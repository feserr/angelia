cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

set(NAME angelia)
set(REPO_VERSION 0.1.0)

project(${NAME} VERSION ${REPO_VERSION} DESCRIPTION "TCP socket library")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Set the debug or relese mode.
if (CMAKE_BUILD_TYPE MATCHES Debug)
  # Debug level
  add_definitions(-DDEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
  # Optimization level
else ()
  message(FATAL_ERROR "Set the build type with -DCMAKE_BUILD_TYPE=<type>")
endif()

add_subdirectory(external/hephaestus)

set(SOURCE_FILES
  src/server.cpp
  src/client.cpp
  src/send.cpp
  src/recv.cpp)

set(HEADER_PATHS include)
set(HEADER_FILES
  include/angelia/tcp_headers.h
  include/angelia/server.h
  include/angelia/client.h
  include/angelia/send.h
  include/angelia/recv.h)

include_directories(
  ${HEADER_PATHS}
  ${hephaestus_SOURCE_DIR}/include)

add_library(${NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES})
add_library(angelia::angelia ALIAS ${NAME})

# Set the debug or relese mode.
if (CMAKE_BUILD_TYPE MATCHES Debug)
  # Debug level
  add_definitions(-DDEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
  # Optimization level
else ()
  message(FATAL_ERROR "Set the build type with -DCMAKE_BUILD_TYPE=<type>")
endif()

include(GenerateExportHeader)
generate_export_header(${NAME})

target_include_directories(${NAME}
  PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})

target_link_libraries(${NAME}
  hephaestus::hephaestus)