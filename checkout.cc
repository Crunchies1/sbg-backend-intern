#include "checkout.h"
#include <iostream>

int main()
{
    Checkout checkout = Checkout();

    checkout.add(0, 2);
    checkout.add(1, 3);
    checkout.add(3, 1);

    float total = checkout.price();
    std::cout << "Total price: $" << total;
}