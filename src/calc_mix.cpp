#include "calc_mix.hpp"

// sources
// https://www.ign.com/wikis/schedule-1/Schedule_1_Mixing_Guide
// https://hardcoregamer.com/schedule-1-every-ingredient-effects/
// Product mix(const Product & product, const Mixer & mixer)
// {
//     Product result;
//     std::vector<Effect> effects = product.effects();
//     std::vector<Mixer> mixers = product.mixers();

//     // Mix logic
//     std::string mixer_name = mixer.effect.name;
//     if (G_MAP_MIXERS.at(static_cast<int>(mixer_enum_t::cuke)).name == mixer_name)

// }

// Replace effect in effects vector with another effect based on the mixer used
void replace_effect(std::vector<Effect> & effects, const mixer_enum_t & mixer_enum, const Effect & affected_effect)
{
    std::cout << "[REPLACE_EFFECT]" << '\n';
    std::string eff_name = affected_effect.name;
    eff_name[0] = tolower(eff_name[0]);

    switch(mixer_enum)
    {
    case (mixer_enum_t::cuke):
        if (eff_name == "munchies") {find_replace_effect(effects, eff_name, "athletic");}
        else if (eff_name == "foggy") {find_replace_effect(effects, eff_name, "cyclopean");}
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "euphoric") {find_replace_effect(effects, eff_name, "laxative");}
        else if (eff_name == "slippery") {find_replace_effect(effects, eff_name, "munchies");}
        else if (eff_name == "sneaky") {find_replace_effect(effects, eff_name, "paranoia");}
        else if (eff_name == "gingeritis") {find_replace_effect(effects, eff_name, "thoughtprovoking");}
        else if (eff_name == "slippery") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("munchies")) != effects.end()) {
                // Replace Slippery with Athletic only if Munchies is also present
                find_replace_effect(effects, eff_name, "athletic");
            }
        }
        break;
    
    case (mixer_enum_t::banana):
        if (eff_name == "smelly") {find_replace_effect(effects, eff_name, "antigravity");}
        else if (eff_name == "disorienting") {find_replace_effect(effects, eff_name, "focused");}
        else if (eff_name == "paranoia") {find_replace_effect(effects, eff_name, "jennerising");}
        else if (eff_name == "longfaced") {find_replace_effect(effects, eff_name, "refreshing");}
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "seizureinducing");}
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "smelly");}
        else if (eff_name == "calming") {find_replace_effect(effects, eff_name, "sneaky");}
        else if (eff_name == "cyclopean") {find_replace_effect(effects, eff_name, "thoughtprovoking");}
        else if (eff_name == "energizing") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("cyclopean")) == effects.end()) {
                // Replace Energizing with Thought-Provoking only if Cyclopean is NOT present
                find_replace_effect(effects, eff_name, "thoughtprovoking");
            }
        }
        break;

    case (mixer_enum_t::paracetamol):
        if (eff_name == "munchies") {find_replace_effect(effects, eff_name, "antigravity");}
        else if (eff_name == "electrifying") {find_replace_effect(effects, eff_name, "athletic");}
        else if (eff_name == "paranoia") {find_replace_effect(effects, eff_name, "balding");}
        else if (eff_name == "spicy") {find_replace_effect(effects, eff_name, "brighteyed");}
        else if (eff_name == "foggy") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "gingeritis");}
        else if (eff_name == "calming") {find_replace_effect(effects, eff_name, "slippery");}
        else if (eff_name == "glowing") {find_replace_effect(effects, eff_name, "toxic");}
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "tropicthunder");}
        else if (eff_name == "energizing") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("paranoia")) == effects.end()) {
                // Replace Energizing with Balding only if Paranoia is NOT present
                find_replace_effect(effects, eff_name, "balding");
            } else if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("munchies")) == effects.end()) {
                // Replace Energizing with Paranoia only if Munchies is NOT present
                find_replace_effect(effects, eff_name, "paranoia");
            }
        }
        break;

    case (mixer_enum_t::donut):
        if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "energizing");}
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "jennerising") {find_replace_effect(effects, eff_name, "gingeritis");}
        else if (eff_name == "antigravity") {find_replace_effect(effects, eff_name, "slippery");}
        else if (eff_name == "balding") {find_replace_effect(effects, eff_name, "sneaky");}
        else if (eff_name == "caloriedense") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("explosive")) == effects.end()) {
                // Replace Calorie-Dense with Explosive only if Explosive is NOT present
                find_replace_effect(effects, eff_name, "explosive");
            }
        }
        break;

    case (mixer_enum_t::viagra):
        if (eff_name == "euphoric") {find_replace_effect(effects, eff_name, "brighteyed");}
        else if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "athletic") {find_replace_effect(effects, eff_name, "sneaky");}
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "disorienting");}
        break;

    case (mixer_enum_t::mouthwash):
        if (eff_name == "calming") {find_replace_effect(effects, eff_name, "antigravity");}
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "jennerising");}
        else if (eff_name == "explosive") {find_replace_effect(effects, eff_name, "sedating");}
        else if (eff_name == "caloriedense") {find_replace_effect(effects, eff_name, "sneaky");}
        break;

    case (mixer_enum_t::flumedicine):
        if (eff_name == "calming") {find_replace_effect(effects, eff_name, "brighteyed");}
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "cyclopean") {find_replace_effect(effects, eff_name, "foggy");}
        else if (eff_name == "thoughtprovoking") {find_replace_effect(effects, eff_name, "gingeritis");}
        else if (eff_name == "athletic") {find_replace_effect(effects, eff_name, "munchies");}
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "paranoia");}
        else if (eff_name == "electrifying") {find_replace_effect(effects, eff_name, "refreshing");}
        else if (eff_name == "munchies") {find_replace_effect(effects, eff_name, "slippery");}
        else if (eff_name == "euphoric") {find_replace_effect(effects, eff_name, "toxic");}
        break;

    case (mixer_enum_t::gasoline):
        if (eff_name == "paranoia") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "electrifying") {find_replace_effect(effects, eff_name, "disorienting");}
        else if (eff_name == "energizing") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "focused");}
        else if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "foggy");}
        else if (eff_name == "disorienting") {find_replace_effect(effects, eff_name, "glowing");}
        else if (eff_name == "munchies") {find_replace_effect(effects, eff_name, "sedating");}
        else if (eff_name == "gingeritis") {find_replace_effect(effects, eff_name, "smelly");}
        else if (eff_name == "jennerising") {find_replace_effect(effects, eff_name, "sneaky");}
        else if (eff_name == "energizing") {find_replace_effect(effects, eff_name, "spicy");}
        else if (eff_name == "sneaky") {find_replace_effect(effects, eff_name, "tropicthunder");}
        else if (eff_name == "euphoric") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("energizing")) == effects.end()) {
                // Replace Euphoric with Spicy only if Energizing is NOT present
                find_replace_effect(effects, eff_name, "spicy");
            }
        }
        break;

    case (mixer_enum_t::energydrink):
        if (eff_name == "schizophrenia") {find_replace_effect(effects, eff_name, "balding");}
        else if (eff_name == "glowing") {find_replace_effect(effects, eff_name, "disorienting");}
        else if (eff_name == "disorienting") {find_replace_effect(effects, eff_name, "electrifying");}
        else if (eff_name == "euphoric") {find_replace_effect(effects, eff_name, "energizing");}
        else if (eff_name == "spicy") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "foggy") {find_replace_effect(effects, eff_name, "laxative");}
        else if (eff_name == "sedating") {find_replace_effect(effects, eff_name, "munchies");}
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "shrinking");}
        else if (eff_name == "tropicthunder") {find_replace_effect(effects, eff_name, "sneaky");}
        break;

    case (mixer_enum_t::motoroil):
        if (eff_name == "paranoia") {find_replace_effect(effects, eff_name, "antigravity");}
        else if (eff_name == "energizing") {find_replace_effect(effects, eff_name, "munchies");}
        // else if (eff_name == "energizing") {find_replace_effect(effects, eff_name, "schizophrenia");}  // IGN error?
        else if (eff_name == "euphoric") {find_replace_effect(effects, eff_name, "sedating");}
        else if (eff_name == "foggy") {find_replace_effect(effects, eff_name, "toxic");}
        else if (eff_name == "munchies") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("energizing")) == effects.end()) {
                // Replace Munchies with Schizophrenia only if Energizing is NOT present
                find_replace_effect(effects, eff_name, "schizophrenia");
            }
        }
        break;
    
    case (mixer_enum_t::megabean):
        if (eff_name == "sneaky") {find_replace_effect(effects, eff_name, "calming");}
        // else if (eff_name == "thoughtprovoking") {find_replace_effect(effects, eff_name, "cyclopean");}  // IGN Error?
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "disorienting");}
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "electrifying");}
        else if (eff_name == "thoughtprovoking") {find_replace_effect(effects, eff_name, "energizing");}
        else if (eff_name == "seizureinducing") {find_replace_effect(effects, eff_name, "focused");}
        else if (eff_name == "calming") {find_replace_effect(effects, eff_name, "glowing");}
        else if (eff_name == "sneaky") {find_replace_effect(effects, eff_name, "glowing");}
        else if (eff_name == "athletic") {find_replace_effect(effects, eff_name, "laxative");}
        else if (eff_name == "jennerising") {find_replace_effect(effects, eff_name, "paranoia");}
        else if (eff_name == "slippery") {find_replace_effect(effects, eff_name, "toxic");}
        else if (eff_name == "energizing") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("thoughtprovoking")) == effects.end()) {
                // Replace Energizing with Cyclopean only if Thought-Provoking is NOT present
                find_replace_effect(effects, eff_name, "cyclopean");
            }
        }
        break;

    case (mixer_enum_t::chili):
        if (eff_name == "sneaky") {find_replace_effect(effects, eff_name, "brighteyed");}
        else if (eff_name == "athletic") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "longfaced");}
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "refreshing");}
        else if (eff_name == "munchies") {find_replace_effect(effects, eff_name, "toxic");}
        else if (eff_name == "antigravity") {find_replace_effect(effects, eff_name, "tropicthunder");}
        break;

    case (mixer_enum_t::battery):
        if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "caloriedense");}
        else if (eff_name == "cyclopean") {find_replace_effect(effects, eff_name, "glowing");}
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "munchies");}
        else if (eff_name == "munchies") {find_replace_effect(effects, eff_name, "tropicthunder");}
        else if (eff_name == "electrifying") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("zombifying")) == effects.end()) {
                // Replace Electrifying with Euphoric only if Zombifying is NOT present
                find_replace_effect(effects, eff_name, "euphoric");
            }
        }
        else if (eff_name == "euphoric") {
            if (std::find(effects.begin(), effects.end(), G_MAP_EFFECTS.at("electrifying")) == effects.end()) {
                // Replace Euphoric with Zombifying only if Electrifying is NOT present
                find_replace_effect(effects, eff_name, "zombifying");
            }
        }
        break;
    
    case (mixer_enum_t::iodine):
        if (eff_name == "caloriedense") {find_replace_effect(effects, eff_name, "gingeritis");}
        else if (eff_name == "foggy") {find_replace_effect(effects, eff_name, "paranoia");}
        else if (eff_name == "calming") {find_replace_effect(effects, eff_name, "sedating");}
        else if (eff_name == "euphoric") {find_replace_effect(effects, eff_name, "seizureinducing");}
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "sneaky");}
        else if (eff_name == "refreshing") {find_replace_effect(effects, eff_name, "thoughtprovoking");}
        break;

    case (mixer_enum_t::addy):
        if (eff_name == "longfaced") {find_replace_effect(effects, eff_name, "electrifying");}
        else if (eff_name == "foggy") {find_replace_effect(effects, eff_name, "energizing");}
        else if (eff_name == "explosive") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "sedating") {find_replace_effect(effects, eff_name, "gingeritis");}
        else if (eff_name == "glowing") {find_replace_effect(effects, eff_name, "refreshing");}
        break;

    case (mixer_enum_t::horsesemen):
        if (eff_name == "antigravity") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "thoughtprovoking") {find_replace_effect(effects, eff_name, "electrifying");}
        else if (eff_name == "gingeritis") {find_replace_effect(effects, eff_name, "refreshing");}
        break;
    
    default:
        throw;
    }
}

void find_replace_effect(std::vector<Effect> & vec, std::string mixer_eff, std::string mixer_replace)
{
    std::cout << "[FIND_REPLACE_EFFECT]" << '\n';
    auto it = std::find(vec.begin(), vec.end(), G_MAP_EFFECTS.at(mixer_eff));
    if (it != vec.end()) {
        *it = G_MAP_EFFECTS.at(mixer_replace);
    }
}

Product mix(const Product &product, const mixer_enum_t &mixer_enum)
{
    std::cout << "[MIX]" << '\n';
    std::vector<Effect> effects = product.effects();
    std::vector<Mixer> mixers = product.mixers();
    Mixer mixer = G_MAP_MIXERS.at(static_cast<int>(mixer_enum));

    // Add the mixer to the mixer history
    mixers.push_back(mixer);

    // New Mix Logic
    // Iterate through each effect in effect list
    // First element = oldest effect transformed
    // Last element = effect added by the mixer
    for (auto it = effects.begin(); it != effects.end(); it++)
    {
        std::string buh = it->name;
        buh[0] = tolower(buh[0]);

        // If the effect will be affected by the mixer...
        if (std::find(mixer.affected_effects.begin(), mixer.affected_effects.end(), buh) != mixer.affected_effects.end())
        {
            // Replace the effect
            replace_effect(effects, mixer_enum, *it);
        }
    }

    // Add the mixer's effect if there is still space
    if (effects.size() < MAX_NUM_EFFECTS) {
        effects.push_back(G_MAP_MIXERS.at(static_cast<int>(mixer_enum)).effect);
    }

    return Product(product.base(), effects, mixers);
}
