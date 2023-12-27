#include <gtest/gtest.h>
#include "npc.cpp"
#include "vip.cpp"
#include "muskrat.cpp"
#include "bear.cpp"
#include "visitor.hpp"

std::shared_ptr<NPC> bear = std::make_shared<Bear>(21, 17);
std::shared_ptr<NPC> muskrat = std::make_shared<Muskrat>(20, 16);
std::shared_ptr<NPC> vip = std::make_shared<Vip>(100, 17);
std::shared_ptr<Visitor> bear_visitor = std::make_shared<BearVisitor>();
std::shared_ptr<Visitor> muskrat_visitor = std::make_shared<MuskratVisitor>();
std::shared_ptr<Visitor> vip_visitor = std::make_shared<VipVisitor>();

TEST(VisitorTest, Bear) {
    ASSERT_FALSE(bear_visitor->visit(std::static_pointer_cast<Bear>(bear)));
    ASSERT_TRUE(bear_visitor->visit(std::static_pointer_cast<Muskrat>(muskrat)));
    ASSERT_TRUE(bear_visitor->visit(std::static_pointer_cast<Vip>(vip)));
}

TEST(VisitorTest, Muskrat) {
    ASSERT_FALSE(muskrat_visitor->visit(std::static_pointer_cast<Bear>(bear)));
    ASSERT_FALSE(muskrat_visitor->visit(std::static_pointer_cast<Muskrat>(muskrat)));
    ASSERT_TRUE(muskrat_visitor->visit(std::static_pointer_cast<Vip>(vip)));
}

TEST(VisitorTest, Vip) {
    ASSERT_FALSE(vip_visitor->visit(std::static_pointer_cast<Bear>(bear)));
    ASSERT_FALSE(vip_visitor->visit(std::static_pointer_cast<Muskrat>(muskrat)));
    ASSERT_FALSE(vip_visitor->visit(std::static_pointer_cast<Vip>(vip)));
}

TEST(AcceptTest, Bear) {
    ASSERT_FALSE(bear->accept(bear));
    ASSERT_TRUE(muskrat->accept(bear));
    ASSERT_TRUE(vip->accept(bear));    
}

TEST(AcceptTest, Muskrat) {
    ASSERT_FALSE(bear->accept(muskrat));
    ASSERT_FALSE(muskrat->accept(muskrat));
    ASSERT_TRUE(vip->accept(muskrat));
}

TEST(AcceptTest, Vip) {
    ASSERT_FALSE(bear->accept(vip));
    ASSERT_FALSE(muskrat->accept(vip));
    ASSERT_FALSE(vip->accept(vip));
}

TEST(DistanceTest, IsClose) {
    ASSERT_FALSE(bear->is_close(vip));
    ASSERT_FALSE(vip->is_close(muskrat));
    ASSERT_TRUE(muskrat->is_close(bear));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}