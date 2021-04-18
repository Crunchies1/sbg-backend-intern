#pragma once
#include <string>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#define NUM_ITEMS 8
#define SET_ITEMS 3
#define MAIN 2
#define SNACK 1
#define DRINK 0
using namespace std;

class Checkout {        
    public:         

        // Basket stores a list of items possibly being purchased.
        map<int, int> basket = {};

        // These arrays store the names, deal types and prices of items.
        string names[NUM_ITEMS] = {"Apple", "Pear", "Coffee", "Juice", "Chicken", "Lobster", "Sweets", "Burger"};
        int deal_type[NUM_ITEMS] = {0, 1, 2, 2, 3, 4, 3, 4};
        float prices[NUM_ITEMS] = {2.50, 3.00, 5.00, 6.00, 7.50, 10.00, 4.00, 7.00};

        // Empty constructor, if there is no basket being provided.
        Checkout() {}

        // If basket is provided, we use that one.
        Checkout(int basket[NUM_ITEMS]) {
            basket = basket;
        }

        // Add item to the basket.
        int add(int item, int quantity)
        {
            map<int, int>::iterator it = basket.find(item); 
            if (it != basket.end()) 
            {
                it->second += quantity;
            } 
            else 
            {
                basket.insert(make_pair(item, quantity));
            }
        }

        // Remove item from the basket.
        int remove(int item, int quantity) 
        {
            map<int, int>::iterator it = basket.find(item); 
            if (it != basket.end()) 
            {   
                if (quantity >= it->second)
                {
                    it->second = 0;
                }
                else 
                {
                    it->second -= quantity;
                }
            } 
            else 
            {
                cout << "This item isn't in the basket!";
            }
        }

        void price()
        {
            // Stores the discount obtained.
            float disc = 0.00;
            // Stores the subtotal.
            float total = 0.00;
            // This vector keeps all the items purchased that can be part of a set.
            vector<float> set_prices = {};
            // This list keeps the number of items purchased of each part of a set.
            int set_item_count[SET_ITEMS] = {0, 0, 0};

            // Print out the individual items costs.
            cout << "\n ===== RECEIPT ===== \n";

            map<int, int>::iterator it;

            for (it = basket.begin(); it != basket.end(); it++)
            {
                int item = it->first;
                int quant = it->second;
                switch(deal_type[item]) 
                {
                    // This case is used to check for the "buy 3 for the cost of 2" deal.
                    case 1:
                        disc += (quant / 3) * prices[item];
                        break;

                    // This case is used to tally up DRINKS, to use for set meal calculation later.
                    case 2:
                        for (int b = 0; b < quant; b++) {
                            set_prices.push_back(prices[item]);
                        }
                        set_item_count[DRINK] += quant;
                        break;

                    // This case is used to tally up SNACKS.
                    case 3:
                        for (int b = 0; b < quant; b++) {
                            set_prices.push_back(prices[item]);
                        }
                        set_item_count[SNACK] += quant;
                        break;

                    // This case is used to tally up MAINS.
                    case 4:
                        for (int b = 0; b < quant; b++) {
                            set_prices.push_back(prices[item]);
                        }
                        set_item_count[MAIN] += quant;
                        break;
                }

                // Print out the item name and quantity bought, along with the total price.
                cout << names[item] << " x " << quant << ": $" << quant * prices[item] << "\n";

                // Update the total price.
                total += quant * prices[item];

            }

            // Calculate the number of sets purchased.
            int num_disc(min({set_item_count[DRINK], set_item_count[SNACK], set_item_count[MAIN]}));
            // Sort the items in the sets by descending price.
            sort(set_prices.rbegin(), set_prices.rend());
            // For each set, remove the cheapest item and add that to the discount total.
            for (int i = 0; i < num_disc; i++) 
            {
                disc += set_prices.back();
                set_prices.pop_back();
            }
            
            // Print out TOTAL part of the receipt.
            cout << "\n ===== TOTAL ===== \n";
            cout << "Subtotal: $" << total << "\n";
            cout << "DISCOUNT: $" << disc << "\n";
            cout << "Total price: $" << total - disc << "\n";
        }
};