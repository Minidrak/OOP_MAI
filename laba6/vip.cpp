#include "bear.hpp"
#include "vip.hpp"
#include "muskrat.hpp"

Vip::Vip(int x, int y) : NPC(VipType, x, y) {}
Vip::Vip(std::istream &is) : NPC(VipType, is) {}

void Vip::print() {
    std::cout << *this;
}

void Vip::save(std::ostream &os) {
    os << VipType << std::endl;
    NPC::save(os);
}

bool Vip::accept(std::shared_ptr<NPC> attacker) {
    return attacker->visit_Vip(std::dynamic_pointer_cast<Vip>(shared_from_this()));
}



std::ostream &operator<<(std::ostream &os, Vip &Vip) {
    os << "Vip: " << *static_cast<NPC *>(&Vip) << std::endl;
    return os;
}