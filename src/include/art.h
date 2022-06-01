#ifndef ART_H
#define ART_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./constants_macros.h"

typedef struct ART_T {
  char ** art;
  int w; // only garenteed to be the largest width
  int h; // height
} art;

art * init_art(void);
art * art_from_file(char * file_name);
void free_art(art * a);

#endif
