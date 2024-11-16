cmake_minimum_required(VERSION 3.10)
project(multiscale-curvature-analysis)
add_executable(main main.cpp)
add_library(analysis analysis.cpp)
add_library(dataContainer dataContainer.cpp)
add_library(fileConvert fileConvert.cpp)
add_library(gui gui.cpp)

add_subdirectory(tests)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/release-1.10.0.zip
# )

#Add the Eigen library
FetchContent_Declare(
    Eigen
    URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip
)
FetchContent_MakeAvailable(Eigen)
include_directories(${eigen_SOURCE_DIR})



# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)