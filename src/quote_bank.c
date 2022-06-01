/**
 * @file quote_bank.c
 * @brief this file contains the functions relating to the quote bank
 * @author Matthew C. Lindeman
 * @date May 31, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/quote_bank.h"

/**
 * This function initializes a quote bank
 * @param N/a
 * @return qb - the new quote bank
 */
quote_bank * init_quote_bank(void) {
  quote_bank * qb = calloc(1, sizeof(struct QUOTE_BANK_T));
  qb->quote_no = 0;
  return qb;
}

/**
 * This function reads a quote bank from a file
 * @param file_name - the full path to the file
 * @return       qb - the quote bank
 */
quote_bank * quote_bank_from_file(char * file_name) {
  FILE * fp = fopen(file_name, "r");
  quote_bank * qb = init_quote_bank();
  char buf[MAX_LEN];
  size_t len;

  while(fgets(buf, MAX_LEN, fp)) {
    len = strnlen(buf, MAX_LEN);
    // If there are no quotes set up the struct
    if(qb->quote_no == 0) {
      qb->quote_no++;
      qb->quotes = calloc(qb->quote_no, sizeof(char *));
      qb->quotes[qb->quote_no - 1] = calloc(len + 1, sizeof(char));
      strncpy(qb->quotes[qb->quote_no - 1], buf, len);
    } else if(strncmp(QUOTE_DELIM, buf, MAX_LEN)) {
      if(qb->quotes[qb->quote_no - 1]) {
        // At most the max quote length, not just MAX_LEN
        len += strnlen(qb->quotes[qb->quote_no - 1], MAX_Q_LEN);
        qb->quotes[qb->quote_no - 1] = realloc(qb->quotes[qb->quote_no - 1],
            (len + 1) * sizeof(char));
      } else {
        qb->quotes[qb->quote_no - 1] = calloc(len + 1, sizeof(char));
      }
      strncat(qb->quotes[qb->quote_no - 1], buf, MAX_LEN);
    } else {
      qb->quote_no++;
      qb->quotes = realloc(qb->quotes, qb->quote_no * sizeof(char *));
      /**
       * If this is not set (i.e. the potential for more quotes) then line 35
       * depends on uninitialized value
       */
      qb->quotes[qb->quote_no - 1] = NULL;
    }
  }
  /**
   * Because in the loop we need to be ready to accept one more quote we need to
   * decerment here
   */
  qb->quote_no--;
  fclose(fp);
  return qb;
}

/**
 * This function is used for debugging purposes
 * @param   qb - the quote bank to be debugged
 * @return N/a
 */
void quote_bank_dump_debug(quote_bank * qb) {
  for(int i = 0; i < qb->quote_no; i++) {
    printf("Quote %d:\n", i);
    printf("`%s`\n", qb->quotes[i]);
    printf("--------------------------------\n");
  }
}

/**
 * This function prints out a
 * @param
 * @return
 */
void print_random_quote(quote_bank * qb) {
  int rand_index = pick_random_quote(qb);
  int buffer = 0;
  size_t len = strnlen(qb->quotes[rand_index], MAX_Q_LEN);
  buffer = (MAX_LEN - 1 - len) / 2;
  if(buffer > 0) {
    // Boarder above
    print_char(' ', buffer);
    print_char('*', len);
    printf("\n");
    
    // Buffer
    print_char(' ', buffer);
    printf("%s", qb->quotes[rand_index]);
    // Boarder below
    print_char(' ', buffer);
    print_char('*', len);
    printf("\n");
  } else {
    print_char('*', MAX_LEN - 1);
    printf("\n");
    printf("%s", qb->quotes[rand_index]);
    print_char('*', MAX_LEN - 1);
    printf("\n");
  }
}

void print_char(char c, int qty) {
  for(int i = 0; i < qty; i++)
    printf("%c", c);
}

int pick_random_quote(quote_bank * qb) {
  time_t tim;
  srand((unsigned) time(&tim));
  return rand() % qb->quote_no;
}

/**
 * This function frees a quote bank
 * @param   qb - the quote bank to be freed
 * @return N/a
 */
void free_quote_bank(quote_bank * qb) {
  if(qb) {
    if(qb->quotes) {
      for(int i = 0; i < qb->quote_no; i++) {
        if(qb->quotes[i]) {
          free(qb->quotes[i]);
        }
      }
      free(qb->quotes);
    }
    free(qb);
  }
}
