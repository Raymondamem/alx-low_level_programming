#include "main.h"
#include <stdlib.h>

/**
 * count_words - count number of words from a string
 * @str: strubg to count
 * Return: number of words in string
 */
int count_words(char *str)
{
	int i, count;

	for (i = 0, count = 0; str[i] != '\0'; i++)
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	return (count);
}

/**
 * get_word - get word and loop throught it
 * @str: word to loop over
 * @index: index
 * Return: pointer
 */
char *get_word(char *str, int *index)
{
	char *word;
	int i, j, len;

	for (i = *index; str[i] == ' '; i++)
		;
	for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
		;
	len = j - i;
	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	for (j = 0; j < len; j++)
		word[j] = str[i + j];
	word[j] = '\0';
	*index = i + len;
	return (word);
}

/**
 * strtow - makes string to array of words
 * @str: string to convert
 * Return: pointer to new Array
 */
char **strtow(char *str)
{
	char **words;
	int i, j, count;

	if (str == NULL || str[0] == '\0')
	{
		return (NULL);
	}

	count = count_words(str);
	if (count == 0)
	{
		return (NULL);
	}

	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	for (i = 0, j = 0; i < count; i++)
	{
		words[i] = get_word(str, &j);
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(words[j]);
			}
			free(words);
			return (NULL);
		}
	}
	words[i] = NULL;
	return (words);
}
