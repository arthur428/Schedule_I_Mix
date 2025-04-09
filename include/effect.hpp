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
    {"shrinking", Effect{"Shrinking", 0.6}},
    {"zombifying", Effect{"Zombifying", 0.58}},
    {"cyclopean", Effect{"Cyclopean", 0.56}},
    {"antigravity", Effect{"Anti-Gravity", 0.54}},
    {"longfaced", Effect{"Long Faced", 0.52}},
    {"electrifying", Effect{"Electrifying", 0.50}},
    {"glowing", Effect{"Glowing", 0.48}},
    {"tropicthunder", Effect{"Tropic Thunder", 0.46}},
    {"thoughtprovoking", Effect{"Thought-Provoking", 0.44}},
    {"jennerising", Effect{"Jennerising", 0.42}},
    {"brighteyed", Effect{"Bright-Eyed", 0.40}},
    {"spicy", Effect{"Spicy", 0.38}},
    {"foggy", Effect{"Foggy", 0.36}},
    {"slippery", Effect{"Slippery", 0.34}},
    {"athletic", Effect{"Athletic", 0.32}},
    {"balding", Effect{"Balding", 0.30}},
    {"caloriedense", Effect{"Calorie-Dense", 0.28}},
    {"sedating", Effect{"Sedating", 0.26}},
    {"sneaky", Effect{"Sneaky", 0.24}},
    {"energizing", Effect{"Energizing", 0.22}},
    {"gingeritis", Effect{"Gingeritis", 0.20}},
    {"euphoric", Effect{"Euphoric", 0.18}},
    {"focused", Effect{"Focused", 0.16}},
    {"refreshing", Effect{"Refreshing", 0.14}},
    {"munchies", Effect{"Munchies", 0.12}},
    {"calming", Effect{"Calming", 0.10}},
    {"disorienting", Effect{"Disorienting", 0.0}},
    {"explosive", Effect{"Explosive", 0.0}},
    {"laxative", Effect{"Laxative", 0.0}},
    {"lethal", Effect{"Lethal", 0.0}},
    {"paranoia", Effect{"Paranoia", 0.0}},
    {"schizophrenia", Effect{"Schizophrenia", 0.0}},
    {"seizureinducing", Effect{"Seizure-Inducing", 0.0}},
    {"smelly", Effect{"Smelly", 0.0}},
    {"toxic", Effect{"Toxic", 0.0}}
};

#endif  // __EFFECT_HPP__
