#include "checkout.h"

int main()
{
    // Create a new empty checkout.
    Checkout checkout = Checkout();

    // Add items to the basket using item number.
    checkout.add(1, 5); // Add 5 Pears. (3 for 2 discount applied, so you pay for 4.)
    checkout.add(2, 1); // Add 1 Coffee. (DRINK)
    checkout.add(3, 1); // Add 1 Juice. (DRINK)
    checkout.add(4, 2); // Add 2 Chicken. (SNACK)
    checkout.add(5, 1); // Add 1 Lobster. (MAIN)
    checkout.add(6, 1); // Add 1 Sweet. (SNACK)
    checkout.add(7, 1); // Add 1 Burger. (MAIN)
    checkout.add(4, 1); // Add another Chicken. (SNACK)

    checkout.price();
}