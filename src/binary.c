#include <stdio.h>
#include <stdint.h>
#include "binary.h"
/* Create a Binary File */
int writeBinary(const char *filename, uint8_t *bytes, size_t size) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    perror("[x]: erro ao criar o binário:");
    return -1;
  }
  fwrite(bytes, sizeof(uint8_t), size, fp);
  fclose(fp);
  return 0;
}

/* Read a Binary File*/
int readBinary(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  uint8_t byte;
  int byteIndex = 0;
  if (!fp) {
    
    perror("[x]: erro ao tentar ler o arquivo:");
    return -1;
  }
  
  while (fread(&byte, sizeof(uint8_t), 1, fp) == 1) {
    printf("-> byte: %d: 0x%02X\n", byteIndex, byte);
    printf("-> ativas:");
    if (byte & 0x80)
      printf("128 ");
    if (byte & 0x40)
      printf("64 ");
    if (byte & 0x20)
      printf("32 ");
    if (byte & 0x10)
      printf("16 ");
    if (byte & 0x08)
      printf("8 ");
    if (byte & 0x04)
      printf("4 ");
    if (byte & 0x02)
      printf("2 ");
    if (byte & 0x01)
      printf("1 ");
    printf("\n");
    byteIndex++;
  }
  fclose(fp);
  return 0;
}
