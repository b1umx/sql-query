set(TARGET sandbox)
add_executable(${TARGET} sandbox.cpp)

target_compile_features(${TARGET} PRIVATE cxx_std_17)

target_link_libraries(${TARGET} PRIVATE sql_query_lib)

