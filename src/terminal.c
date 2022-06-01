/**
 * @file terminal.c
 * @brief this file contains the functions relating to the whole of what is
 * printed to the terminal (i.e. the term struct)
 * @author Matthew C. Lindeman
 * @date June 1, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/terminal.h"

/**
 * This function initializes a terminal struct
 * @param  a - the art to be associated with the terminal
 * @param qb - the quote bank to be associated with the terminal
 * @return t - the new terminal struct with not much initialized
 */
term * init_term(art * a, quote_bank * qb) {
  term * t = calloc(1, sizeof(struct TERMINAL_T));
  t->a = a;
  t->qb = qb;
  return t;
}

/**
 * This function takes two file paths in and makes a terminal object from them
 * @param quote_bank_fn - the file path to the quotes
 * @param        art_fn - the file path to the art
 * @return            t - the terminal struct
 */
term * terminal_from_files(char * quote_bank_fn, char * art_fn) {
  quote_bank * qb = quote_bank_from_file(quote_bank_fn);
  art * a = art_from_file(art_fn);
  term * t = init_term(a, qb);
  return t;
}

/**
 * This function prints the whole of the terminal structure (art and the quote)
 * @param    t - the terminal struct
 * @return N/a
 */
void print_terminal_art(term * t) {
  print_art(t->a);
  print_random_quote(t->qb);
}

/**
 * This function frees a terminal structure
 * @param    t - the terminal structure to be printed
 * @return N/a
 */
void free_term(term * t) {
  if(t) {
    if(t->a)
      free_art(t->a);
    if(t->qb)
      free_quote_bank(t->qb);
    free(t);
  }
}
