#include"include/terminal.h"

term * init_term(art * a, quote_bank * qb) {
  term * t = calloc(1, sizeof(struct TERMINAL_T));
  t->a = a;
  t->qb = qb;
  return t;
}

term * terminal_from_files(char * quote_bank_fn, char * art_fn) {
  quote_bank * qb = quote_bank_from_file(quote_bank_fn);
  art * a = art_from_file(art_fn);
  term * t = init_term(a, qb);
  return t;
}

void print_terminal_art(term * t) {
  print_art(t->a);
  printf("%s", t->qb->quotes[pick_random_quote(t->qb)]);
}

void free_term(term * t) {
  if(t) {
    if(t->a)
      free_art(t->a);
    if(t->qb)
      free_quote_bank(t->qb);
    free(t);
  }
}
