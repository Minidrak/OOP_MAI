#pragma once
#include "npc.hpp"
#include "visitor.hpp"

class Bear final : public NPC {
public:
    Bear(int x, int y);
    Bear(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Bear& Bear);
};