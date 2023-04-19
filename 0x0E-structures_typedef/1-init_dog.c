#include "dog.h"

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: Pointer to struct dog
 * @name: Pointer to char (name of the dog)
 * @age: Float (age of the dog)
 * @owner: Pointer to char (name of the dog's owner)
 *
 * Return: Nothing (void)
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		d = malloc(sizeof(struct dog));

		d->name = name;
		d->age = age;
		d->owner = owner;
	}
	else
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
