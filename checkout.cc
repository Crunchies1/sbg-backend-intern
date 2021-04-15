// my first program in C++
#include <iostream>
#define NUM_ITEMS 5

int add(int basket[], int item, int quantity)
{
    basket[item] += quantity;
}

int remove(int basket[], int item, int quantity) 
{
    basket[item] -= quantity;
}

float checkout(int basket[], float prices[])
{
    float total = 0.00;

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        total += basket[i] * prices[i];
    }

    return total;
}

int main()
{
    std::cout << "Hello World!";
    int basket[NUM_ITEMS] = {0, 0, 0, 0, 0};
    float prices[NUM_ITEMS] = {2.50, 3.00, 5.00, 7.50, 10.00};

    add(basket, 0, 2);
    add(basket, 3, 1);

    float total = checkout(basket, prices);
    std::cout << total;
}