#ifndef __MIXER_HPP__
#define __MIXER_HPP__

#include <algorithm>
#include <map>
#include <string>

#include "effect.hpp"

enum class mixer_enum_t
{
   cuke = 0,
   banana,
   paracetamol,
   donut,
   viagra,
   mouthwash,
   flumedicine,
   gasoline,
   energydrink,
   motoroil,
   megabean,
   chili,
   battery,
   iodine,
   addy,
   horsesemen
};

struct Mixer
{
   std::string name;
   double cost;
   Effect effect;
   std::map<std::string, std::string> affected_effects;
};

// https://www.sportskeeda.com/esports/all-ingredients-schedule-1-their-effects
// https://www.ign.com/wikis/schedule-1/Schedule_1_Mixing_Guide
// https://hardcoregamer.com/schedule-1-every-ingredient-effects/
const std::map<int, Mixer> G_MAP_MIXERS
{
   {0, Mixer{"Cuke", 2.00, G_MAP_EFFECTS.at("energizing"),
      {
         {"euphoric", "laxative"},
         {"foggy", "cyclopean"},
         {"gingeritis", "thoughtprovoking"},
         {"munchies", "athletic"},
         {"slippery", "munchies"},
         {"sneaky", "paranoia"},
         {"toxic", "euphoric"},
      }}
   },

   {1, Mixer{"Banana", 2.00, G_MAP_EFFECTS.at("gingeritis"),
      {
         {"calming", "sneaky"},
         {"cyclopean", "energizing"},
         {"disorienting", "focused"},
         {"energizing", "thoughtprovoking"},
         {"focused", "seizureinducing"},
         {"longfaced", "refreshing"},
         {"paranoia", "jennerising"},
         {"smelly", "antigravity"},
         {"toxic", "smelly"},
      }}
   },

   {2, Mixer{"Paracetamol", 3.00, G_MAP_EFFECTS.at("sneaky"),
      {
         {"munchies", "antigravity"},
         {"electrifying", "athletic"},
         {"paranoia", "balding"},
         {"spicy", "brighteyed"},
         {"foggy", "calming"},
         {"focused", "gingeritis"},
         {"calming", "slippery"},
         {"glowing", "toxic"},
         {"toxic", "tropicthunder"},
         {"energizing", "paranoia"},
      }}
   },

   {3, Mixer{"Donut", 3.00, G_MAP_EFFECTS.at("caloriedense"),
      {
         {"antigravity", "slippery"},
         {"balding", "sneaky"},
         {"caloriedense", "explosive"},
         {"focused", "euphoric"},
         {"jennerising", "gingeritis"},
         {"munchies", "calming"},
         {"shrinking", "energizing"},
      }}
   },

   {4, Mixer{"Viagra", 4.00, G_MAP_EFFECTS.at("tropicthunder"),
      {
         {"athletic", "sneaky"},
         {"disorienting", "toxic"},
         {"euphoric", "brighteyed"},
         {"laxative", "calming"},
         {"shrinking", "gingeritis"},
      }}
   },

   {5, Mixer{"Mouth Wash", 4.00, G_MAP_EFFECTS.at("balding"),
      {
         {"calming", "antigravity"},
         {"caloriedense", "sneaky"},
         {"explosive", "sedating"},
         {"focused", "jennerising"},
      }}
   },

   {6, Mixer{"Flu Medicine", 5.00, G_MAP_EFFECTS.at("sedating"),
      {
         {"athletic", "munchies"},
         {"calming", "brighteyed"},
         {"cyclopean", "foggy"},
         {"electrifying", "refreshing"},
         {"euphoric", "toxic"},
         {"focused", "calming"},
         {"laxative", "euphoric"},
         {"munchies", "slippery"},
         {"shrinking", "paranoia"},
         {"thoughtprovoking", "gingeritis"},
      }}
   },

   {7, Mixer{"Gasoline", 5.00, G_MAP_EFFECTS.at("toxic"),
      {
         {"disorienting", "glowing"},
         {"electrifying", "disorienting"},
         {"energizing", "euphoric"},
         {"euphoric", "spicy"},
         {"gingeritis", "smelly"},
         {"jennerising", "sneaky"},
         {"laxative", "foggy"},
         {"munchies", "sedating"},
         {"paranoia", "calming"},
         {"shrinking", "focused"},
         {"sneaky", "tropicthunder"},
      }}
   },

   {8, Mixer{"Energy Drink", 6.00, G_MAP_EFFECTS.at("athletic"),
      {
         {"disorienting", "electrifying"},
         {"euphoric", "energizing"},
         {"focused", "shrinking"},
         {"foggy", "laxative"},
         {"glowing", "disorienting"},
         {"schizophrenia", "balding"},
         {"sedating", "munchies"},
         {"spicy", "euphoric"},
         {"tropicthunder", "sneaky"},
      }}
   },

   {9, Mixer{"Motor Oil", 6.00, G_MAP_EFFECTS.at("slippery"),
      {
         {"energizing", "munchies"},
         {"euphoric", "sedating"},
         {"foggy", "toxic"},
         {"munchies", "schizophrenia"},
         {"paranoia", "antigravity"},
      }}
   },

   {10, Mixer{"Mega Bean", 7.00, G_MAP_EFFECTS.at("foggy"),
      {
         {"athletic", "laxative"},
         {"calming", "glowing"},
         {"energizing", "cyclopean"},
         {"focused", "disorienting"},
         {"jennerising", "paranoia"},
         {"seizureinducing", "focused"},
         {"shrinking", "electrifying"},
         {"slippery", "toxic"},
         {"sneaky", "calming"},
         {"thoughtprovoking", "energizing"},
      }}
   },

   {11, Mixer{"Chili", 7.00, G_MAP_EFFECTS.at("spicy"),
      {
         {"antigravity", "tropicthunder"},
         {"athletic", "euphoric"},
         {"laxative", "longfaced"},
         {"munchies", "toxic"},
         {"shrinking", "refreshing"},
         {"sneaky", "brighteyed"},
         {"thoughtprovoking", "focused"},
      }}
   },

   {12, Mixer{"Battery", 8.00, G_MAP_EFFECTS.at("brighteyed"),
      {
         {"cyclopean", "glowing"},
         {"electrifying", "euphoric"},
         {"euphoric", "zombifying"},
         {"laxative", "caloriedense"},
         {"munchies", "tropicthunder"},
         {"shrinking", "munchies"},
      }}
   },

   {13, Mixer{"Iodine", 8.00, G_MAP_EFFECTS.at("jennerising"),
      {
         {"calming", "balding"},
         {"caloriedense", "gingeritis"},
         {"euphoric", "seizureinducing"},
         {"foggy", "paranoia"},
         {"refreshing", "thoughtprovoking"},
         {"toxic", "sneaky"},
      }}
   },

   {14, Mixer{"Addy", 9.00, G_MAP_EFFECTS.at("thoughtprovoking"),
      {
         {"explosive", "euphoric"},
         {"foggy", "energizing"},
         {"glowing", "refreshing"},
         {"longfaced", "electrifying"},
         {"sedating", "gingeritis"},
      }}
   },

   {15, Mixer{"Horse Semen", 9.00, G_MAP_EFFECTS.at("longfaced"),
      {
         {"antigravity", "calming"},
         {"gingeritis", "refreshing"},
         {"seizureinducing", "energizing"},
         {"thoughtprovoking", "electrifying"},
      }}
   },

};

#endif // __MIXER_HPP__
