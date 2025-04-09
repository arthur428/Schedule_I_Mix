#include <iostream>
#include <sstream>

#include "calc_mix.hpp"
#include "product.hpp"

int main()
{
    using std::cout;

    std::ostringstream text;
    auto og_kush = Product(Product::base_product_t::OG_KUSH);
    Product result = mix(og_kush, mixer_enum_t::mouthwash);

    cout << "--------------------" << '\n';
    cout << "Cost: " << result.cost() << '\n';
    cout << "Sell Price: " << result.sell_price() << '\n';
    cout << "Profit: " << result.profit() << '\n';
    result.effects();
    result.mixers();
    cout << "--------------------" << '\n';

    return 0;
}