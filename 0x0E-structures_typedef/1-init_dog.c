#include "dog.h"

/**
 * init_dog - Initializes a variable of type struct dog
 * @r: Pointer to struct dog
 * @name: Pointer to char (name of the dog)
 * @age: Float (age of the dog)
 * @owner: Pointer to char (name of the dog's owner)
 *
 * Return: Nothing (void)
 */
void init_dog(struct dog *r, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		r = malloc(sizeof(struct dog));
	}

	r->name = name;
	r->age = age;
	r->owner = owner;
}
