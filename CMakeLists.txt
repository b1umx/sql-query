cmake_minimum_required(VERSION 3.20)

project(SqlQuery
    VERSION 0.0.1
    DESCRIPTION "SQL query generator"
    LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    include(CTest)

endif()

add_subdirectory(src)
add_subdirectory(apps)

if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR SQL_QUERY_BUILD_TESTING) AND BUILD_TESTING)
    # add_subdirectory(tests)
endif()

# Prohibit to build in source directories
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if (EXISTS "${LOC_PATH}")
    message(FATAL_ERROR
        "You cannot build in a source directory (or any directory with a CMakeLists.txt file).\
        Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

