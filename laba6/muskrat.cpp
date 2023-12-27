#include "bear.hpp"
#include "muskrat.hpp"
#include "vip.hpp"

Muskrat::Muskrat(int x, int y) : NPC(MuskratType, x, y) {}
Muskrat::Muskrat(std::istream &is) : NPC(MuskratType, is) {}

void Muskrat::print() {
    std::cout << *this;
}

void Muskrat::save(std::ostream &os) {
    os << MuskratType << std::endl;
    NPC::save(os);
}

bool Muskrat::accept(std::shared_ptr<NPC> attacker) {
    return attacker->visit_Muskrat(std::dynamic_pointer_cast<Muskrat>(shared_from_this()));
}

bool Muskrat::visit_Bear(std::shared_ptr<Bear> other) {
    fight_notify(other, true);
    return true;
}
 
std::ostream &operator<<(std::ostream &os, Muskrat &Muskrat) {
    os << "Muskrat: " << *static_cast<NPC *>(&Muskrat) << std::endl;
    return os;
}