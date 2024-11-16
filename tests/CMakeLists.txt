cmake_minimum_required(VERSION 3.10)
project(tests)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.10.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the test executables
add_executable(test_main test_main.cpp)
add_executable(formulatest formulatest.cc)

target_link_libraries(test_main gtest_main)
target_link_libraries(formulatest gtest_main)

include(GoogleTest)
gtest_discover_tests(test_main)
gtest_discover_tests(formulatest)

#add some tests?
add_test(NAME TestFormulas COMMAND formulatest) 

