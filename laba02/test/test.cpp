#include <gtest/gtest.h>
#include "Three.h"

TEST(test_01, add_tests) {
    Three first1 ("12021");
    Three second1 ("10122");
    Three third1 = first1 + second1;
    Three result1("22220");
    ASSERT_TRUE(third1 == result1);

    Three f2 ("1000");
    Three s2 ("1000");
    Three t2 = f2 + s2;
    Three r2("2000");
    ASSERT_TRUE(t2 == r2);

    Three f3 ("202120");
    Three s3 ("121111");
    Three r3 = f3 + s3;
    Three t3("1101001");
    ASSERT_TRUE(r3 == t3);

    Three f4 ("200");
    Three s4 ("10");
    Three t4 = f4 + s4;
    Three r4("102");
    ASSERT_FALSE(r4 == t4);

    Three f5 ("1");
    Three s5 ("1");
    Three t5 = f5 + s5;
    Three r5("2");
    ASSERT_TRUE(t5 == r5);
}

TEST(test_07, remove_test) {
    Three first ("2000");
    Three second ("2000");
    Three third = second - first;
    Three res ("0");
    ASSERT_TRUE(res == third);
}

TEST(test_06, remove_test) {
    Three first ("120");
    Three second ("10");
    Three third = first - second;
    Three res("110");
    ASSERT_TRUE(res == third);
}

TEST(test_05, remove_test) {
    Three first ("10");
    Three second ("1");
    Three third = first - second;
    Three res("1");
    ASSERT_FALSE(res == third);
}

TEST(test_04, remove_test) {
    Three first ("100");
    Three second ("11");
    Three third = first - second;
    Three res("12");
    ASSERT_TRUE(res == third);
}

TEST(test_03, remove_test) {
    Three first ("1111");
    Three second ("1110");
    Three third = first - second;
    Three res("1");
    ASSERT_TRUE(res == third);
}

TEST(test_02, remove_test) {
    Three first ("1222112");
    Three second ("210211");
    Three third = first - second;
    Three res("1011201");
    ASSERT_TRUE(res == third);
}

TEST(test_01, remove_test) {
    Three first ("0");
    Three second ("0");
    Three third = first - second;
    Three res("0");
    ASSERT_TRUE(res == third);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
