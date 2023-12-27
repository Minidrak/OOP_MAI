#include <gtest/gtest.h>
#include "npc.cpp"
#include "bear.cpp"
#include "muskrat.cpp"
#include "vip.cpp"
#include "npc.hpp"
#include "bear.hpp"
#include "muskrat.hpp"
#include "vip.hpp"

using namespace std;

TEST(FightTest, MuskratAttackVip) {
    shared_ptr<NPC> muskrat = make_shared<Muskrat>(1, 1);
    shared_ptr<NPC> vip = make_shared<Vip>(2,2);
    bool success = vip->accept(muskrat);
    ASSERT_FALSE(success);
}

TEST(FightTest, VipAttackMuskrat) {
    shared_ptr<NPC> muskrat = make_shared<Muskrat>(1, 1);
    shared_ptr<NPC> vip = make_shared<Vip>(2,2);
    bool success = muskrat->accept(vip);
    ASSERT_FALSE(success);
}

TEST(VipTest, VipAttackBear) {
    shared_ptr<NPC> bear = make_shared<Bear>(0, 0);
    shared_ptr<NPC> vip = make_shared<Vip>(2,2);
    bool success = bear->accept(vip);
    ASSERT_FALSE(success);
}

TEST(BearTest, spawn) {
    Bear bear(1,2);
    EXPECT_EQ(bear.type, BearType);
    EXPECT_EQ(bear.x, 1);
    EXPECT_EQ(bear.y,2);
}

TEST(FightTest, BearAttackMuskrat) {
    shared_ptr<NPC> bear = make_shared<Bear>(0, 0);
    shared_ptr<NPC> muskrat = make_shared<Muskrat>(1, 1);
    bool success = muskrat->accept(bear);
    ASSERT_TRUE(success);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
