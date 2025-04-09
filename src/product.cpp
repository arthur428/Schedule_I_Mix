#include "product.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

// Base product constructor
Product::Product(const base_product_t & base)
:   sell_price_{0},
    cost_{0}
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
double Product::cost()
{
    double cost = cost_seed_;

    // Add seed cost and cost of all mixers.
    for (const Mixer & m : mixers_) {
        cost += m.cost;
    }
    cost_ = cost;

    return cost;
}

// Calculate selling price of product
double Product::sell_price()
{
    double sell_price = 0;
    double sum_mult = 0;

    // Get sum of effect multipliers
    for (const Effect & e : effects_) {
        sum_mult += e.multiplier;
    }

    // Calculate selling price
    sell_price = base_price_ * (1 + sum_mult);
    sell_price_ = floor(sell_price);

    return sell_price_;
}

// Calculate profit from selling the product without mark-up
double Product::profit() const
{
    return sell_price_ - cost_;
}

Product::base_product_t Product::base() const
{
    return base_;
}

// Print and return the product's effects
std::vector<Effect> Product::effects() const
{
    std::ostringstream text;
    Effect temp_effect;

    // Print each effect in effects_
    text << "Effects: ";
    for (auto it = effects_.begin(); it != effects_.end(); it++)
    {
        text << it->name;
        if (it != (effects_.end() - 1)) {
            text << ", ";
        }
    }
    std::cout << text.str() << '\n';
    
    return effects_;
}

// Print and return the product's mixers
std::vector<Mixer> Product::mixers() const
{
    std::ostringstream text;
    Mixer temp_mixer;

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
    
    return mixers_;
}
