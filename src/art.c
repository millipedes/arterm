/**
 * @file art.c
 * @brief This file contains the functions related to the art struct
 * @author Matthew C. Lindeman
 * @date May 31, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/art.h"

art * init_art(void) {
  art * a = calloc(1, sizeof(struct ART_T));
  a->art = NULL;
  a->w = 0;
  a->h = 0;
  return a;
}

art * art_from_file(char * file_name) {
  FILE * fp = fopen(file_name, "r");
  art * a = init_art();
  char buf[MAX_LEN];
  size_t len;

  while(fgets(buf, MAX_LEN, fp)) {
    len = strnlen(buf, MAX_LEN);
    if(a->w < (int)len) {
    }
  }
  return NULL;
}

void free_art(art * a) {
  if(a) {
    if(a->art) {
      for(int i = 0; i < a->h; i++) {
        if(a->art[i]) {
          free(a->art[i]);
        }
      }
      free(a->art);
    }
    free(a);
  }
}
