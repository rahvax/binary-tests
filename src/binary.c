#include <stdio.h>
#include <stdint.h>
#include "binary.h"

/* Escrever o arquivo binário */
int writeBinary(const char *filename, uint8_t *buffer, size_t count) {
  FILE *fp = fopen(filename, "wb");

  if (!fp) {
    perror("[x] erro ao criar arquivo: ");
    return -1;
  } else if (fwrite(buffer, sizeof(uint8_t), count, fp) != count) {
    perror("[x] erro ao escrever dados no arquivo: ");
    fclose(fp);
    return -1;
  }

  fclose(fp);
  return 0;
}

/* Ler o arquivo binário */
int readBinary(const char *filename, size_t count) {
  FILE *fp = fopen(filename, "rb");

  if (!fp) {
    perror("[x] erro ao ler o arquivo: ");
    return -1;
  }

  printf("\n[=] leitura de %s\n", filename);
  for (size_t x = 0; x < count; x++) {
    uint8_t byte;
    if (fread(&byte, sizeof(uint8_t), 1, fp) != 1) {
      perror("[x] erro ao ler dentro do arquivo: ");
      fclose(fp);
      return -1;
    }
    printf("-> %3zu: ", x);
    showBinary(byte);
    putchar('\n');
  }

  fclose(fp);
  return 0;
}

/* Imprimir formato convencional do binário */
void showBinary(uint8_t byte) {
  for (register int x = BSIZE; x >= 0; x--)
    putchar((byte & (1u << x)) ? '1' : '0');
  putchar('\n');
}

/* Ler decimais para servirem de prompt */
uint32_t setUint (const char *message, uint32_t min, uint32_t max) {
  uint32_t value = 0;
  int scanned = 0;

  do {
    printf("%s (%u-%u): ", message, min, max);
    scanned = scanf("%u", &value);
    while (getchar() != '\n');
  } while (scanned != 1 || value < min || value > max);

  return value;
}
