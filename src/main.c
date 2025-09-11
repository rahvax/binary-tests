/*
  Testes Aleatórios - Binário
  - Rahvax
*/
#include "binary.h"
#include <stdint.h>
#include <stdlib.h>
#define FILETEST "teste.dat"

int main(void) {
  uint32_t nbytes = setUint("N. bytes", 1, 10);
  uint8_t *buffer = malloc(nbytes * sizeof(*buffer));

  if (!buffer) {
    perror("[X] erro na alocação de memória");
    return -1;
  }
  for (uint32_t i = 0; i < nbytes; ++i) {
    char msg[64];
    snprintf(msg, sizeof(msg), "valor %u", i);
    buffer[i]=(uint8_t)setUint(msg, 0, 255);
  }

  if (writeBinary(FILETEST, buffer, nbytes) != 0) {
    perror("[X] erro ao escrever o arquivo");
    free(buffer);
    return -1;
  }
  printf("[!] criado o arquivo de binário!\n");
  if (readBinary(FILETEST, nbytes) != 0) {
    perror("[X] erro ao ler o arquivo");
    free(buffer);
    return -1;
  }
  free(buffer);
  return 0;
}
