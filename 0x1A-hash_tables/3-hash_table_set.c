#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add or update the key/value pair to.
 * @key: The key, cannot be an empty string.
 * @value: The value associated with the key. It must be duplicated.
 * 
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *temp;
    char *dup_value, *dup_key;

    if (ht == NULL || key == NULL || value == NULL || *key == '\0')
        return (0);

    dup_value = strdup(value);
    if (dup_value == NULL)
        return (0);

    dup_key = strdup(key);
    if (dup_key == NULL)
    {
        free(dup_value);
        return (0);
    }

    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];

    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = dup_value;
            free(dup_key);
            return (1);
        }
        temp = temp->next;
    }

    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
    {
        free(dup_value);
        free(dup_key);
        return (0);
    }

    new_node->key = dup_key;
    new_node->value = dup_value;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
