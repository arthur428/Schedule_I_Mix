#ifndef __EFFECT_HPP__
#define __EFFECT_HPP__

#include <map>
#include <string>

struct Effect
{
    std::string name;
    double multiplier;

    bool operator==(const Effect& other) const
    {
        return name == other.name && multiplier == other.multiplier;
    }
};

const std::map<std::string, Effect> G_MAP_EFFECTS
{
    {"shrinking", Effect{"shrinking", 0.6}},
    {"zombifying", Effect{"zombifying", 0.58}},
    {"cyclopean", Effect{"cyclopean", 0.56}},
    {"antigravity", Effect{"antigravity", 0.54}},
    {"longfaced", Effect{"longfaced", 0.52}},
    {"electrifying", Effect{"electrifying", 0.50}},
    {"glowing", Effect{"glowing", 0.48}},
    {"tropicthunder", Effect{"tropicthunderr", 0.46}},
    {"thoughtprovoking", Effect{"thoughtprovoking", 0.44}},
    {"jennerising", Effect{"jennerising", 0.42}},
    {"brighteyed", Effect{"brighteyed", 0.40}},
    {"spicy", Effect{"spicy", 0.38}},
    {"foggy", Effect{"foggy", 0.36}},
    {"slippery", Effect{"slippery", 0.34}},
    {"athletic", Effect{"athletic", 0.32}},
    {"balding", Effect{"balding", 0.30}},
    {"caloriedense", Effect{"caloriedense", 0.28}},
    {"sedating", Effect{"sedating", 0.26}},
    {"sneaky", Effect{"sneaky", 0.24}},
    {"energizing", Effect{"energizing", 0.22}},
    {"gingeritis", Effect{"gingeritis", 0.20}},
    {"euphoric", Effect{"euphoric", 0.18}},
    {"focused", Effect{"focused", 0.16}},
    {"refreshing", Effect{"refreshing", 0.14}},
    {"munchies", Effect{"munchies", 0.12}},
    {"calming", Effect{"calming", 0.10}},
    {"disorienting", Effect{"disorienting", 0.0}},
    {"explosive", Effect{"explosive", 0.0}},
    {"laxative", Effect{"laxative", 0.0}},
    {"lethal", Effect{"lethal", 0.0}},
    {"paranoia", Effect{"paranoia", 0.0}},
    {"schizophrenia", Effect{"schizophrenia", 0.0}},
    {"seizureinducing", Effect{"seizureinducing", 0.0}},
    {"smelly", Effect{"smelly", 0.0}},
    {"toxic", Effect{"toxic", 0.0}}
};

#endif  // __EFFECT_HPP__
