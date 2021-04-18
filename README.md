# SGD Test 

### Thoughts

This project was enjoyable, as I got to learn more about the C++ language. However, I realize that I've only scratched the surface with this, so I will do more to increase my knowledge of the C++ language.

## Getting Started

All you need to get the program to run:

*You need the G++ compiler installed. You need this in order to run g++ commands.* 

From Github:

Clone the repository, then cd into it. After that run the following two lines.
```bash
g++ checkout.cc -o output.exe
output.exe
```

From ZIP file:

Extract the contents of the zip file into a new directory, then cd into it. After that run the following two lines.
```bash
g++ checkout.cc -o output.exe
output.exe
```

*Note that this adds an output.exe file to the same directory.*

## Decisions and Interpretations

There were a multitude of decisions made during the creation of the checkout. I wanted to try and make the code as scalable as possible, so to that end, I needed to create an easy way to add new items for sale. With a singular list containing all the details of an item, this would be possible, as you only needed to modify a single list to add a new item to the store. Having a switch case be in charge of all the deals available also made sense, as all you would need to do to create a new deal is to modify the switch statement and the logic. If I had the time, I would definitely have tried to abstract more of the logic in the switch statement away, so it would be easier to understand and change in the future.

As for the deals, the route I went with the set deal was similar to the Tesco's meal deal. You are allowed to get a drink, snack and a main, with this only costing 3 pounds. However, the one here simply removes the cheapest item in the set. The deal logic also accounts for duplicate meals.

Lastly, the format of the receipt was chosen through a template found online. Printing out all the individual items, their quantity and total price, then finally printing out the subtotal, discount and total price at the bottom of the receipt. I hope the format is suitable.