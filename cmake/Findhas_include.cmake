if(has_include_ROOT)
    set(has_include_INCLUDE_DIRS ${has_include_ROOT}/include ${has_include_ROOT}/include/Any)
    set(has_include_FOUND TRUE)
    if(NOT TARGET has_include::has_include)
      add_library(has_include_header_only INTERFACE)
      add_library(has_include::has_include ALIAS has_include_header_only)
      set_target_properties(has_include_header_only PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${has_include_INCLUDE_DIRS}"
      )
    endif()
endif()
