
cmake_minimum_required(VERSION 3.13)

set(module_name python_run_simple_string)

add_executable(${module_name}
    run_simple_string.cpp
)
set_target_properties(${module_name} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(${module_name} PRIVATE Python3::Python)

add_library(c_type_struct SHARED
    c_type_struct.cpp
)
set_target_properties(c_type_struct PROPERTIES DEUBG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
