#include<stdio.h>
#include"include/quote_bank.h"
#include"include/art.h"

int main(void) {
  quote_bank * qb = quote_bank_from_file("resources/test.txt");
  quote_bank_dump_debug(qb);
  art * a = art_from_file("resources/art.txt");
  art_dump_debug(a);
  free_quote_bank(qb);
  free_art(a);
  return 0;
}
