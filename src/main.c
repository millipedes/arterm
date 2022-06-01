/**
 * @file main.c
 * @brief the entry point of the code
 * @author Matthew C. Lindeman
 * @date June 1, 2022
 * @bug None known
 * @todo Nothing
 */
#include<stdio.h>
#include<stdlib.h>
#include"include/terminal.h"

int main(int argc, char * argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage:\n./executable path_to/quote.txt path_to/art.txt\n");
    exit(1);
  }
  term * t = terminal_from_files(argv[1], argv[2]);
  print_terminal_art(t);
  free_term(t);
  return 0;
}
