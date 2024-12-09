cmake_minimum_required(VERSION 3.22)
project(CLD2_CMAKE)

if (MSVC)
  #  add_compile_options(/source-charset:utf-8 /execution-charset:utf-8)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /utf-8")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
else ()
  add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif ()

#aux_source_directory(./internal CLD2_SOURCES)
#list(FILTER MY_LIST EXCLUDE REGEX "test$")

set(CLD2_SOURCES
    internal/cldutil.cc
    internal/cldutil_shared.cc
    internal/compact_lang_det.cc
    internal/compact_lang_det_hint_code.cc
    internal/compact_lang_det_impl.cc
    internal/debug.cc
    internal/fixunicodevalue.cc
    internal/generated_entities.cc
    internal/generated_language.cc
    internal/generated_ulscript.cc
    internal/getonescriptspan.cc
    internal/lang_script.cc
    internal/offsetmap.cc
    internal/scoreonescriptspan.cc
    internal/tote.cc
    internal/utf8statetable.cc
    internal/cld_generated_cjk_uni_prop_80.cc
    internal/cld2_generated_cjk_compatible.cc
    internal/cld_generated_cjk_delta_bi_32.cc
    internal/generated_distinct_bi_0.cc
    internal/cld2_generated_quad0122.cc
    internal/cld2_generated_deltaocta0122.cc
    internal/cld2_generated_distinctocta0122.cc
    internal/cld_generated_score_quad_octa_0122.cc
)

add_library(CLD2-static ${CLD2_SOURCES})
include_directories(./public)

if (CLD2_BUILD_TEST)
  add_executable(CLD2_LANG_TEST ./test/lang.cpp)
  target_link_libraries(CLD2_LANG_TEST PRIVATE CLD2-static)
endif ()