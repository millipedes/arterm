#include<stdio.h>
#include"include/terminal.h"

int main(void) {
  term * t = terminal_from_files("resources/test.txt", "resources/art.txt");
  print_terminal_art(t);
  free_term(t);
  return 0;
}
