# cmake最低版本
cmake_minimum_required(VERSION 3.21)

# 項目名
project(has_include)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 包含模塊
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CMakePrintHelpers)
include(GNUInstallDirs)
include(common)

# 設置編譯選項
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP>;/Zc:__cplusplus;")

set(target has_include)

add_library(${target} INTERFACE)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/has_include.hpp" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

target_include_directories(${target}
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

find_package(Boost REQUIRED)

target_link_libraries(${target} INTERFACE Boost::headers)

target_install(${target} "0.0.1")

set(main has_include_main)
add_executable(${main})
target_sources(${main} PRIVATE
  src/main.cpp
  include/has_include.hpp
  cmake/Findhas_include.cmake)
target_link_libraries(${main}
  PRIVATE
    has_include
)
