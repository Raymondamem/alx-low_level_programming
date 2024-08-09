#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - Create a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the created hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t *));
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Add or update an element in the hash table.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 if succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *temp, *prev, *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = strdup(value);
            if (temp->value == NULL)
                return (0);
            return (1);
        }
        temp = temp->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    new_node->snext = NULL;
    new_node->sprev = NULL;

    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        current = ht->shead;
        while (current != NULL && strcmp(current->key, key) < 0)
        {
            prev = current;
            current = current->snext;
        }
        if (current == ht->shead)
        {
            new_node->snext = ht->shead;
            ht->shead->sprev = new_node;
            ht->shead = new_node;
        }
        else
        {
            new_node->snext = current;
            new_node->sprev = prev;
            if (current != NULL)
                current->sprev = new_node;
            prev->snext = new_node;
            if (current == NULL)
                ht->stail = new_node;
        }
    }

    return (1);
}

/**
 * shash_table_get - Retrieve the value associated with a key.
 * @ht: The hash table.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];

    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Print the hash table in sorted order.
 * @ht: The hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->snext != NULL)
            printf(", ");
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Print the hash table in reverse sorted order.
 * @ht: The hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->sprev != NULL)
            printf(", ");
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Delete the hash table.
 * @ht: The hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *node, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);

    node = ht->shead;
    while (node != NULL)
    {
        temp = node;
        node = node->snext;
        free(temp->key);
        free(temp->value);
        free(temp);
    }

    free(ht);
}

