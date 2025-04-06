#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

Node_t *buildHuffmanTree(int freq[])
{
    MinHeap_t *heap = createMinHeap(MAX_CHAR);

    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (freq[i] > 0)
            insertMinHeap(heap, createNode((char)i, freq[i]));
    }

    buildMinHeap(heap);

    while (heap->size > 1)
    {
        Node_t *left = extractMin(heap);
        Node_t *right = extractMin(heap);

        Node_t *merged = createNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        insertMinHeap(heap, merged);
    }

    Node_t *root = extractMin(heap);
    free(heap->array);
    free(heap);
    return root;
}

void generateCodes(Node_t *root, char *code, int depth, Huffman_t codes[])
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        code[depth] = '\0';
        strcpy(codes[(unsigned char)root->character].bits, code); // Make sure 'bits' is valid
        // printf("Character: %c, Code: %s\n", root->character, codes[(unsigned char)root->character].bits);
        return;
    }

    code[depth] = '0';
    generateCodes(root->left, code, depth + 1, codes);

    code[depth] = '1';
    generateCodes(root->right, code, depth + 1, codes);
}

void compressFile(const char *inputPath, const char *outputPath, Huffman_t codes[])
{
    FILE *input = fopen(inputPath, "r");
    FILE *output = fopen(outputPath, "wb");

    if (!input || !output)
    {
        perror("File error");
        return;
    }

    int ch;
    while ((ch = fgetc(input)) != EOF)
    {
        if (codes[(unsigned char)ch].bits[0] == '\0')
            continue;

        // printf("Character: %c, Code: %s\n", ch, codes[(unsigned char)ch].bits);
        fputs(codes[(unsigned char)ch].bits, output);
    }

    fclose(input);
    fclose(output);
}

void decompressFile(const char *inputPath, const char *outputPath, Node_t *treeRoot)
{
    FILE *input = fopen(inputPath, "r");
    FILE *output = fopen(outputPath, "w");

    if (!input || !output)
    {
        perror("File error");
        return;
    }

    Node_t *current = treeRoot;
    int ch;

    while ((ch = fgetc(input)) != EOF)
    {
        if (ch == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right)
        {
            fputc(current->character, output);
            current = treeRoot;
        }
    }

    fclose(input);
    fclose(output);
}

void freeHuffmanTree(Node_t *root)
{
    if (!root)
        return;

    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}