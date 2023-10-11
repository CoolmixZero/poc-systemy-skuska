#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *f = fopen("text.txt", "r");
  if (f == NULL) {
    printf("File dose not exist!\n");
    return 1;
  }

  int words_amount = 0;

  char chr;
  while ((chr = fgetc(f)) != EOF) {
    if (chr == ' ' || chr == '\n' || chr == '\t') {
      words_amount++;
    }
  }

  fclose(f);
  f = NULL;

  printf("Amount of words: %d.\n", words_amount);

  return 0;
}