#include <stdio.h>

struct Card
{
    int value;  // 1, 2... Q(12), K(13)..
    int suit;   // 0 = club | 1 = spade | 2 = heart | 3 = diamond
    int color;  // 0 = Red | 1 = Black
};

int main(void)
{
    // initialize a card struct
    struct Card c1; 
    // 1 way to assign members 
    c1.color = 0;   // red
    c1.suit = 1;    // spade
    c1.value = 11;  // jack
    // another way to assign members 
    struct Card c2 = {3, 3, 0}; // value: 3 | suit: diamond | color: red
}