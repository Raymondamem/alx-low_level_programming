#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: Pointer to struct the dog
 * @name: Pointer to the char (name of the dog)
 * @age: Float for (age of the dog)
 * @owner: Pointer to the char (name of the dog's owner)
 *
 * Return: Nothing (void)
 */
void init_dog(struct dog *r, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		d = malloc(sizeof(struct dog));
	}

	d->name = name;
	d->age = age;
	d->owner = owner;
}
