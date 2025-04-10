#include "product.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

// Base product constructor
Product::Product(const base_product_t & base)
:   sell_price_unit_{0},
    sell_price_batch_{0},
    cost_batch_{0}
{
    // Initialize variables based on base product
    base_ = base;
    switch(base)
    {
        case(base_product_t::OG_KUSH):
            effects_.push_back(G_MAP_EFFECTS.at("calming"));    
            cost_seed_ = COST_SEED_OG_KUSH;
            base_price_ = BASE_PRICE_WEED;
            break;
        
        case(base_product_t::SOUR_DIESEL):
            effects_.push_back(G_MAP_EFFECTS.at("refreshing"));
            cost_seed_ = COST_SEED_SOUR_DIESEL;
            base_price_ = BASE_PRICE_WEED;
            break;

        case(base_product_t::GREEN_CRACK):
            effects_.push_back(G_MAP_EFFECTS.at("energizing"));
            cost_seed_ = COST_SEED_GREEN_CRACK;
            base_price_ = BASE_PRICE_WEED;
            break;

        case(base_product_t::G_PURPLE):
            effects_.push_back(G_MAP_EFFECTS.at("sedating"));
            cost_seed_ = COST_SEED_G_PURPLE;
            base_price_ = BASE_PRICE_WEED;
            break;

        case(base_product_t::CUSTOM):
            cost_seed_ = 0;
            base_price_ = 0;
            break;

        default:
            throw;
    }

    mixers_ = {};
}

// Non-base product constructor
// Ignores effect of base product
Product::Product(const base_product_t & base, const std::vector<Effect> & effects, const std::vector<Mixer> & mixers)
:   Product(base)
{
    effects_ = effects;     // Ignores effect of base product
    mixers_ = mixers;
}

// Calculate total cost to make product (seed + mixers)
double Product::cost_batch()
{
    double cost = cost_seed_;

    // Add seed cost and cost of all mixers.
    // Assuming all produce are going to be used in the mix.
    for (const Mixer & m : mixers_) {
        cost += (m.cost * 8);
    }
    cost_batch_ = cost;

    return cost_batch_;
}

// Calculate selling price of product per unit
double Product::sell_price_unit()
{
    double sell_price = 0;
    double sum_mult = 0;

    // Get sum of effect multipliers
    for (const Effect & e : effects_) {
        sum_mult += e.multiplier;
    }

    // Calculate selling price
    sell_price = base_price_ * (1 + sum_mult);
    sell_price_unit_ = floor(sell_price);

    return sell_price_unit_;
}

// Calculate selling price of product per batch
double Product::sell_price_batch()
{
    if (sell_price_unit_ <= 0) {
        sell_price_unit();
    }
    sell_price_batch_ = sell_price_unit_ * 8;

    return sell_price_batch_;
}

// Calculate profit from selling a batch of the product without mark-up
double Product::profit_batch()
{
    if (sell_price_batch_ <= 0) {
        sell_price_batch();
    }

    if (cost_batch_ <= 0) {
        cost_batch();
    }

    return sell_price_batch_ - cost_batch_;
}

Product::base_product_t Product::base() const
{
    return base_;
}

// Print and return the product's effects
std::vector<Effect> Product::effects(bool b_print_effects) const
{
    std::ostringstream text;
    Effect temp_effect;

    // Print each effect in effects_
    if (b_print_effects) {
        text << "Effects: ";
        for (auto it = effects_.begin(); it != effects_.end(); it++)
        {
            text << it->name;
            if (it != (effects_.end() - 1)) {
                text << ", ";
            }
        }
        std::cout << text.str() << '\n';
    }
    
    return effects_;
}

// Print and return the product's mixers
std::vector<Mixer> Product::mixers(bool b_print_mixers) const
{
    std::ostringstream text;
    Mixer temp_mixer;

    if (b_print_mixers) {
        // Print each mixer in mixers_
        text << "Mixers: ";
        for (auto it = mixers_.begin(); it != mixers_.end(); it++)
        {
            text << it->name;
            if (it != (mixers_.end() - 1)) {
                text << ", ";
            }
        }
        std::cout << text.str() << '\n';
    }
    
    return mixers_;
}
