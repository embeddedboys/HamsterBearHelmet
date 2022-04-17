cmake_minimum_required(VERSION 3.10)
project(my_lvgl)

#set(CMAKE_C_STANDARD 11)
SET(CROSS_COMPILE 1)
set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_C_COMPILER "/home/book/bonbon/mkrootfs/buildroot-2021.02.3/output/host/bin/arm-buildroot-linux-gnueabi-gcc")

SET(TOOLCHAIN_DIR "/home/book/bonbon/mkrootfs/buildroot-2021.02.3/output/host/bin/")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
include_directories(./)
file(GLOB_RECURSE INCLUDES "lvgl/*.h"  "./*.h" "ui/*h" )
file(GLOB_RECURSE SOURCES  "lvgl/*.c" "ui/*.c" )
set(CMAKE_BUILD_TYPE "Release")
set(WARINGS "-Wall -Wextra \
                                                -Wshadow -Wundef -Wmaybe-uninitialized -Wmissing-prototypes -Wno-discarded-qualifiers \
                                                -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized \
                                                -Wno-unused-parameter -Wno-missing-field-initializers -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default  \
                                          -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated  \
                                                -Wempty-body -Wshift-negative-value -Wstack-usage=2048 \
            -Wtype-limits -Wsizeof-pointer-memaccess -Wpointer-arith")
SET(CMAKE_C_FLAGS_RELEASE "-static -O3 ${WARINGS}")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)

add_executable(demo main.c ${SOURCES} ${INCLUDES})

