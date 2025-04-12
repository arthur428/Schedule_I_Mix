#ifndef __CALC_MIX_HPP__
#define __CALC_MIX_HPP__

#include <algorithm>
#include <cmath>    // pow
#include <cstdint>
#include <utility>  // std::move

#include "effect.hpp"
#include "mixer.hpp"
#include "product.hpp"

#define MAX_NUM_EFFECTS 8u

Product mix(const Product &product, const mixer_enum_t &mixer_enum);
Product find_most_profitable_mix(const Product &base_product, const int &n_mixers, const mixer_enum_t &last_unlocked_mixer);

#endif  // __CALC_MIX_HPP__
