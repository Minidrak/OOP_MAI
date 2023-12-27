#pragma once
#include "npc.hpp"
#include "visitor.hpp"

class Vip final : public NPC {
public:
    Vip(int x, int y);
    Vip(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Vip& Vip);
};