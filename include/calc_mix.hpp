#ifndef __CALC_MIX_HPP__
#define __CALC_MIX_HPP__

#include <cctype>
#include <iostream>

#include "effect.hpp"
#include "mixer.hpp"
#include "product.hpp"

#define MAX_NUM_EFFECTS 8u

void replace_effect(std::vector<Effect> & effects, const mixer_enum_t & mixer_enum, const Effect & affected_effect);
void find_replace_effect(std::vector<Effect> & vec, std::string mixer_eff, std::string mixer_replace);
Product mix(const Product &product, const mixer_enum_t &mixer_enum);

#endif  // __CALC_MIX_HPP__
