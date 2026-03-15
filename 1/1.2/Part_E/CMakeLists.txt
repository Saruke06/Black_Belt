cmake_minimum_required(VERSION 3.16)

project(transport_directory LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      "$ENV{CMAKE_BUILD_TYPE}"
      CACHE STRING "Choose build type.")
  if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
  endif()
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release RelWithDebInfo MinSizeRel)
endif()

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/part_e_san_fail)

add_executable(transport_directory
  ${SRC_DIR}/descriptions.cpp
  ${SRC_DIR}/json.cpp
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/requests.cpp
  ${SRC_DIR}/sphere.cpp
  ${SRC_DIR}/transport_catalog.cpp
  ${SRC_DIR}/transport_router.cpp
  ${SRC_DIR}/utils.cpp
)

target_compile_features(transport_directory PRIVATE cxx_std_17)
target_include_directories(transport_directory PRIVATE ${SRC_DIR})

if (MSVC)
  target_compile_options(transport_directory PRIVATE /W4 /permissive-)
else()
  target_compile_options(transport_directory PRIVATE -Wall -Wextra)
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(transport_directory PRIVATE
      $<$<CONFIG:Debug>:-fsanitize=address>
      $<$<CONFIG:Debug>:-g>
      $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
      $<$<CONFIG:Debug>:-fno-optimize-sibling-calls>
    )
    target_link_options(transport_directory PRIVATE
      $<$<CONFIG:Debug>:-fsanitize=address>
    )
  endif()
endif()
