include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# add libraries to be built

add_library(mars STATIC
    Executor.cpp
    Grid.cpp
    Rover.cpp
)
