#include "calc_mix.hpp"

#include <iostream>
#include <sstream>

static bool desired_effects_present(const std::vector<Effect> &effs, const std::vector<Effect> &desired_effs)
{
    bool b_all_present = false;
    std::vector<uint8_t> eff_ids;
    std::vector<int> desired_eff_ids;

    // Get and sort effect IDs
    eff_ids.reserve(effs.size());
    for (auto it = effs.begin(); it != effs.end(); it++) { eff_ids.push_back(static_cast<uint8_t>(it->id)); }
    std::sort(eff_ids.begin(), eff_ids.end());

    // Get and sort desired effect IDs
    desired_eff_ids.reserve(desired_eff_ids.size());
    for (auto it = desired_effs.begin(); it != desired_effs.end(); it++) { desired_eff_ids.push_back(static_cast<uint8_t>(it->id)); }
    std::sort(desired_eff_ids.begin(), desired_eff_ids.end());

    // Check if desired effect vector is a subset of effect vector
    b_all_present = std::includes(eff_ids.begin(), eff_ids.end(), desired_eff_ids.begin(), desired_eff_ids.end());

    return b_all_present;
}

// Replace effect in effects vector with another effect based on the mixer used
Product mix(const Product &product, const mixer_enum_t &mixer_enum)
{
    //std::cout << "[MIX]" << '\n';
    std::vector<Effect> effects = product.effects();
    std::vector<Mixer> mixers = product.mixers();
    Mixer mixer = G_VECTOR_MIXERS.at(static_cast<int>(mixer_enum));

    // Add the mixer to the mixer history
    mixers.push_back(mixer);

    // New Mix Logic
    // Iterate through each effect in effect list
    // First element = oldest effect transformed
    // Last element = effect added by the mixer
    Effect old_effect;
    for (auto it = effects.begin(); it != effects.end(); it++)
    {
        old_effect = *it;
        // If the effect will be affected by the mixer...
        if (auto it_replace = mixer.affected_effects.find(it->id); it_replace != mixer.affected_effects.end())
        {
            // If there is a duplicate to the left...
            if (auto it_left = std::find(effects.begin(), it, G_VECTOR_EFFECTS[static_cast<int>(it_replace->second)]); it_left != it)
            {
                // Do not replace
            }
            // But if there is a duplicate to the right...
            else if (auto it_right = std::find(it + 1, effects.end(), G_VECTOR_EFFECTS[static_cast<int>(it_replace->second)]); it_right != effects.end())
            {
                *it = G_VECTOR_EFFECTS[static_cast<int>(it_replace->second)];
            }
            else
            {
                *it = G_VECTOR_EFFECTS[static_cast<int>(it_replace->second)];
            }
        }

        // If the final effect was replaced, duplicated to the right, AND not affected by the current mixer
        if ((*it != old_effect) &&
            (std::find(it + 1, effects.end(), *it) != effects.end()) &&
            (mixer.affected_effects.find(it->id) == mixer.affected_effects.end()))
        {
            // Revert the change
            *it = old_effect;
        }
    }

    // Add the mixer's effect if there is still space and if non-existent
    if ((effects.size() < MAX_NUM_EFFECTS) && 
        (std::find(effects.begin(), effects.end(), G_VECTOR_MIXERS.at(static_cast<int>(mixer_enum)).effect) == effects.end())) {
        effects.push_back(G_VECTOR_MIXERS.at(static_cast<int>(mixer_enum)).effect);
    }

    return Product(product.base(), effects, mixers);
}

// Simulate mix until n_mixes and find the most profitable mix.
Product find_most_profitable_mix(const Product &base_product, const int &n_mixers, const mixer_enum_t &last_unlocked_mixer, const std::vector<Effect> &desired_effs)
{
    if (static_cast<unsigned int>(n_mixers) < desired_effs.size() - 1)
    {
        std::cerr << "n_mixers must be >= size of desired effects vector - 1." << '\n';
        return base_product;
    }

    // For checking most profitable mix
    Product product;
    Product old;
    Product temp;
    Product most_profitable_product;
    bool found_product_with_desired_effects = false;
    double profit_batch = 0;
    auto mixer_selection = std::vector<uint8_t>(static_cast<int>(0, n_mixers));

    // For selection logic
    auto it_lsb = mixer_selection.begin();
    bool increment_digit = false;
    uint64_t ctr = 0;
    uint64_t ctr_limit = static_cast<uint64_t>(pow((static_cast<double>(last_unlocked_mixer) + 1.0), static_cast<double>(n_mixers)));
    std::cout << "ctr_limit: " << ctr_limit << '\n';

    while (true) {
        product = base_product;

        // Mix each item
        for (auto mixer = mixer_selection.begin(); mixer != mixer_selection.end(); mixer++) {
            old = product;
            temp = mix(product, static_cast<mixer_enum_t>(*mixer));
            if (temp.effects() == old.effects()) { break; }
            else { product = std::move(temp); };
        }

        // Update most profitable record
        if (product.profit_batch() > profit_batch) {
            // Only if the desired effects are present
            if (desired_effects_present(product.effects(), desired_effs))
            {
                profit_batch = product.profit_batch();
                most_profitable_product = product;
                found_product_with_desired_effects = true;
            }
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
        if (ctr >= ctr_limit) { break; }

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

    // If no product with desired effects found, not even one...
    if (!found_product_with_desired_effects)
    {
        std::cerr << "Impossible to get desired effects with current settings!" << '\n';
        most_profitable_product = base_product;
    }

    return most_profitable_product;
}
