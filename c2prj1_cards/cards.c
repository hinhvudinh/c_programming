#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((2 <= c.value) & (c.value <= VALUE_ACE));
  assert((SPADES <= c.suit) & (c.suit <= CLUBS));

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  default: return "";
  }
}

char value_letter(card_t c) {
  switch (c.value){
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  case 10: return '0';
  case 11: return 'J';
  case 12: return 'Q';
  case 13: return 'K';
  case 14: return 'A';
  default:  return '?';
  }

}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return '?';
  }
  
}

void print_card(card_t c) {
  assert_card_valid(c);
  printf("%c%c",value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;

  switch(value_let){
  case '2': temp.value = 2;
  case '3': temp.value = 3;
  case '4': temp.value = 4;
  case '5': temp.value = 5;
  case '6': temp.value = 6;
  case '7': temp.value = 7;
  case '8': temp.value = 8;
  case '9': temp.value = 9;
  case '0': temp.value = 10;
  case 'J': temp.value = VALUE_JACK;
  case 'Q': temp.value = VALUE_QUEEN;
  case 'K': temp.value = VALUE_KING;
  case 'A': temp.value = VALUE_ACE;
  default:
    printf("Something wrong (value_let)\n");
    exit(EXIT_FAILURE);
  }

  switch(suit_let){
  case 's': temp.suit = SPADES;
  case 'h': temp.suit = HEARTS;
  case 'd': temp.suit = DIAMONDS;
  case 'c': temp.suit = CLUBS;
  default:
    printf("Something wrong (suit_let)\n");
    exit(EXIT_FAILURE);
  }
  
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c%13 + 1;
  temp.suit = c/13;
  return temp;
}
