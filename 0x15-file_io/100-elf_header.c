#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - displays the information contained in the ELF header at the start
 * of an ELF file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments passed to the program
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
    int fd;
    ssize_t n;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
        exit(98);
    }
    n = read(fd, &header, sizeof(header));
    if (n != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
        exit(98);
    }
    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
        exit(98);
    }
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (n = 0; n < EI_NIDENT; n++)
        printf("%02x ", header.e_ident[n]);
    printf("\n");
    printf("  Class:                             ");
    printf("%s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("  Data:                              ");
    printf("%s\n", header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "2's complement, little endian");
    printf("  Version:                           %d %s\n",
           header.e_ident[EI_VERSION],
           header.e_ident[EI_VERSION] == EV_CURRENT ? "(current)" : "");
    printf("  OS/ABI: ");
    switch (header.e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD");
        break;
    default:
        printf("<unknown: %x>", header.e_ident[EI_OSABI]);
        break;
    }
    printf("\n");
    printf("  ABI Version: %d\n",
           header.e_ident[EI_ABIVERSION]);
    printf("  Type: ");
    switch (header.e_type)
    {
    case ET_NONE:
        printf("NONE (No file type)");
        break;
    case ET_REL:
        printf("REL (Relocatable file)");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)");
        break;
    case ET_CORE:
        printf("CORE (Core file)");
        break;
    default:
        printf("<unknown: %x>", header.e_type);
        break;
    }
    printf("\n");
    printf("  Entry point address: %#lx\n", header.e_entry);
}