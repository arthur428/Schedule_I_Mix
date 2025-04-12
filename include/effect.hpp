#ifndef __EFFECT_HPP__
#define __EFFECT_HPP__

#include <string>
#include <vector>

enum class effect_enum_t
{
    shrinking = 0,
    zombifying,
    cyclopean,
    antigravity,
    longfaced,
    electrifying,
    glowing,
    tropicthunder,
    thoughtprovoking,
    jennerising,
    brighteyed,
    spicy,
    foggy,
    slippery,
    athletic,
    balding,
    caloriedense,
    sedating,
    sneaky,
    energizing,
    gingeritis,
    euphoric,
    focused,
    refreshing,
    munchies,
    calming,
    disorienting,
    explosive,
    laxative,
    lethal,
    paranoia,
    schizophrenia,
    seizureinducing,
    smelly,
    toxic
};

struct Effect
{
    effect_enum_t id;
    std::string name;
    double multiplier;

    bool operator==(const Effect& other) const
    {
        return name == other.name && multiplier == other.multiplier;
    }

    bool operator!=(const Effect& other) const
    {
        return !operator==(other);
    }
};

const std::vector<Effect> G_VECTOR_EFFECTS = {
    {effect_enum_t::shrinking, "shrinking", 0.6},
    {effect_enum_t::zombifying, "zombifying", 0.58},
    {effect_enum_t::cyclopean, "cyclopean", 0.56},
    {effect_enum_t::antigravity, "antigravity", 0.54},
    {effect_enum_t::longfaced, "longfaced", 0.52},
    {effect_enum_t::electrifying, "electrifying", 0.50},
    {effect_enum_t::glowing, "glowing", 0.48},
    {effect_enum_t::tropicthunder, "tropicthunder", 0.46}, // check spelling
    {effect_enum_t::thoughtprovoking, "thoughtprovoking", 0.44},
    {effect_enum_t::jennerising, "jennerising", 0.42},
    {effect_enum_t::brighteyed, "brighteyed", 0.40},
    {effect_enum_t::spicy, "spicy", 0.38},
    {effect_enum_t::foggy, "foggy", 0.36},
    {effect_enum_t::slippery, "slippery", 0.34},
    {effect_enum_t::athletic, "athletic", 0.32},
    {effect_enum_t::balding, "balding", 0.30},
    {effect_enum_t::caloriedense, "caloriedense", 0.28},
    {effect_enum_t::sedating, "sedating", 0.26},
    {effect_enum_t::sneaky, "sneaky", 0.24},
    {effect_enum_t::energizing, "energizing", 0.22},
    {effect_enum_t::gingeritis, "gingeritis", 0.20},
    {effect_enum_t::euphoric, "euphoric", 0.18},
    {effect_enum_t::focused, "focused", 0.16},
    {effect_enum_t::refreshing, "refreshing", 0.14},
    {effect_enum_t::munchies, "munchies", 0.12},
    {effect_enum_t::calming, "calming", 0.10},
    {effect_enum_t::disorienting, "disorienting", 0.0},
    {effect_enum_t::explosive, "explosive", 0.0},
    {effect_enum_t::laxative, "laxative", 0.0},
    {effect_enum_t::lethal, "lethal", 0.0},
    {effect_enum_t::paranoia, "paranoia", 0.0},
    {effect_enum_t::schizophrenia, "schizophrenia", 0.0},
    {effect_enum_t::seizureinducing, "seizureinducing", 0.0},
    {effect_enum_t::smelly, "smelly", 0.0},
    {effect_enum_t::toxic, "toxic", 0.0}
};

#endif  // __EFFECT_HPP__
