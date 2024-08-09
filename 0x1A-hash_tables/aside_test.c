#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for collisions.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);

    /* Add colliding key-value pairs */
    hash_table_set(ht, "hetairas", "value1");
    hash_table_set(ht, "mentioner", "value2");
    hash_table_set(ht, "heliotropes", "value3");
    hash_table_set(ht, "neurospora", "value4");
    hash_table_set(ht, "depravement", "value5");
    hash_table_set(ht, "serafins", "value6");
    hash_table_set(ht, "stylist", "value7");
    hash_table_set(ht, "subgenera", "value8");
    hash_table_set(ht, "joyful", "value9");
    hash_table_set(ht, "synaphea", "value10");
    hash_table_set(ht, "redescribed", "value11");
    hash_table_set(ht, "urites", "value12");
    hash_table_set(ht, "dram", "value13");
    hash_table_set(ht, "vivency", "value14");

    /* Retrieve and print the values to check if collisions are handled */
    printf("hetairas: %s\n", hash_table_get(ht, "hetairas"));
    printf("mentioner: %s\n", hash_table_get(ht, "mentioner"));
    printf("heliotropes: %s\n", hash_table_get(ht, "heliotropes"));
    printf("neurospora: %s\n", hash_table_get(ht, "neurospora"));
    printf("depravement: %s\n", hash_table_get(ht, "depravement"));
    printf("serafins: %s\n", hash_table_get(ht, "serafins"));
    printf("stylist: %s\n", hash_table_get(ht, "stylist"));
    printf("subgenera: %s\n", hash_table_get(ht, "subgenera"));
    printf("joyful: %s\n", hash_table_get(ht, "joyful"));
    printf("synaphea: %s\n", hash_table_get(ht, "synaphea"));
    printf("redescribed: %s\n", hash_table_get(ht, "redescribed"));
    printf("urites: %s\n", hash_table_get(ht, "urites"));
    printf("dram: %s\n", hash_table_get(ht, "dram"));
    printf("vivency: %s\n", hash_table_get(ht, "vivency"));

    /* Clean up */
    hash_table_delete(ht);

    return (EXIT_SUCCESS);
}

