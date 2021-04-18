#include "checkout.h"
#include <iostream>

int main()
{
    Checkout checkout = Checkout();

    checkout.add(0, 0);
    checkout.add(1, 6);
    checkout.add(2, 1);
    checkout.add(3, 1);
    checkout.add(4, 2);
    checkout.add(5, 1);
    checkout.add(6, 1);
    checkout.add(7, 1);

    checkout.price();
}