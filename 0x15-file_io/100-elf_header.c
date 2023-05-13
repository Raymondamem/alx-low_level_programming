#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

void print_error(const char *message)
{
    for (int i = 0; message[i] != '\0'; i++)
        _putchar(message[i]);
    _putchar('\n');
    exit(98);
}

void print_elf_header(const Elf64_Ehdr *header)
{
    for (int i = 0; i < EI_NIDENT; i++)
        _putchar(header->e_ident[i]);
    _putchar('\n');
    switch (header->e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        _putchar('3');
        break;
    case ELFCLASS64:
        _putchar('6');
        break;
    default:
        _putchar('?');
        break;
    }
    _putchar('\n');
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        _putchar('l');
        break;
    case ELFDATA2MSB:
        _putchar('b');
        break;
    default:
        _putchar('?');
        break;
    }
    _putchar('\n');
    for (int i = 0; i < EI_VERSION; i++)
        _putchar(header->e_ident[i]);
    _putchar('\n');
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        for (int i = 0; "UNIX - System V"[i] != '\0'; i++)
            _putchar("UNIX - System V"[i]);
        break;
    case ELFOSABI_NETBSD:
        for (int i = 0; "UNIX - NetBSD"[i] != '\0'; i++)
            _putchar("UNIX - NetBSD"[i]);
        break;
    case ELFOSABI_SOLARIS:
        for (int i = 0; "UNIX - Solaris"[i] != '\0'; i++)
            _putchar("UNIX - Solaris"[i]);
        break;
    default:
        for (int i = 0; "<unknown>"[i] != '\0'; i++)
            _putchar("<unknown>"[i]);
        break;
    }
    _putchar('\n');
    for (int i = 0; i < EI_ABIVERSION; i++)
        _putchar(header->e_ident[i]);
    _putchar('\n');
    switch (header->e_type)
    {
    case ET_NONE:
        for (int i = 0; "NONE (Unknown type)"[i] != '\0'; i++)
            _putchar("NONE (Unknown type)"[i]);
        break;
    case ET_REL:
        for (int i = 0; "REL (Relocatable file)"[i] != '\0'; i++)
            _putchar("REL (Relocatable file)"[i]);
        break;
    case ET_EXEC:
        for (int i = 0; "EXEC (Executable file)"[i] != '\0'; i++)
            _putchar("EXEC (Executable file)"[i]);
        break;
    case ET_DYN:
        for (int i = 0; "DYN (Shared object file)"[i] != '\0'; i++)
            _putchar("DYN (Shared object file)"[i]);
        break;
    default:
        for (int i = 0; "<unknown>"[i] != '\0'; i++)
            _putchar("<unknown>"[i]);
        break;
    }
    printf("\nEntry point address: 0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error("Error opening file");
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        print_error("Error reading ELF header");
    }

    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        print_error("Error seeking file");
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}