#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>

char *readFile(const char *filename);
void writeFile(const char *filename, const char *data);
void writeFrequencies(const char *filename, int freq[]);
void readFrequencies(const char *filename, int freq[]);

#endif
