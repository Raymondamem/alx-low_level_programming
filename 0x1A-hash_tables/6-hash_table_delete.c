#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node;
    hash_node_t *temp;

    if (ht == NULL)
        return;

    /* Free each linked list in the hash table array */
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = temp;
        }
    }

    /* Free the array of pointers to hash nodes */
    free(ht->array);

    /* Free the hash table structure itself */
    free(ht);
}
