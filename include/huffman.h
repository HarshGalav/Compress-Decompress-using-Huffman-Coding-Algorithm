#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "minheap.h"

#define MAX_CHAR 256

typedef struct
{
    char bits[MAX_CHAR];
} Huffman_t;

Node_t *buildHuffmanTree(int freq[]);
void generateCodes(Node_t *root, char *code, int depth, Huffman_t codes[]);
void compressFile(const char *inputPath, const char *outputPath, Huffman_t codes[]);
void decompressFile(const char *inputPath, const char *outputPath, Node_t *treeRoot);
void freeHuffmanTree(Node_t *root);

#endif