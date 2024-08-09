#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table to look into.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element, or NULL if key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *node;

    /* Check if the hash table or key is NULL */
    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    /* Get the index for the key */
    index = key_index((const unsigned char *)key, ht->size);

    /* Retrieve the node at the index */
    node = ht->array[index];

    /* Traverse the linked list at that index to find the key */
    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }

    /* Key not found */
    return (NULL);
}

