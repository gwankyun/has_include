if(HasInclude_ROOT)
    set(HasInclude_INCLUDE_DIRS ${HasInclude_ROOT}/include ${HasInclude_ROOT}/include/Any)
    set(HasInclude_FOUND TRUE)
    if(NOT TARGET HasInclude::HasInclude)
      add_library(HasInclude_header_only INTERFACE)
      add_library(HasInclude::HasInclude ALIAS HasInclude_header_only)
      set_target_properties(HasInclude_header_only PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${HasInclude_INCLUDE_DIRS}"
      )
    endif()
endif()
