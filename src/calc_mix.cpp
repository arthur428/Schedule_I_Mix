#include "calc_mix.hpp"

// Replace effect in effects vector with another effect based on the mixer used
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
        // If the effect will be affected by the mixer...
        if (auto it_replace = mixer.affected_effects.find(it->name); it_replace != mixer.affected_effects.end())
        {
            // If there is a duplicate to the left...
            if (auto it_left = std::find(effects.begin(), it, G_MAP_EFFECTS.at(it_replace->second)); it_left != it)
            {
                // Do not replace
            }
            // But if there is a duplicate to the right...
            else if (auto it_right = std::find(it + 1, effects.end(), G_MAP_EFFECTS.at(it_replace->second)); it_right != effects.end())
            {
                *it = G_MAP_EFFECTS.at(it_replace->second);
            }
            else
            {
                *it = G_MAP_EFFECTS.at(it_replace->second);
            }
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

        // Update counter
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
