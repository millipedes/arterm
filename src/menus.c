/**
 * @file menus.c
 * @brief This file contains the terminal menus that are printed in particular
 * instances of the program
 * @author Matthew C. Lindeman
 * @date May 31, 2022
 * @bug None known
 * @todo Nothing
 */
#include "include/menus.h"

/**
 * This function prints an error message if a given file has an art that is too
 * large to be centered (i.e. the user provided art has a line of width >
 * MAX_LEN - 1)
 * @param width - the width that caused the error
 * @return  N/a
 */
void width_error_menu(int width) {
  // see conststants_macros.h for why '- 1' below
  fprintf(stderr, "[\t\tArt width: %d is larger than alignment: %d\t\t]\n",
      width, MAX_LEN - 1);
}
