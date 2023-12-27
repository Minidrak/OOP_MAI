#include "muskrat.hpp"

Muskrat::Muskrat(int x, int y) : NPC(MuskratType, x, y) {
    move_distance = 5;
    kill_distance = 20;
}

Muskrat::Muskrat(std::istream& is) : NPC(MuskratType, is) {
    move_distance = 5;
    kill_distance = 20;
}

bool Muskrat::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Muskrat> defender = std::dynamic_pointer_cast<Muskrat>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Muskrat::print() {
    std::cout << *this;
}

void Muskrat::save(std::ostream& os) {
    os << MuskratType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Muskrat& Muskrat) {
    os << "Muskrat " << *static_cast<NPC*>(&Muskrat) << std::endl;
    return os;
}