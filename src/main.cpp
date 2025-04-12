#include <iostream>

#include "calc_mix.hpp"
#include "product.hpp"

int main()
{
    using std::cout;

    /***  EXAMPLE 1 ***/
    //Product result = mix(Product(Product::base_product_t::SOUR_DIESEL), mixer_enum_t::cuke);
    //result.effects(true);
    //result.mixers(true);
    //cout << "-----" << '\n';

    //result = mix(result, mixer_enum_t::banana);
    //result.effects(true);
    //result.mixers(true);
    //cout << "-----" << '\n';

    //result = mix(result, mixer_enum_t::horsesemen);
    //result.effects(true);
    //result.mixers(true);
    //cout << "-----" << '\n';

    //result = mix(result, mixer_enum_t::iodine);
    //result.effects(true);
    //result.mixers(true);
    //cout << "-----" << '\n';

    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';

    /***  EXAMPLE 2 ***/
    Product result;
    mixer_enum_t max_mixer = mixer_enum_t::horsesemen;

    result = find_most_profitable_mix(Product(Product::base_product_t::OG_KUSH), 3, max_mixer);
    cout << "Batch Cost: " << result.cost_batch() << '\n';
    cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    cout << "Batch Profit: " << result.profit_batch() << '\n';
    result.effects(true);
    result.mixers(true);
    cout << "----------" << '\n';

    result = find_most_profitable_mix(Product(Product::base_product_t::SOUR_DIESEL), 3, max_mixer);
    cout << "Batch Cost: " << result.cost_batch() << '\n';
    cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    cout << "Batch Profit: " << result.profit_batch() << '\n';
    result.effects(true);
    result.mixers(true);
    cout << "----------" << '\n';

    result = find_most_profitable_mix(Product(Product::base_product_t::GREEN_CRACK), 3, max_mixer);
    cout << "Batch Cost: " << result.cost_batch() << '\n';
    cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    cout << "Batch Profit: " << result.profit_batch() << '\n';
    result.effects(true);
    result.mixers(true);
    cout << "----------" << '\n';

    result = find_most_profitable_mix(Product(Product::base_product_t::G_PURPLE), 3, max_mixer);
    cout << "Batch Cost: " << result.cost_batch() << '\n';
    cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    cout << "Batch Profit: " << result.profit_batch() << '\n';
    result.effects(true);
    result.mixers(true);
    cout << "----------" << '\n';

    result = find_most_profitable_mix(Product(Product::base_product_t::METH), 3, max_mixer);
    cout << "Batch Cost: " << result.cost_batch() << '\n';
    cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    cout << "Batch Profit: " << result.profit_batch() << '\n';
    result.effects(true);
    result.mixers(true);
    cout << "----------" << '\n';


    /***  EXAMPLE 3 ***/
    // Product result;

    // result = mix(Product(Product::base_product_t::OG_KUSH), mixer_enum_t::mouthwash);
    // result = find_most_profitable_mix(result, 1, mixer_enum_t::megabean);
    // result.effects(true);
    // result.mixers(true);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // cout << "----------" << '\n';

    // result = mix(Product(Product::base_product_t::SOUR_DIESEL), mixer_enum_t::viagra);
    // result = find_most_profitable_mix(result, 1, mixer_enum_t::megabean);
    // result.effects(true);
    // result.mixers(true);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // cout << "----------" << '\n';

    // result = mix(Product(Product::base_product_t::GREEN_CRACK), mixer_enum_t::megabean);
    // result = find_most_profitable_mix(result, 1, mixer_enum_t::megabean);
    // result.effects(true);
    // result.mixers(true);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // cout << "----------" << '\n';

    // result = mix(Product(Product::base_product_t::G_PURPLE), mixer_enum_t::viagra);
    // result = find_most_profitable_mix(result, 1, mixer_enum_t::megabean);
    // result.effects(true);
    // result.mixers(true);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // cout << "----------" << '\n';

    // Product result;
    // result = find_most_profitable_mix(Product(Product::base_product_t::METH), 2, mixer_enum_t::chili);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // cout << "----------" << '\n';
    // result.effects(true);
    // result.mixers(true);

    /***  EXAMPLE 4 ***/
    // Product result;

    // result = Product(Product::base_product_t::METH);
    // result = mix(result, mixer_enum_t::cuke);
    // result = mix(result, mixer_enum_t::megabean);
    // result = mix(result, mixer_enum_t::viagra);
    // result = mix(result, mixer_enum_t::paracetamol);
    // result = mix(result, mixer_enum_t::megabean);
    // result = mix(result, mixer_enum_t::mouthwash);
    // result = find_most_profitable_mix(result, 2, mixer_enum_t::iodine);
    // result.effects(true);
    // result.mixers(true);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // cout << "----------" << '\n';

    /***  EXAMPLE 5 ***/
    // Product result;
    // mixer_enum_t max_mixer = mixer_enum_t::horsesemen;

    // result = find_most_profitable_mix(Product(Product::base_product_t::METH), 8, max_mixer);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // result.effects(true);
    // result.mixers(true);
    // cout << "----------" << '\n';

    return 0;
}