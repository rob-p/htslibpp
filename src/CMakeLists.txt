add_executable(test_read 
test_read.cpp
)

target_include_directories(test_read
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_link_libraries(test_read hts)