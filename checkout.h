#pragma once
#include <string>
#define NUM_ITEMS 5
using namespace std;

class Checkout {        
  public:         
    int basket[NUM_ITEMS] = {0, 0, 0, 0, 0};
    string names[NUM_ITEMS] = {"Apple", "Pear", "Coffee", "Chicken", "Lobster"};
    int deal_type[NUM_ITEMS] = {0, 1, 2, 2, 2};
    float prices[NUM_ITEMS] = {2.50, 3.00, 5.00, 7.50, 10.00};

    Checkout() { 

    }

    int add(int item, int quantity)
    {
        basket[item] += quantity;
    }

    int remove(int item, int quantity) 
    {
        basket[item] -= quantity;
    }

    float price()
    {
        float total = 0.00;

        for (int i = 0; i < NUM_ITEMS; i++)
        {

            switch(deal_type[i]) {
                case 1:
                {
                    int num_deals = basket[i] / 3;
                    int remainder = basket[i] % 3;
                    basket[i] = num_deals * 2 + remainder;
                }
                    break;
                case 2:
                    break;
            }

            total += basket[i] * prices[i];
        }

        return total;
    }
};