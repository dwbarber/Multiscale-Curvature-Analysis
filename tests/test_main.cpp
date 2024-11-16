#include <gtest/gtest.h>

// from source: cd build && cmake ..
// cmake --build .
// cd tests
// you should now be in /build/tests
// ctest (you should be all good now)

// A simple test case
TEST(HelloTest, BasicAssertions) {
  // Expect two strings to be equal.
  EXPECT_EQ("hello", "hello");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}