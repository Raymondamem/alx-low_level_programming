#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024

void check_argc(int argc);
int open_file_from(char *file_from);
int open_file_to(char *file_to);
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to);
void close_files(int fd_from, int fd_to);

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

	check_argc(argc);

	fd_from = open_file_from(argv[1]);
	fd_to = open_file_to(argv[2]);

	copy_file(fd_from, fd_to, argv[1], argv[2]);

	close_files(fd_from, fd_to);

	return (0);
}

/**
 * check_argc - Check if the number of arguments is correct
 * @argc: Number of arguments
 */
void check_argc(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_file_from - Open the file to copy from
 * @file_from: Name of the file to copy from
 *
 * Return: File descriptor of the opened file
 */
int open_file_from(char *file_from)
{
	int fd_from;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	return (fd_from);
}

/**
 * open_file_to - Open the file to copy to
 * @file_to: Name of the file to copy to
 *
 * Return: File descriptor of the opened file
 */
int open_file_to(char *file_to)
{
	int fd_to;

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	return (fd_to);
}

/**
 * copy_file - Copy the content of a file to another file
 * @fd_from: File descriptor of the file to copy from
 * @fd_to: File descriptor of the file to copy to
 * @file_from: Name of the file to copy from
 * @file_to: Name of the file to copy to
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t n_read;
	char buf[BUFSIZE];

	while ((n_read = read(fd_from, buf, BUFSIZE)) > 0)
	{
		if (write(fd_to, buf, n_read) != n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
 * close_files - Close two files
 * @fd_from: File descriptor of the first file
 * @fd_to: File descriptor of the second file
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}
