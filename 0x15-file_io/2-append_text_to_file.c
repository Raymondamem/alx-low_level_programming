#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

/**
 * append_text_to_file - appends to file
 * @filename: file to append
 * @text_content: text to append
 * Return: returns of err or succ
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
		if (write(fd, text_content, len) == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
