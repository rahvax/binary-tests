#ifndef _BINARY_H
#define _BINARY_H
#include <stdio.h>
#include <stdint.h>
#define BSIZE 8
/* Escrever o arquivo binário */
int writeBinary (const char *filename, uint8_t *buffer, size_t count);
/* Ler o arquivo binário */
int readBinary(const char *filename, size_t count);
/* Imprimir formato convencional do binário */
void showBinary(uint8_t byte);
/* Definir os UINT32 que serão usados */
uint32_t setUint(const char *message, uint32_t min, uint32_t max);
#endif
