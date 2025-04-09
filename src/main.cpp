#include <iostream>
#include <sstream>

#include "calc_mix.hpp"
#include "product.hpp"

int main()
{
    using std::cout;

    std::ostringstream text;
    auto og_kush = Product(Product::base_product_t::OG_KUSH);
    
    cout << "1--------------------" << '\n';
    Product result = mix(og_kush, mixer_enum_t::paracetamol);
    cout << "Cost: " << result.cost() << '\n';
    cout << "Sell Price: " << result.sell_price() << '\n';
    cout << "Profit: " << result.profit() << '\n';
    result.effects();
    result.mixers();
    cout << "--------------------" << '\n';

    cout << "2--------------------" << '\n';
    result = mix(result, mixer_enum_t::cuke);
    cout << "Cost: " << result.cost() << '\n';
    cout << "Sell Price: " << result.sell_price() << '\n';
    cout << "Profit: " << result.profit() << '\n';
    result.effects();
    result.mixers();
    cout << "--------------------" << '\n';

    cout << "3--------------------" << '\n';
    result = mix(result, mixer_enum_t::paracetamol);
    cout << "Cost: " << result.cost() << '\n';
    cout << "Sell Price: " << result.sell_price() << '\n';
    cout << "Profit: " << result.profit() << '\n';
    result.effects();
    result.mixers();
    cout << "--------------------" << '\n';

    //Product result = mix(og_kush, mixer_enum_t::banana);
    //result = mix(result, mixer_enum_t::gasoline);
    //result = mix(result, mixer_enum_t::paracetamol);
    //result = mix(result, mixer_enum_t::cuke);
    //result = mix(result, mixer_enum_t::megabean);
    //result = mix(result, mixer_enum_t::battery);
    //result = mix(result, mixer_enum_t::banana);
    //result = mix(result, mixer_enum_t::cuke);
    //cout << "Cost: " << result.cost() << '\n';
    //cout << "Sell Price: " << result.sell_price() << '\n';
    //cout << "Profit: " << result.profit() << '\n';
    //result.effects();
    //result.mixers();

    return 0;
}