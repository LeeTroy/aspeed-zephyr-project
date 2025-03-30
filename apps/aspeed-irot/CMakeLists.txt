# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

zephyr_link_libraries(mbedTLS)
zephyr_link_libraries(dmtf_libspdm)
zephyr_include_directories(mbedTLS)
zephyr_include_directories(.)
zephyr_include_directories(src/include)

target_sources(app PRIVATE src/main.c src/spdm_req.c)
