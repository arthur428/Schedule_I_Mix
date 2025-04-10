#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include <string>
#include <vector>

#include "effect.hpp"
#include "mixer.hpp"

#define BASE_PRICE_WEED 35.0
#define BASE_PRICE_METH 70.0
#define BASE_PRICE_COCAINE 150.0

#define COST_SEED_OG_KUSH 30.0
#define COST_SEED_SOUR_DIESEL 35.0
#define COST_SEED_GREEN_CRACK 40.0
#define COST_SEED_G_PURPLE 45.0

class Product
{
public:
    enum class base_product_t
    {
        OG_KUSH = 0,
        SOUR_DIESEL,
        GREEN_CRACK,
        G_PURPLE,
        CUSTOM,
        BASE_MAX  // DO NOT USE
    };

    // Base product constructor
    Product(const base_product_t & base);
    Product(const base_product_t & base, const std::vector<Effect> & effects, const std::vector<Mixer> & mixers);
    double cost_batch();
    double sell_price_unit();
    double sell_price_batch();
    double profit_batch();
    base_product_t base() const;
    std::vector<Effect> Product::effects(bool b_print_effects = false) const;
    std::vector<Mixer> Product::mixers(bool b_print_mixers = false) const;

private:
    double sell_price_unit_;
    double sell_price_batch_;
    double cost_batch_;
    base_product_t base_;
    std::vector<Effect> effects_;
    double cost_seed_;
    double base_price_;
    std::vector<Mixer> mixers_; // Mixer History? Then create another variable for "mixer_addons"?
};

#endif // __PRODUCT_HPP__
