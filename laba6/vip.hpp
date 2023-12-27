#ifndef VIP_HPP
#define VIP_HPP

struct Vip final : public NPC {
    Vip(int x, int y);
    Vip(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> attacker) override;
    


    friend std::ostream &operator<<(std::ostream &os, Vip &Vip);
};

#endif