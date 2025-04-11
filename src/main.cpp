#include <iostream>

#include "calc_mix.hpp"
#include "product.hpp"

int main()
{
    using std::cout;

    auto og_kush = Product(Product::base_product_t::OG_KUSH);
    
    //cout << "1--------------------" << '\n';
    //Product result = mix(og_kush, mixer_enum_t::paracetamol);
    //cout << "Cost: " << result.cost() << '\n';
    //cout << "Sell Price: " << result.sell_price() << '\n';
    //cout << "Profit: " << result.profit() << '\n';
    //result.effects();
    //result.mixers();
    //cout << "--------------------" << '\n';

    //cout << "2--------------------" << '\n';
    //result = mix(result, mixer_enum_t::cuke);
    //cout << "Cost: " << result.cost() << '\n';
    //cout << "Sell Price: " << result.sell_price() << '\n';
    //cout << "Profit: " << result.profit() << '\n';
    //result.effects();
    //result.mixers();
    //cout << "--------------------" << '\n';

    //cout << "3--------------------" << '\n';
    //result = mix(result, mixer_enum_t::paracetamol);
    //cout << "Cost: " << result.cost() << '\n';
    //cout << "Sell Price: " << result.sell_price() << '\n';
    //cout << "Profit: " << result.profit() << '\n';
    //result.effects();
    //result.mixers();
    //cout << "--------------------" << '\n';

    // Product result = mix(og_kush, mixer_enum_t::banana);
    // result = mix(result, mixer_enum_t::gasoline);
    // result = mix(result, mixer_enum_t::paracetamol);
    // result = mix(result, mixer_enum_t::cuke);
    // result = mix(result, mixer_enum_t::megabean);
    // result = mix(result, mixer_enum_t::battery);
    // result = mix(result, mixer_enum_t::banana);
    // result = mix(result, mixer_enum_t::cuke);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // result.effects(true);
    // result.mixers(true);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';

    // Product result = mix(og_kush, mixer_enum_t::banana);
    // result.effects(true);
    // result.mixers(true);
    // cout << "-----" << '\n';

    // result = mix(result, mixer_enum_t::cuke);
    // result.effects(true);
    // result.mixers(true);
    // cout << "-----" << '\n';

    // result = mix(result, mixer_enum_t::megabean);
    // result.effects(true);
    // result.mixers(true);
    // cout << "-----" << '\n';

    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';

    Product result = mix(og_kush, mixer_enum_t::paracetamol);
    result.effects(true);
    result.mixers(true);
    cout << "-----" << '\n';

    result = mix(result, mixer_enum_t::cuke);
    result.effects(true);
    result.mixers(true);
    cout << "-----" << '\n';

    result = mix(result, mixer_enum_t::paracetamol);
    result.effects(true);
    result.mixers(true);
    cout << "-----" << '\n';

    cout << "Batch Cost: " << result.cost_batch() << '\n';
    cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    cout << "Batch Profit: " << result.profit_batch() << '\n';

    // Product result = find_most_profitable_mix(Product::base_product_t::G_PURPLE, 3, mixer_enum_t::addy);
    // cout << "Batch Cost: " << result.cost_batch() << '\n';
    // cout << "Unit Sell Price: " << result.sell_price_unit() << '\n';
    // cout << "Batch Sell Price: " << result.sell_price_batch() << '\n';
    // cout << "Batch Profit: " << result.profit_batch() << '\n';
    // result.effects(true);
    // result.mixers(true);

    return 0;
}