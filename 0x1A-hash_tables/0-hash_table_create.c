#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *hash_t;
    unsigned long int i;

    /* Allocate memory for the hash table structure */
    hash_t = malloc(sizeof(hash_table_t));
    if (hash_t == NULL)
        return (NULL);

    /* Allocate memory for the array of pointers to hash nodes */
    hash_t->array = malloc(sizeof(hash_node_t *) * size);
    if (hash_t->array == NULL)
    {
        free(hash_t);
        return (NULL);
    }

    /* Initialize each element of the array to NULL */
    for (i = 0; i < size; i++)
        hash_t->array[i] = NULL;

    /* Set the size of the hash table */
    hash_t->size = size;

    return (hash_t);
}
