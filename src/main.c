#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
#include "minheap.h"
#include "file_handler.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    char *inputPath = argv[2];
    char *outputPath = argv[3];

    if (strcmp(argv[1], "compress") == 0)
    {
        printf("Compressing file: %s\n", inputPath);

        char *fileContent = readFile(inputPath);
        if (fileContent == NULL)
        {
            return 1;
        }

        int freq[MAX_CHAR] = {0};
        for (int i = 0; fileContent[i] != '\0'; i++)
        {
            unsigned char ch = (unsigned char)fileContent[i];
            freq[ch]++;
        }

        // for (int i = 0; i < MAX_CHAR; i++)
        // {
        //     if (freq[i] > 0)
        //     {
        //         printf("Character '%c' with frequency %d\n", i, freq[i]);
        //     }
        // }

        Node_t *root = buildHuffmanTree(freq);

        Huffman_t huffmanCodes[MAX_CHAR];
        char code[MAX_CHAR];
        generateCodes(root, code, 0, huffmanCodes);

        compressFile(inputPath, outputPath, huffmanCodes);

        writeFrequencies("frequencies.bin", freq);

        freeHuffmanTree(root);
        free(fileContent);

        printf("Compression complete. Output file: %s\n", outputPath);
    }
    else if (strcmp(argv[1], "decompress") == 0)
    {
        printf("Decompressing file: %s\n", inputPath);

        int freq[MAX_CHAR] = {0};
        readFrequencies("frequencies.bin", freq);

        Node_t *root = buildHuffmanTree(freq);

        decompressFile(inputPath, outputPath, root);

        freeHuffmanTree(root);

        printf("Decompression complete. Output file: %s\n", outputPath);
    }
    else
    {
        printf("Invalid option. Use 'compress' or 'decompress'.\n");
        return 1;
    }

    return 0;
}
