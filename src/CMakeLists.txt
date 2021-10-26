# Autimatic source and header files enumeration
file(GLOB_RECURSE HEADER_FILES "${sql_query_SOURCE_DIR}/include/sql-query/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")

set(TARGET sql_query_lib)

add_library(${TARGET}
    ${SOURCE_FILES}
    ${HEADER_FILES})

target_include_directories(${TARGET} PUBLIC ../include)

target_compile_features(${TARGET} PUBLIC cxx_std_17)

source_group(TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_FILES})

