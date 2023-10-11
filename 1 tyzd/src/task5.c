#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  uint64_t no = 1;
  uint8_t* no_ptr = (uint8_t*)&no;

  for (int i = 0; i < sizeof(no); i++) {
    printf("[%d] : 0x%02" PRIx8 "\n", i, no_ptr[i]);
  }

  return 0;
}