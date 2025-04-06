#include "minheap.h"

MinHeap_t *createMinHeap(int capacity)
{
    MinHeap_t *heap = (MinHeap_t *)malloc(sizeof(MinHeap_t));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node_t **)malloc(capacity * sizeof(Node_t *));
    return heap;
}

Node_t *createNode(char character, int frequency)
{
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

void insertMinHeap(MinHeap_t *heap, Node_t *node)
{
    int i = heap->size;
    heap->array[i] = node;
    heap->size++;

    while (i != 0 && heap->array[(i - 1) / 2]->frequency > heap->array[i]->frequency)
    {
        Node_t *temp = heap->array[i];
        heap->array[i] = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

Node_t *extractMin(MinHeap_t *heap)
{
    if (heap->size == 0)
        return NULL;

    Node_t *min = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    minHeapify(heap, 0);
    return min;
}

void minHeapify(MinHeap_t *heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;

    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx)
    {
        Node_t *temp = heap->array[idx];
        heap->array[idx] = heap->array[smallest];
        heap->array[smallest] = temp;
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(MinHeap_t *heap)
{
    for (int i = (heap->size - 1) / 2; i >= 0; i--)
        minHeapify(heap, i);
}