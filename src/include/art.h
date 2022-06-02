/**
 * @file art.h
 * @brief This file contains the function definitions for art.c
 * @author Matthew C. Lindeman
 * @date May 31, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef ART_H
#define ART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants_macros.h"
#include "menus.h"

typedef struct ART_T {
  char ** art;
  int max_width; // only garenteed to be the largest width
  int height;   // height
} art;

art * init_art(void);
art * art_from_file(char * file_name);
void print_art(art * a);
void art_dump_debug(art * a);
void free_art(art * a);

#endif
