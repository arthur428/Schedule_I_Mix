#include  "mixer.hpp"

// source: https://www.sportskeeda.com/esports/all-ingredients-schedule-1-their-effects
// const std::map<std::string, Mixer> G_MAP_MIXERS
// {
//     {"cuke", Mixer{"Cuke", 2.00, G_MAP_EFFECTS.at("energizing")}},
//     {"banana", Mixer{"Banana", 2.00, G_MAP_EFFECTS.at("gingeritis")}},
//     {"paracetamol", Mixer{"Paracetamol", 3.00, G_MAP_EFFECTS.at("sneaky")}},
//     {"donut", Mixer{"Donut", 3.00, G_MAP_EFFECTS.at("calorie-dense")}},
//     {"viagra", Mixer{"Viagra", 4.00, G_MAP_EFFECTS.at("tropicthunder")}},
//     {"mouthwash", Mixer{"Mouth Wash", 4.00, G_MAP_EFFECTS.at("balding")}},
//     {"flumedicine", Mixer{"Flu Medicine", 5.00, G_MAP_EFFECTS.at("sedating")}},
//     {"gasoline", Mixer{"Gasoline", 5.00, G_MAP_EFFECTS.at("toxic")}},
//     {"energydrink", Mixer{"Energy Drink", 6.00, G_MAP_EFFECTS.at("athletic")}},
//     {"motoroil", Mixer{"Motor Oil", 6.00, G_MAP_EFFECTS.at("slippery")}},
//     {"megabean", Mixer{"Mega Bean", 7.00, G_MAP_EFFECTS.at("foggy")}},
//     {"chili", Mixer{"Chili", 7.00, G_MAP_EFFECTS.at("spicy")}},
//     {"battery", Mixer{"Battery", 8.00, G_MAP_EFFECTS.at("brighteyed")}},
//     {"iodine", Mixer{"cuke", 8.00, G_MAP_EFFECTS.at("iodine")}},
//     {"addy", Mixer{"Addy", 9.00, G_MAP_EFFECTS.at("thoughtprovoking")}},
//     {"horsesemen", Mixer{"Horse Semen", 9.00, G_MAP_EFFECTS.at("longfaced")}},
// };

const std::map<int, Mixer> G_MAP_MIXERS
{
    {0, Mixer{"Cuke", 2.00, G_MAP_EFFECTS.at("energizing"),
        {"munchies", "foggy", "toxic", "euphoric", "slippery", "sneaky", "gingeritis", "slippery"}}},

    {1, Mixer{"Banana", 2.00, G_MAP_EFFECTS.at("gingeritis"),
        {"smelly", "disorienting", "paranoia", "longfaced", "focused", "toxic", "calming", "cyclopean", "energizing"}}},

    {2, Mixer{"Paracetamol", 3.00, G_MAP_EFFECTS.at("sneaky"),
        {"munchies", "electrifying", "paranoia", "spicy", "foggy", "focused", "calming", "glowing", "toxic", "energizing"}}},

    {3, Mixer{"Donut", 3.00, G_MAP_EFFECTS.at("caloriedense"),
        {"shrinking", "focused", "jennerising", "antigravity", "balding", "caloriedense"}}},

    {4, Mixer{"Viagra", 4.00, G_MAP_EFFECTS.at("tropicthunder"),
        {"euphoric", "laxative", "athletic", "toxic"}}},

    {5, Mixer{"Mouth Wash", 4.00, G_MAP_EFFECTS.at("balding"),
        {"calming", "focused", "explosive", "caloriedense"}}},

    {6, Mixer{"Flu Medicine", 5.00, G_MAP_EFFECTS.at("sedating"),
        {"calming", "focused", "laxative", "cyclopean", "thoughtprovoking", "athletic", "shrinking", "electrifying", "munchies", "euphoric"}}},

    {7, Mixer{"Gasoline", 5.00, G_MAP_EFFECTS.at("toxic"),
        {"paranoia", "electrifying", "energizing", "shrinking", "laxative", "disorienting", "munchies", "gingeritis", "jennerising", "energizing", "sneaky", "euphoric"}}},

    {8, Mixer{"Energy Drink", 6.00, G_MAP_EFFECTS.at("athletic"),
        {"schizophrenia", "glowing", "disorienting", "euphoric", "spicy", "foggy", "sedating", "focused", "tropicthunder"}}},

    {9, Mixer{"Motor Oil", 6.00, G_MAP_EFFECTS.at("slippery"),
        {"paranoia", "energizing", "euphoric", "foggy", "munchies"}}},

    {10, Mixer{"Mega Bean", 7.00, G_MAP_EFFECTS.at("foggy"),
        {"sneaky", "focused", "shrinking", "thoughtprovoking", "seizureinducing", "calming", "sneaky", "athletic", "jennerising", "slippery", "energizing"}}},

    {11, Mixer{"Chili", 7.00, G_MAP_EFFECTS.at("spicy"),
        {"sneaky", "athletic", "laxative", "shrinking", "munchies", "antigravity"}}},

    {12, Mixer{"Battery", 8.00, G_MAP_EFFECTS.at("brighteyed"),
        {"laxative", "cyclopean", "shrinking", "munchies", "electrifying", "euphoric"}}},

    {13, Mixer{"cuke", 8.00, G_MAP_EFFECTS.at("iodine"),
        {"caloriedense", "foggy", "calming", "euphoric", "toxic", "refreshing"}}},

    {14, Mixer{"Addy", 9.00, G_MAP_EFFECTS.at("thoughtprovoking"),
        {"longfaced", "foggy", "explosive", "sedating", "glowing"}}},
    
    {15, Mixer{"Horse Semen", 9.00, G_MAP_EFFECTS.at("longfaced"),
        {"antigravity", "thoughtprovoking", "gingeritis"}}}
};
