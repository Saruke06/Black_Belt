cmake_minimum_required(VERSION 3.16)

project(Part_F LANGUAGES CXX)

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

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(Part_F
  ${SRC_DIR}/descriptions.cpp
  ${SRC_DIR}/json.cpp
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/requests.cpp
  ${SRC_DIR}/sphere.cpp
  ${SRC_DIR}/transport_catalog.cpp
  ${SRC_DIR}/transport_router.cpp
  ${SRC_DIR}/utils.cpp
)

target_compile_features(Part_F PRIVATE cxx_std_20)
target_include_directories(Part_F PRIVATE ${SRC_DIR})

if (MSVC)
  target_compile_options(Part_F PRIVATE /W4 /permissive-)
else()
  target_compile_options(Part_F PRIVATE -Wall -Wextra)
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(Part_F PRIVATE
      $<$<CONFIG:Debug>:-fsanitize=address>
      $<$<CONFIG:Debug>:-g>
      $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
      $<$<CONFIG:Debug>:-fno-optimize-sibling-calls>
    )
    target_link_options(Part_F PRIVATE
      $<$<CONFIG:Debug>:-fsanitize=address>
    )
  endif()
endif()
