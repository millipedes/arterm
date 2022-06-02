/**
 * @file terminal.h
 * @brief this file contains the function definitions for terminal.c
 * @author Matthew C. Lindeman
 * @date June 1, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef TER_H
#define TER_H

#include "art.h"
#include "quote_bank.h"

typedef struct TERMINAL_T {
  art * art;
  quote_bank * qb;
} term;

term * init_term(art * a, quote_bank * qb);
term * terminal_from_files(char * quote_bank_fn, char * art_fn);
void print_terminal_art(term * t);
void free_term(term * t);

#endif
