#include "calc_mix.hpp"

// sources
// https://www.ign.com/wikis/schedule-1/Schedule_1_Mixing_Guide
// https://hardcoregamer.com/schedule-1-every-ingredient-effects/
// Replace effect in effects vector with another effect based on the mixer used
void replace_effect(std::vector<Effect> & effects, const mixer_enum_t & mixer_enum, const Effect & affected_effect)
{
    //std::cout << "[REPLACE_EFFECT]" << '\n';
    std::string eff_name = affected_effect.name;
    eff_name[0] = tolower(eff_name[0]);

    switch(mixer_enum)
    {
    case (mixer_enum_t::cuke):
        if (eff_name == "euphoric") { find_replace_effect(effects, eff_name, "laxative"); }
        else if (eff_name == "foggy") { find_replace_effect(effects, eff_name, "cyclopean"); }
        else if (eff_name == "gingeritis") { find_replace_effect(effects, eff_name, "thoughtprovoking"); }
        else if (eff_name == "munchies") { find_replace_effect(effects, eff_name, "athletic"); }
        else if (eff_name == "slippery") { find_replace_effect(effects, eff_name, "munchies");}
        else if (eff_name == "sneaky") { find_replace_effect(effects, eff_name, "paranoia"); }
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "euphoric");}
        break;
    
    case (mixer_enum_t::banana):    
        if (eff_name == "calming") { find_replace_effect(effects, eff_name, "sneaky"); }
        else if (eff_name == "cyclopean") { find_replace_effect(effects, eff_name, "energizing"); }
        else if (eff_name == "disorienting") { find_replace_effect(effects, eff_name, "focused"); }
        else if (eff_name == "energizing") { find_replace_effect(effects, eff_name, "thoughtprovoking"); }
        else if (eff_name == "focused") { find_replace_effect(effects, eff_name, "seizureinducing"); }
        else if (eff_name == "longfaced") { find_replace_effect(effects, eff_name, "refreshing"); }
        else if (eff_name == "paranoia") { find_replace_effect(effects, eff_name, "jennerising"); }
        else if (eff_name == "smelly") {find_replace_effect(effects, eff_name, "antigravity");}
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "smelly");}
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
        else if (eff_name == "energizing") { find_replace_effect(effects, eff_name, "paranoia"); }
        break;

    case (mixer_enum_t::donut):
        if (eff_name == "antigravity") { find_replace_effect(effects, eff_name, "slippery"); }
        else if (eff_name == "balding") { find_replace_effect(effects, eff_name, "sneaky"); }
        else if (eff_name == "caloriedense") { find_replace_effect(effects, eff_name, "explosive"); }
        else if (eff_name == "focused") { find_replace_effect(effects, eff_name, "euphoric"); }
        else if (eff_name == "jennerising") { find_replace_effect(effects, eff_name, "gingeritis"); }
        else if (eff_name == "munchies") { find_replace_effect(effects, eff_name, "calming"); }
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "energizing");}
        break;

    case (mixer_enum_t::viagra):
        if (eff_name == "athletic") { find_replace_effect(effects, eff_name, "sneaky"); }
        else if (eff_name == "disorienting") { find_replace_effect(effects, eff_name, "toxic"); }
        else if (eff_name == "euphoric") {find_replace_effect(effects, eff_name, "brighteyed");}
        else if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "shrinking") { find_replace_effect(effects, eff_name, "gingeritis"); }
        break;

    case (mixer_enum_t::mouthwash):
        if (eff_name == "calming") {find_replace_effect(effects, eff_name, "antigravity");}
        else if (eff_name == "caloriedense") { find_replace_effect(effects, eff_name, "sneaky"); }
        else if (eff_name == "explosive") { find_replace_effect(effects, eff_name, "sedating"); }
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "jennerising");}
        break;

    case (mixer_enum_t::flumedicine):
        if (eff_name == "athletic") { find_replace_effect(effects, eff_name, "munchies"); }
        else if (eff_name == "calming") {find_replace_effect(effects, eff_name, "brighteyed");}
        else if (eff_name == "cyclopean") { find_replace_effect(effects, eff_name, "foggy"); }
        else if (eff_name == "electrifying") { find_replace_effect(effects, eff_name, "refreshing"); }
        else if (eff_name == "euphoric") { find_replace_effect(effects, eff_name, "toxic"); }
        else if (eff_name == "focused") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "munchies") { find_replace_effect(effects, eff_name, "slippery"); }
        else if (eff_name == "shrinking") { find_replace_effect(effects, eff_name, "paranoia"); }
        else if (eff_name == "thoughtprovoking") {find_replace_effect(effects, eff_name, "gingeritis");}
        break;

    case (mixer_enum_t::gasoline):
        if (eff_name == "disorienting") { find_replace_effect(effects, eff_name, "glowing"); }
        else if (eff_name == "electrifying") { find_replace_effect(effects, eff_name, "disorienting"); }
        else if (eff_name == "energizing") { find_replace_effect(effects, eff_name, "euphoric"); }
        else if (eff_name == "euphoric") { find_replace_effect(effects, eff_name, "spicy"); }
        else if (eff_name == "gingeritis") { find_replace_effect(effects, eff_name, "smelly"); }
        else if (eff_name == "jennerising") { find_replace_effect(effects, eff_name, "sneaky"); }
        else if (eff_name == "laxative") { find_replace_effect(effects, eff_name, "foggy"); }
        else if (eff_name == "munchies") { find_replace_effect(effects, eff_name, "sedating"); }
        else if (eff_name == "paranoia") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "focused");}
        else if (eff_name == "sneaky") { find_replace_effect(effects, eff_name, "tropicthunder"); }
        break;

    case (mixer_enum_t::energydrink):
        if (eff_name == "disorienting") { find_replace_effect(effects, eff_name, "electrifying"); }
        else if (eff_name == "euphoric") { find_replace_effect(effects, eff_name, "energizing"); }
        else if (eff_name == "focused") { find_replace_effect(effects, eff_name, "shrinking"); }
        else if (eff_name == "foggy") { find_replace_effect(effects, eff_name, "laxative"); }
        else if (eff_name == "glowing") { find_replace_effect(effects, eff_name, "disorienting"); }
        else if (eff_name == "schizophrenia") {find_replace_effect(effects, eff_name, "balding");}
        else if (eff_name == "sedating") { find_replace_effect(effects, eff_name, "munchies"); }
        else if (eff_name == "spicy") {find_replace_effect(effects, eff_name, "euphoric");}
        else if (eff_name == "tropicthunder") {find_replace_effect(effects, eff_name, "sneaky");}
        break;

    case (mixer_enum_t::motoroil):
        if (eff_name == "energizing") { find_replace_effect(effects, eff_name, "munchies"); }
        else if (eff_name == "euphoric") { find_replace_effect(effects, eff_name, "sedating"); }
        else if (eff_name == "foggy") { find_replace_effect(effects, eff_name, "toxic"); }
        else if (eff_name == "munchies") { find_replace_effect(effects, eff_name, "schizophrenia"); }
        else if (eff_name == "paranoia") {find_replace_effect(effects, eff_name, "antigravity");}
        break;
    
    case (mixer_enum_t::megabean):
        if (eff_name == "athletic") { find_replace_effect(effects, eff_name, "laxative"); }
        else if (eff_name == "calming") { find_replace_effect(effects, eff_name, "glowing"); }
        else if (eff_name == "energizing") { find_replace_effect(effects, eff_name, "cyclopean"); }
        else if (eff_name == "focused") { find_replace_effect(effects, eff_name, "disorienting"); }
        else if (eff_name == "jennerising") { find_replace_effect(effects, eff_name, "paranoia"); }
        else if (eff_name == "seizureinducing") { find_replace_effect(effects, eff_name, "focused"); }
        else if (eff_name == "shrinking") { find_replace_effect(effects, eff_name, "electrifying"); }
        else if (eff_name == "slippery") { find_replace_effect(effects, eff_name, "toxic"); }
        else if (eff_name == "sneaky") { find_replace_effect(effects, eff_name, "calming"); }
        else if (eff_name == "thoughtprovoking") { find_replace_effect(effects, eff_name, "energizing"); }
        break;

    case (mixer_enum_t::chili):
        if (eff_name == "antigravity") { find_replace_effect(effects, eff_name, "tropicthunder"); }
        else if (eff_name == "athletic") { find_replace_effect(effects, eff_name, "euphoric"); }
        else if (eff_name == "laxative") { find_replace_effect(effects, eff_name, "longfaced"); }
        else if (eff_name == "munchies") { find_replace_effect(effects, eff_name, "toxic"); }
        else if (eff_name == "shrinking") { find_replace_effect(effects, eff_name, "refreshing"); }
        else if (eff_name == "sneaky") {find_replace_effect(effects, eff_name, "brighteyed");}
        else if (eff_name == "thoughtprovoking") { find_replace_effect(effects, eff_name, "focused"); }
        break;

    case (mixer_enum_t::battery):
        if (eff_name == "cyclopean") { find_replace_effect(effects, eff_name, "glowing"); }
        else if (eff_name == "electrifying") { find_replace_effect(effects, eff_name, "euphoric"); }
        else if (eff_name == "euphoric") { find_replace_effect(effects, eff_name, "zombifying"); }
        else if (eff_name == "laxative") {find_replace_effect(effects, eff_name, "caloriedense");}
        else if (eff_name == "munchies") { find_replace_effect(effects, eff_name, "tropicthunder"); }
        else if (eff_name == "shrinking") {find_replace_effect(effects, eff_name, "munchies");}
        break;
    
    case (mixer_enum_t::iodine):
        /*if (eff_name == "calming") { find_replace_effect(effects, eff_name, "sedating"); }*/
        if (eff_name == "calming") { find_replace_effect(effects, eff_name, "balding"); }
        else if (eff_name == "caloriedense") {find_replace_effect(effects, eff_name, "gingeritis");}
        else if (eff_name == "euphoric") { find_replace_effect(effects, eff_name, "seizureinducing"); }
        else if (eff_name == "foggy") {find_replace_effect(effects, eff_name, "paranoia");}
        else if (eff_name == "refreshing") { find_replace_effect(effects, eff_name, "thoughtprovoking"); }
        else if (eff_name == "toxic") {find_replace_effect(effects, eff_name, "sneaky");}
        break;

    case (mixer_enum_t::addy):
        if (eff_name == "explosive") { find_replace_effect(effects, eff_name, "euphoric"); }
        else if (eff_name == "foggy") { find_replace_effect(effects, eff_name, "energizing"); }
        else if (eff_name == "glowing") { find_replace_effect(effects, eff_name, "refreshing"); }
        else if (eff_name == "longfaced") {find_replace_effect(effects, eff_name, "electrifying");}
        else if (eff_name == "sedating") {find_replace_effect(effects, eff_name, "gingeritis");}
        break;

    case (mixer_enum_t::horsesemen):
        if (eff_name == "antigravity") {find_replace_effect(effects, eff_name, "calming");}
        else if (eff_name == "gingeritis") { find_replace_effect(effects, eff_name, "refreshing"); }
        else if (eff_name == "seizureinducing") { find_replace_effect(effects, eff_name, "energizing"); }
        else if (eff_name == "thoughtprovoking") {find_replace_effect(effects, eff_name, "electrifying");}
        break;
    
    default:
        throw;
    }
}

std::vector<Effect>::iterator find_replace_effect(std::vector<Effect> & vec, std::string mixer_eff, std::string mixer_replace)
{
    //std::cout << "[FIND_REPLACE_EFFECT]" << '\n';
    auto it = std::find(vec.begin(), vec.end(), G_MAP_EFFECTS.at(mixer_eff));
    if (it != vec.end()) {
        // Do the replacement if effect to replace is present
        *it = G_MAP_EFFECTS.at(mixer_replace);
    }

    // TODO: Make mixer affected effects into a map of string string
    // where the first string is the affected effect
    // and the second string is the replacement effect
    it = std::find(it + 1, vec.end(), G_MAP_EFFECTS.at(mixer_replace));

    return it;
}

Product mix(const Product &product, const mixer_enum_t &mixer_enum)
{
    //std::cout << "[MIX]" << '\n';
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

    // Add the mixer's effect if there is still space and if non-existent
    if ((effects.size() < MAX_NUM_EFFECTS) && 
        (std::find(effects.begin(), effects.end(), G_MAP_MIXERS.at(static_cast<int>(mixer_enum)).effect) == effects.end())) {
        effects.push_back(G_MAP_MIXERS.at(static_cast<int>(mixer_enum)).effect);
    }

    return Product(product.base(), effects, mixers);
}

// Simulate mix until n_mixes and find the most profitable mix.
Product find_most_profitable_mix(const Product::base_product_t& base, int n_mixers, mixer_enum_t last_unlocked_mixer)
{
    auto product = Product(base);
    auto most_profitable_product = Product(base);
    auto old = Product(base);
    double profit_batch = 0;
    auto mixer_selection = std::vector<uint8_t>(static_cast<int>(0, n_mixers));

    auto it_lsb = mixer_selection.begin();
    bool increment_digit = false;
    uint64_t ctr = 0;
    uint64_t ctr_limit = static_cast<uint64_t>(pow((static_cast<double>(last_unlocked_mixer) + 1.0), static_cast<double>(n_mixers)));
    std::cout << "ctr_limit: " << ctr_limit << '\n';

    while (true) {
        product = Product(base);

        // Mix each item
        for (auto mixer = mixer_selection.begin(); mixer != mixer_selection.end(); mixer++) {
            old = product;
            Product temp = mix(product, static_cast<mixer_enum_t>(*mixer));
            // std::cout << "Mixed with mixer: " << static_cast<int>(*mixer) << '\n';
            if (temp.effects() == old.effects()) { break; }
            else { product = temp; };
        }

        // Update most profitable record
        if (product.profit_batch() > profit_batch) {
            profit_batch = product.profit_batch();
            most_profitable_product = product;
        }

        // Debug Log
        std::ostringstream text;
        for (auto it = mixer_selection.begin(); it != mixer_selection.end(); it++)
        {
            text << std::to_string(*it);
            if (it != (mixer_selection.end() - 1)) {
                text << ", ";
            }
        }
        std::cout << text.str() << '\n';

        ctr++;
        if (ctr >= ctr_limit) {
            break;
        }

        // Update selection logic
        (*it_lsb)++;
        if (*it_lsb > static_cast<int>(last_unlocked_mixer)) {
            increment_digit = true;
            while (increment_digit) {
                *it_lsb = 0;
                it_lsb++;
                (*it_lsb)++;
                if (*it_lsb > static_cast<int>(last_unlocked_mixer)) { continue; }
                else { increment_digit = false; }
            }
            it_lsb = mixer_selection.begin();
        }
    }

    return most_profitable_product;
}
