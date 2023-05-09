#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024

/**
 * reduce - reduces the function
 */
int reduce_2(int *fd_from, int *fd_to, int *n_read)
{
	if (*n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(*fd_from);
		close(*fd_to);
		exit(98);
	}

	if (close(*fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", *fd_from);
		close(*fd_to);
		exit(100);
	}

	if (close(*fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", *fd_to);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0 on success, exit with code 97, 98, 99 or 100 on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t n_read;
	char buf[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	while ((n_read = read(fd_from, buf, BUFSIZE)) > 0)
	{
		if (write(fd_to, buf, n_read) != n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	reduce_2(&fd_from, &fd_to, &n_read);

	return (0);
}
