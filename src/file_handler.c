#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"

char *readFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file for reading");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    // printf("File size: %ld\n", fileSize);

    char *content = (char *)malloc(fileSize + 1);
    if (!content)
    {
        perror("Failed to allocate memory for the file content");
        fclose(file);
        return NULL;
    }

    fread(content, 1, fileSize, file);
    content[fileSize] = '\0';

    fclose(file);
    return content;
}

void writeFile(const char *filename, const char *data)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        perror("Failed to open file for writing");
        return;
    }

    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
}

void writeFrequencies(const char *filename, int freq[])
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        perror("Failed to open file for writing frequencies");
        return;
    }

    fwrite(freq, sizeof(int), 256, file);
    fclose(file);
}

void readFrequencies(const char *filename, int freq[])
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Failed to open file for reading frequencies");
        return;
    }

    fread(freq, sizeof(int), 256, file);
    fclose(file);
}