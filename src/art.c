/**
 * @file art.c
 * @brief This file contains the functions related to the art struct
 * @author Matthew C. Lindeman
 * @date May 31, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/art.h"

/**
 * This function initializes an art struct
 * @param N/a
 * @return  a - the new art struct
 */
art * init_art(void) {
  art * a = calloc(1, sizeof(struct ART_T));
  a->art = NULL;
  a->w = 0;
  a->h = 0;
  return a;
}

/**
 * This function will make an art struct from a file path with max width of
 * MAX_LEN
 * @param file_name - the name of the file
 * @return        a - the art struct
 */
art * art_from_file(char * file_name) {
  FILE * fp = fopen(file_name, "r");
  art * a = init_art();
  char buf[MAX_LEN];
  size_t len;

  while(fgets(buf, MAX_LEN, fp)) {
    len = strnlen(buf, MAX_LEN);
    // If the art is too wide print error message and exit
    if(a->w > MAX_LEN) {
      width_error_menu(a->w);
      exit(1);
    }
    // We want to keep track of largest width
    if(a->w < (int)len)
      a->w = (int)len;

    // Only allocate memory that we need
    a->h++;
    if(a->h == 1) {
      a->art = calloc(a->h, sizeof(char *));
    } else {
      a->art = realloc(a->art, a->h * sizeof(char *));
    }
    a->art[a->h - 1] = calloc(len + 1, sizeof(char));
    strncpy(a->art[a->h - 1], buf, len);
  }
  fclose(fp);
  return a;
}

/**
 * This function prints the user art
 * @param    a - the art
 * @return N/a
 */
void print_art(art * a) {
  size_t len = 0;
  int buffer = 0;
  for(int i = 0; i < a->h; i++) {
    len = strnlen(a->art[i], MAX_LEN);
    buffer = (MAX_LEN - 2 - len) / 2;
    for(int i = 0; i < buffer; i++)
      printf(" ");
    printf("%s", a->art[i]);
  }
}

/**
 * This function is used in the debugging process
 * @param    a - the art to be debugged
 * @return N/a
 */
void art_dump_debug(art * a) {
  printf("Art:\n");
  for(int i = 0; i < a->h; i++) {
    printf("`%s`\n", a->art[i]);
  }
  printf("------------------------------\n");
}

/**
 * This function frees an art struct
 * @param    a - the art struct to be freed
 * @return N/a
 */
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
