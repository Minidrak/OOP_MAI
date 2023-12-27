#ifndef BEAR_HPP
#define BEAR_HPP

#include "npc.hpp"

struct Bear final : public NPC {
    Bear(int x, int y);
    Bear(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    
    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visit_Muskrat(std::shared_ptr<Muskrat> other) override;
    bool visit_Vip(std::shared_ptr<Vip> other) override;

    friend std::ostream &operator<<(std::ostream &os, Bear &Bear);
};

#endif