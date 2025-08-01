/*
  Testes Aleatórios - Binário
  - Rahvax
*/
#include "binary.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define FILETEST "teste.dat"

int main(void) {
  uint32_t nBytes = setUint("Bytes a gerar", 1, 10);
  uint8_t *buffer = malloc(nBytes * sizeof(*buffer));
  
  if (!buffer) {
    fprintf(stderr, "[x] falha na alocação de memória\n");
    return EXIT_FAILURE;
  }

  for (uint32_t i = 0; i < nBytes; ++i) {
    char msg[64];
    snprintf(msg, sizeof(msg), "valor-byte %u", i);
    buffer[i] = (uint8_t)setUint(msg, 0, 255);
  }

  if (writeBinary(FILETEST, buffer, nBytes) != 0) {
    free(buffer);
    return EXIT_FAILURE;
  }

  printf("\n[+] %s criado (%u bytes)\n", FILETEST, nBytes);
  if (readBinary(FILETEST, nBytes) != 0) {
    free(buffer);
    return EXIT_FAILURE;
  }

  free(buffer);
  return 0;
}
