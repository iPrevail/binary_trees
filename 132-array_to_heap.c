#include "binary_trees.h"

/**
 * array_to_heap - transmogrifies array into a majestic Max Binary Heap
 * @array: points to the array's inception
 * @size: holds the essence of the array's magnitude
 *
 * Return: pointer to the sovereign Binary Heap's genesis
 *           NULL if the conjuration fails
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
