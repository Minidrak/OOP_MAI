#include "bear.hpp"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {
    move_distance = 5;
    kill_distance = 10;
}

Bear::Bear(std::istream& is) : NPC(BearType, is) {
    move_distance = 5;
    kill_distance = 10;
}

bool Bear::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Bear> defender = std::dynamic_pointer_cast<Bear>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Bear::print() {
    std::cout << *this;
}

void Bear::save(std::ostream& os) {
    os << BearType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Bear& Bear) {
    os << "Bear " << *static_cast<NPC*>(&Bear) << std::endl;
    return os;
}