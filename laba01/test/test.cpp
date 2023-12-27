#include <gtest/gtest.h>
#include "turk_numbers.h"

TEST(test_01, number_translater_test) {
    std::string result;

    number_translater(0, result);
    EXPECT_EQ(result, "sıfır");

    number_translater(5, result);
    EXPECT_EQ(result, "beş");
    
    number_translater(12, result);
    EXPECT_EQ(result, "on iki");

    number_translater(47, result);
    EXPECT_EQ(result, "kırk yedi");

    number_translater(30, result);
    EXPECT_EQ(result, "otuz");

    number_translater(8, result);
    EXPECT_EQ(result, "sekiz");

    number_translater(63, result);
    EXPECT_EQ(result, "altmış üç");
}


 
