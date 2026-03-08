# Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


# basic packagesearching and setup
# (further support will be needed, this is a preliminary release!)
set(OPENSSL_EXPECTED_VERSION 1.0.0)

# Pre-set version to bypass multi-line OPENSSL_VERSION_NUMBER parsing (OpenSSL 3.x)
if(NOT _OPENSSL_VERSION)
  set(_OPENSSL_VERSION "3.0.0")
endif()

find_package(OpenSSL REQUIRED)

add_library(openssl INTERFACE)

target_link_libraries(openssl
  INTERFACE
    ${OPENSSL_LIBRARIES}
    $<$<BOOL:${WIN32}>:crypt32>
    $<$<BOOL:${WIN32}>:ws2_32>)

target_include_directories(openssl
  INTERFACE
    ${OPENSSL_INCLUDE_DIR})
