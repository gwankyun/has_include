# cmake最低版本
cmake_minimum_required(VERSION 3.19)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包含模塊
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CMakePrintHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
project(has_include)

# 設置編譯選項
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP>;/Zc:__cplusplus;")

set(has_include_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
find_package(has_include REQUIRED)

find_package(Boost REQUIRED)

add_executable(has_include)
target_sources(has_include PRIVATE
  src/main.cpp
  include/has_include.hpp
  cmake/Findhas_include.cmake)
target_link_libraries(has_include
  PRIVATE
    has_include::has_include
)
