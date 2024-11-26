cmake_minimum_required(VERSION 3.29)
project(CLD2_CMAKE)

if (MSVC)
  add_compile_options(/source-charset:utf-8 /execution-charset:utf-8)
else ()
  add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif ()

aux_source_directory(./internal CLD2_SOURCES)
list(FILTER MY_LIST EXCLUDE REGEX "test$")

add_library(CLD2-static ${CLD2_SOURCES})
include_directories(./public)

if (CLD2_BUILD_TEST)
  add_executable(CLD2_LANG_TEST ./test/lang.cpp)
  target_link_libraries(CLD2_LANG_TEST PRIVATE CLD2-static)
endif ()