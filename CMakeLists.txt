cmake_minimum_required(VERSION 3.10)
project(multiscale-curvature-analysis)

add_executable(main main.cpp)

add_library(fileHandler fileHandler.cpp)
add_library(formula formula.cpp)
add_library(userData userData.cpp)
add_library(analysis analysis.cpp)
add_library(dataContainer dataContainer.cpp)
add_library(userInputCLI userInputCLI.cpp)
add_library(gui gui.cpp)
target_link_libraries(main fileHandler formula userData analysis dataContainer userInputCLI gui)