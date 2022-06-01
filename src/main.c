/**
 * @file main.c
 * @brief the entry point of the code
 * @author Matthew C. Lindeman
 * @date June 1, 2022
 * @bug None known
 * @todo Nothing
 */
#include<stdio.h>
#include"include/terminal.h"

int main(void) {
  term * t = terminal_from_files("resources/test.txt", "resources/art.txt");
  print_terminal_art(t);
  free_term(t);
  return 0;
}
