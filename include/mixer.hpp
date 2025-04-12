#ifndef __MIXER_HPP__
#define __MIXER_HPP__

#include <map>
#include <string>
#include <vector>

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
   std::map<effect_enum_t, effect_enum_t> affected_effects;
};

// https://www.sportskeeda.com/esports/all-ingredients-schedule-1-their-effects
// https://www.ign.com/wikis/schedule-1/Schedule_1_Mixing_Guide
// https://hardcoregamer.com/schedule-1-every-ingredient-effects/
const std::vector<Mixer> G_VECTOR_MIXERS
{
   {"Cuke", 2.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::energizing)],
      {
         {effect_enum_t::euphoric, effect_enum_t::laxative},
         {effect_enum_t::foggy, effect_enum_t::cyclopean},
         {effect_enum_t::gingeritis, effect_enum_t::thoughtprovoking},
         {effect_enum_t::munchies, effect_enum_t::athletic},
         {effect_enum_t::slippery, effect_enum_t::munchies},
         {effect_enum_t::sneaky, effect_enum_t::paranoia},
         {effect_enum_t::toxic, effect_enum_t::euphoric}
      }
   },

   {"Banana", 2.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::gingeritis)],
      {
         {effect_enum_t::calming, effect_enum_t::sneaky},
         {effect_enum_t::cyclopean, effect_enum_t::energizing},
         {effect_enum_t::disorienting, effect_enum_t::focused},
         {effect_enum_t::energizing, effect_enum_t::thoughtprovoking},
         {effect_enum_t::focused, effect_enum_t::seizureinducing},
         {effect_enum_t::longfaced, effect_enum_t::refreshing},
         {effect_enum_t::paranoia, effect_enum_t::jennerising},
         {effect_enum_t::smelly, effect_enum_t::antigravity},
         {effect_enum_t::toxic, effect_enum_t::smelly}
      }
   },

   {"Paracetamol", 3.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::sneaky)],
      {
         {effect_enum_t::munchies, effect_enum_t::antigravity},
         {effect_enum_t::electrifying, effect_enum_t::athletic},
         {effect_enum_t::paranoia, effect_enum_t::balding},
         {effect_enum_t::spicy, effect_enum_t::brighteyed},
         {effect_enum_t::foggy, effect_enum_t::calming},
         {effect_enum_t::focused, effect_enum_t::gingeritis},
         {effect_enum_t::calming, effect_enum_t::slippery},
         {effect_enum_t::glowing, effect_enum_t::toxic},
         {effect_enum_t::toxic, effect_enum_t::tropicthunder},
         {effect_enum_t::energizing, effect_enum_t::paranoia}
      }
   },

   {"Donut", 3.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::caloriedense)],
      {
         {effect_enum_t::antigravity, effect_enum_t::slippery},
         {effect_enum_t::balding, effect_enum_t::sneaky},
         {effect_enum_t::caloriedense, effect_enum_t::explosive},
         {effect_enum_t::focused, effect_enum_t::euphoric},
         {effect_enum_t::jennerising, effect_enum_t::gingeritis},
         {effect_enum_t::munchies, effect_enum_t::calming},
         {effect_enum_t::shrinking, effect_enum_t::energizing}
      }
   },

   {"Viagra", 4.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::tropicthunder)],
      {
         {effect_enum_t::athletic, effect_enum_t::sneaky},
         {effect_enum_t::disorienting, effect_enum_t::toxic},
         {effect_enum_t::euphoric, effect_enum_t::brighteyed},
         {effect_enum_t::laxative, effect_enum_t::calming},
         {effect_enum_t::shrinking, effect_enum_t::gingeritis}
      }
   },

  {"Mouth Wash", 4.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::balding)],
      {
         {effect_enum_t::calming, effect_enum_t::antigravity},
         {effect_enum_t::caloriedense, effect_enum_t::sneaky},
         {effect_enum_t::explosive, effect_enum_t::sedating},
         {effect_enum_t::focused, effect_enum_t::jennerising}
      }
   },

  {"Flu Medicine", 5.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::sedating)],
      {
         {effect_enum_t::athletic, effect_enum_t::munchies},
         {effect_enum_t::calming, effect_enum_t::brighteyed},
         {effect_enum_t::cyclopean, effect_enum_t::foggy},
         {effect_enum_t::electrifying, effect_enum_t::refreshing},
         {effect_enum_t::euphoric, effect_enum_t::toxic},
         {effect_enum_t::focused, effect_enum_t::calming},
         {effect_enum_t::laxative, effect_enum_t::euphoric},
         {effect_enum_t::munchies, effect_enum_t::slippery},
         {effect_enum_t::shrinking, effect_enum_t::paranoia},
         {effect_enum_t::thoughtprovoking, effect_enum_t::gingeritis}
      }
   },

   {"Gasoline", 5.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::toxic)],
      {
         {effect_enum_t::disorienting, effect_enum_t::glowing},
         {effect_enum_t::electrifying, effect_enum_t::disorienting},
         {effect_enum_t::energizing, effect_enum_t::euphoric},
         {effect_enum_t::euphoric, effect_enum_t::spicy},
         {effect_enum_t::gingeritis, effect_enum_t::smelly},
         {effect_enum_t::jennerising, effect_enum_t::sneaky},
         {effect_enum_t::laxative, effect_enum_t::foggy},
         {effect_enum_t::munchies, effect_enum_t::sedating},
         {effect_enum_t::paranoia, effect_enum_t::calming},
         {effect_enum_t::shrinking, effect_enum_t::focused},
         {effect_enum_t::sneaky, effect_enum_t::tropicthunder}
      }
   },

   {"Energy Drink", 6.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::athletic)],
      {
         {effect_enum_t::disorienting, effect_enum_t::electrifying},
         {effect_enum_t::euphoric, effect_enum_t::energizing},
         {effect_enum_t::focused, effect_enum_t::shrinking},
         {effect_enum_t::foggy, effect_enum_t::laxative},
         {effect_enum_t::glowing, effect_enum_t::disorienting},
         {effect_enum_t::schizophrenia, effect_enum_t::balding},
         {effect_enum_t::sedating, effect_enum_t::munchies},
         {effect_enum_t::spicy, effect_enum_t::euphoric},
         {effect_enum_t::tropicthunder, effect_enum_t::sneaky}
      }
   },

   {"Motor Oil", 6.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::slippery)],
      {
         {effect_enum_t::energizing, effect_enum_t::munchies},
         {effect_enum_t::euphoric, effect_enum_t::sedating},
         {effect_enum_t::foggy, effect_enum_t::toxic},
         {effect_enum_t::munchies, effect_enum_t::schizophrenia},
         {effect_enum_t::paranoia, effect_enum_t::antigravity}
      }
   },

   {"Mega Bean", 7.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::foggy)],
      {
         {effect_enum_t::athletic, effect_enum_t::laxative},
         {effect_enum_t::calming, effect_enum_t::glowing},
         {effect_enum_t::energizing, effect_enum_t::cyclopean},
         {effect_enum_t::focused, effect_enum_t::disorienting},
         {effect_enum_t::jennerising, effect_enum_t::paranoia},
         {effect_enum_t::seizureinducing, effect_enum_t::focused},
         {effect_enum_t::shrinking, effect_enum_t::electrifying},
         {effect_enum_t::slippery, effect_enum_t::toxic},
         {effect_enum_t::sneaky, effect_enum_t::calming},
         {effect_enum_t::thoughtprovoking, effect_enum_t::energizing}
      }
   },

   {"Chili", 7.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::spicy)],
      {
         {effect_enum_t::antigravity, effect_enum_t::tropicthunder},
         {effect_enum_t::athletic, effect_enum_t::euphoric},
         {effect_enum_t::laxative, effect_enum_t::longfaced},
         {effect_enum_t::munchies, effect_enum_t::toxic},
         {effect_enum_t::shrinking, effect_enum_t::refreshing},
         {effect_enum_t::sneaky, effect_enum_t::brighteyed},
         {effect_enum_t::thoughtprovoking, effect_enum_t::focused}
      }
   },

   {"Battery", 8.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::brighteyed)],
      {
         {effect_enum_t::cyclopean, effect_enum_t::glowing},
         {effect_enum_t::electrifying, effect_enum_t::euphoric},
         {effect_enum_t::euphoric, effect_enum_t::zombifying},
         {effect_enum_t::laxative, effect_enum_t::caloriedense},
         {effect_enum_t::munchies, effect_enum_t::tropicthunder},
         {effect_enum_t::shrinking, effect_enum_t::munchies}
      }
   },

   {"Iodine", 8.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::jennerising)],
      {
         {effect_enum_t::calming, effect_enum_t::balding},
         {effect_enum_t::caloriedense, effect_enum_t::gingeritis},
         {effect_enum_t::euphoric, effect_enum_t::seizureinducing},
         {effect_enum_t::foggy, effect_enum_t::paranoia},
         {effect_enum_t::refreshing, effect_enum_t::thoughtprovoking},
         {effect_enum_t::toxic, effect_enum_t::sneaky}
      }
   },

   {"Addy", 9.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::thoughtprovoking)],
      {
         {effect_enum_t::explosive, effect_enum_t::euphoric},
         {effect_enum_t::foggy, effect_enum_t::energizing},
         {effect_enum_t::glowing, effect_enum_t::refreshing},
         {effect_enum_t::longfaced, effect_enum_t::electrifying},
         {effect_enum_t::sedating, effect_enum_t::gingeritis}
      }
   },

   {"Horse Semen", 9.00, G_VECTOR_EFFECTS[static_cast<int>(effect_enum_t::longfaced)],
      {
         {effect_enum_t::antigravity, effect_enum_t::calming},
         {effect_enum_t::gingeritis, effect_enum_t::refreshing},
         {effect_enum_t::seizureinducing, effect_enum_t::energizing},
         {effect_enum_t::thoughtprovoking, effect_enum_t::electrifying}
      }
   },
};

#endif // __MIXER_HPP__
