#include "bear.hpp"
#include "muskrat.hpp"
#include "vip.hpp"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {}
Bear::Bear(std::istream &is) : NPC(BearType, is) {}

void Bear::print() {
    std::cout << *this;
}

void Bear::save(std::ostream &os) {
    os << BearType << std::endl;
    NPC::save(os);
}

bool Bear::accept(std::shared_ptr<NPC> attacker) {
    return attacker->visit_Bear(std::dynamic_pointer_cast<Bear>(shared_from_this()));
}

bool Bear::visit_Muskrat(std::shared_ptr<Muskrat> other) {
    fight_notify(other, true);
    return true;
}

bool Bear::visit_Vip(std::shared_ptr<Vip> other) {
    fight_notify(other, true);
    return true;
}


std::ostream &operator<<(std::ostream &os, Bear &Bear) {
    os << "Bear: " << *static_cast<NPC *>(&Bear) << std::endl;
    return os;
}