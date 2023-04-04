/**
 * _memcpy - copy memory area
 * @dest: pointer to the destination array where data is to be copied
 * @src: pointer to the source of data to be copied
 * @n: number of bytes to be copied
 *
 * Return: a pointer to the destination array
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
