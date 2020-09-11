# cmake最低版本
cmake_minimum_required(VERSION 3.18)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包含模塊
include(CMakePrintHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
project(has_include)

# 設置編譯選項
add_compile_options(
  "$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP>")

# 執行文件
add_executable(main)

# 添加源碼
target_sources(main PRIVATE src/main.cpp include/has_include.hpp)

# 頭文件目錄
target_include_directories(main
  PRIVATE
    include)
