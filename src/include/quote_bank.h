#ifndef QUOB_H
#define QUOB_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"constants_macros.h"

typedef struct QUOTE_BANK_T {
  char ** quotes;
  int quote_no;
} quote_bank;

quote_bank * init_quote_bank(void);
quote_bank * quote_bank_from_file(char * file_name);
void quote_bank_dump_debug(quote_bank * qb);
void free_quote_bank(quote_bank * qb);

#endif
