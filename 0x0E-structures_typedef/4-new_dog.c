#include "dog.h"
#include <stdlib.h>

/**
 * _strcpy - copy string from one source to another
 * @dest: where to copy the string to
 * @src: from where to copy the string
 * Return: point to the @dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - count the length of a string
 * @s: the string to count
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * new_dog - creates a new dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner's name
 * Return: new Dog or NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dp = malloc(sizeof(dog_t));

	if (dp == NULL)
	{
		return (NULL);
	}
	dp->name = malloc(_strlen(name) + 1);
	if (dp->name == NULL)
	{
		free(dp);
		return (NULL);
	}
	_strcpy(dp->name, name);

	dp->owner = malloc(_strlen(owner) + 1);
	if (dp->owner == NULL)
	{
		free(dp->name);
		free(dp);
		return (NULL);
	}
	_strcpy(dp->owner, owner);

	dp->age = age;
	return (dp);
}
