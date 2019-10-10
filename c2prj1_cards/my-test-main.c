#include "cards.h"

int main(void) {
  card_t card;
  card.value = 2;
  card.suit = CLUBS;
  print_card(card);

  card_t card2;
  card2 = card_from_letters('2','h');
  print_card(card2);

  return 0;
}
