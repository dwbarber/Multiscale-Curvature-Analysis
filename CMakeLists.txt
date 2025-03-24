cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(multiscale-curvature-analysis)


include(FetchContent)

FetchContent_Declare(
    wxWidgets
    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
    GIT_TAG        v3.2.7.1 # Replace with the desired version or branch
)

# Make wxWidgets available
FetchContent_MakeAvailable(wxWidgets)



add_executable(main main.cpp)

add_library(fileHandler fileHandler.cpp)
add_library(formula formula.cpp)
add_library(userData userData.cpp)
add_library(analysis analysis.cpp)
add_library(dataContainer dataContainer.cpp)
add_library(userInputCLI userInputCLI.cpp)
add_library(gui gui.cpp)

target_link_libraries(main PRIVATE wx::core wx::base fileHandler formula userData analysis dataContainer userInputCLI gui)