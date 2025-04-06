#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char character;
    int frequency;
    struct Node *left, *right;
} Node_t;

typedef struct MinHeap
{
    int size;
    int capacity;
    Node_t **array; // array of pointers to Node_t
} MinHeap_t;

MinHeap_t *createMinHeap(int capacity);
Node_t *createNode(char character, int frequency);
void insertMinHeap(MinHeap_t *minHeap, Node_t *node);
Node_t *extractMin(MinHeap_t *minHeap);
void minHeapify(MinHeap_t *minHeap, int idx);
void buildMinHeap(MinHeap_t *minHeap);

#endif