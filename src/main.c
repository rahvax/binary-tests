/*
  Testes Aleatórios - Binário
  - Rahvax
*/
#include "binary.h"
#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint8_t dados[] = {0x88, 0x43, 0xFF, 0x00};
  printf("[*]: iniciando testes\n[!]: criando arquivo\n");
  writeBinary("teste.dat", dados, sizeof(dados));
  printf("[!]: lendo arquivo\n\n");
  readBinary("teste.dat");
  return 0;
}
