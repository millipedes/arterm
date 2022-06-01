#include<stdio.h>
#include"include/quote_bank.h"

int main(void) {
  quote_bank * qb = quote_bank_from_file("resources/test.txt");
  quote_bank_dump_debug(qb);
  free_quote_bank(qb);
  return 0;
}
