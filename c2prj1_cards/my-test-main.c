#include "cards.h"

int main(void) {
  card_t card;
  card.value = 2;
  card.suit = CLUBS;
  print_card(card);

  return 0;
}
