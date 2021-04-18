#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>
// Here we define magic numbers that are used in the program.
// This refers to the total number of items on sale.
#define NUM_ITEMS 8
// This refers to the number of items in a set.
#define SET_ITEMS 3
// These refer to the type of item in the set.
#define MAIN 2
#define SNACK 1
#define DRINK 0
using namespace std;

class Checkout {        
    public:         

        // Basket stores a list of items possibly being purchased.
        map<int, int> basket = {};

        // This array stores the names, deal types and prices of items.
        tuple<string, float, int> item_list[NUM_ITEMS] = 
        {
            make_tuple("Apple", 2.50, 0),
            make_tuple("Pear", 3.00, 1),
            make_tuple("Coffee", 5.00, 2),
            make_tuple("Juice", 6.00, 2),
            make_tuple("Chicken", 7.50, 3),
            make_tuple("Lobster", 10.00, 4),
            make_tuple("Sweets", 4.00, 3),
            make_tuple("Burger", 7.00, 4)
        };

        // Empty constructor, if there is no basket being provided.
        Checkout() {}

        // If basket is provided, we use that one.
        Checkout(int basket[NUM_ITEMS]) {
            basket = basket;
        }

        // Add item to the basket.
        int add(int item, int quantity)
        {
            // Look for the item being added, if it is already in the map, update quantity.
            map<int, int>::iterator it = basket.find(item); 
            if (it != basket.end()) 
            {
                it->second += quantity;
            } 
            // Otherwise, insert item into the map.
            else 
            {
                basket.insert(make_pair(item, quantity));
            }
        }

        // Remove item from the basket.
        int remove(int item, int quantity) 
        {
            // Look for the item being added, if it is already in the map, update quantity to a limit of 0.
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
            // Otherwise, print error message.
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

            // Loop through the basket items.
            map<int, int>::iterator it;
            for (it = basket.begin(); it != basket.end(); it++)
            {
                // Store the item number and quantity being purchased.
                int item = it->first;
                int quant = it->second;

                // Check whether the item purchased has any deal associated with it.
                switch(get<2>(item_list[item])) 
                {
                    // This case is used to check for the "buy 3 for the cost of 2" deal.
                    case 1:
                        disc += (quant / 3) * get<1>(item_list[item]);
                        break;

                    // This case is used to tally up DRINKS, to use for set meal calculation later.
                    case 2:
                        for (int b = 0; b < quant; b++) {
                            set_prices.push_back(get<1>(item_list[item]));
                        }
                        set_item_count[DRINK] += quant;
                        break;

                    // This case is used to tally up SNACKS.
                    case 3:
                        for (int b = 0; b < quant; b++) {
                            set_prices.push_back(get<1>(item_list[item]));
                        }
                        set_item_count[SNACK] += quant;
                        break;

                    // This case is used to tally up MAINS.
                    case 4:
                        for (int b = 0; b < quant; b++) {
                            set_prices.push_back(get<1>(item_list[item]));
                        }
                        set_item_count[MAIN] += quant;
                        break;
                }

                // Print out the item name and quantity bought, along with the total price.
                cout << get<0>(item_list[item]) << " x " << quant << ": $" << quant * get<1>(item_list[item]) << "\n";

                // Update the total price.
                total += quant * get<1>(item_list[item]);

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