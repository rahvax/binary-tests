#ifndef _BINARY_H
#define _BINARY_H
#include <stdio.h>
#include <stdint.h>
/* Create a Binary File */
int writeBinary (const char *filename, uint8_t *bytes, size_t size);
/* Read a Binary File*/
int readBinary (const char *filename);
#endif
