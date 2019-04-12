# Here is the main program

add_executable(MarsTest MarsTest.cpp)
target_link_libraries(MarsTest gtest)
target_link_libraries(MarsTest mars)

include_directories(${PROJECT_SOURCE_DIR}/include)
