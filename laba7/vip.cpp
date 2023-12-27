#include "vip.hpp"

Vip::Vip(int x, int y) : NPC(VipType, x, y) {
    move_distance = 50;
    kill_distance = 10;
}

Vip::Vip(std::istream& is) : NPC(VipType, is) {
    move_distance = 50;
    kill_distance = 10;
}

bool Vip::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Vip> defender = std::dynamic_pointer_cast<Vip>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Vip::print() {
    std::cout << *this;
}

void Vip::save(std::ostream& os) {
    os << VipType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Vip& Vip) {
    os << "Vip " << *static_cast<NPC*>(&Vip) << std::endl;
    return os;
}