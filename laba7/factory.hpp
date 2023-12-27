#pragma once
#include "npc.hpp"
#include "vip.hpp"
#include "muskrat.hpp"
#include "bear.hpp"
#include "observer.hpp"

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const NpcType& type, int x, int y) {
        std::shared_ptr<NPC> result;
        if (type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::BearType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Bear>(x, y));
                    break;

                case NpcType::MuskratType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Muskrat>(x, y));
                    break;

                case NpcType::VipType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Vip>(x, y));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> CreateNPC(std::istream& is) {
        std::shared_ptr<NPC> result;
        int type{0};
        if (is >> type && type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::BearType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Bear>(is));
                    break;

                case NpcType::MuskratType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Muskrat>(is));
                    break;

                case NpcType::VipType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Vip>(is));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }
        
        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};