#ifndef MUSKRAT_HPP
#define MUSKRAT_HPP

struct Muskrat final : public NPC {
    Muskrat(int x, int y);
    Muskrat(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visit_Bear(std::shared_ptr<Bear> other) override;
    
    friend std::ostream &operator<<(std::ostream &os, Muskrat &Muskrat);
};

#endif