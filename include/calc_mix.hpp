#ifndef __CALC_MIX_HPP__
#define __CALC_MIX_HPP__

#include <cmath>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <sstream>

#include "effect.hpp"
#include "mixer.hpp"
#include "product.hpp"

#define MAX_NUM_EFFECTS 8u

Product mix(const Product &product, const mixer_enum_t &mixer_enum);
Product find_most_profitable_mix(const Product::base_product_t &base, const int &n_mixers, const mixer_enum_t &last_unlocked_mixer);

#endif  // __CALC_MIX_HPP__
