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

struct NPC;
struct Bear;
struct Muskrat;
struct Vip;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    BearType = 1,
    MuskratType = 2,
    VipType = 3
};
// TEST(FightTest, BearAttackMuskrat) {
//     Bear bear(0,0);
//     Muskrat muskrat(1,1);
//     bool success = bear.accept(make_shared<Bear>(muskrat));
//     ASSERT_TRUE(success);
// }

// TEST(FightTest, BearAttackMuskratAndVip) {
//     Bear bear(0,0);
//     Muskrat muskrat(1,1);
//     Vip vip(2,2);
//     bool success = muskrat.accept(make_shared<Muskrat>(bear)) and vip.accept(make_shared<Bear>(vip));
//     ASSERT_TRUE(success);
// }

// TEST(FightTest, MuskratAttackVip) {
//     Muskrat muskrat(1,1);
//     Vip vip(2,2);
//     bool success = vip.accept(make_shared<Muskrat>(vip));
//     ASSERT_TRUE(success);
// }

// TEST(FightTest, VipAttackMuskrat) {
//     Muskrat muskrat(1,1);
//     Vip vip(2,2);
//     bool success = muskrat.accept(make_shared<Vip>(muskrat));
//     ASSERT_FALSE(success);
// }

TEST(VipTest, VipAttackBear) {
    shared_ptr<NPC> bear = make_shared<Bear>(0, 0);
    shared_ptr<NPC> vip = make_shared<Vip>(2,2);
    bool success = vip->accept(bear);
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
// TEST(BearTest, BearVSBear) {
//     Bear bear1(1,2);
//     Bear bear2(3,4);

//     EXPECT_FALSE(bear1.accept(make_shared<Bear>(bear2)));
// }

// TEST(NpcTest, Creation){
//     set_t npc_set;
//     npc_set.insert(factory(BearType, 10, 20));
//     npc_set.insert(factory(MuskratType, 30, 40));
//     npc_set.insert(factory(VipType, 50, 60));

//     ASSERT_EQ(npc_set.size(), 3);

//     for (const auto& npc: npc_set) {
//         EXPECT_NE(npc, nullptr);
//         EXPECT_TRUE(npc->is_close(npc, 0));
//     }

// }

// TEST(NpcTest, AutoCreation){
//     set_t npc_set;

//     for (size_t i = 0; i < 10; ++i) {
//         npc_set.insert(factory(NpcType(rand() % 3 + 1), rand() % 100, rand() % 100));
//     }

//     EXPECT_EQ(npc_set.size(), 10);
// }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}