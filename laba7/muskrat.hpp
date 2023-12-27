#pragma once
#include "npc.hpp"
#include "visitor.hpp"

class Muskrat final : public NPC {
public:

    Muskrat(int x, int y);
    Muskrat(std::istream& is);

    virtual bool accept(const std::shared_ptr<NPC>& attacker) const override;

    void print() override;
    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Muskrat& Muskrat);
};