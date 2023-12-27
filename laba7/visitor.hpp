#pragma once
#include "npc.hpp"
#include "vip.hpp"
#include "muskrat.hpp"
#include "bear.hpp"

class Visitor {
public:
    virtual bool visit(const std::shared_ptr<NPC>&) const = 0;
};

class BearVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::BearType:
                result = false;
                break;

            case NpcType::MuskratType:
                result = true;
                break;
            
            case NpcType::VipType:
                result = true;
                break;
        }
        return result;
    }
};

class MuskratVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::BearType:
                result = false;
                break;

            case NpcType::MuskratType:
                result = false;
                break;
            
            case NpcType::VipType:
                result = true;
                break;
        }
        return result;
    }
};

class VipVisitor final : public Visitor {
public:
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::BearType:
                result = false;
                break;

            case NpcType::MuskratType:
                result = false;
                break;
            
            case NpcType::VipType:
                result = false;
                break;
        }
        return result;
    }
};

class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
        std::shared_ptr<Visitor> result;
        switch (type) {
            case NpcType::VipType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<VipVisitor>());
                break;

            case NpcType::MuskratType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<MuskratVisitor>());
                break;

            case NpcType::BearType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<BearVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};