#ifndef ELF_H
#define ELF_H

typedef struct
{
    unsigned char e_ident[EI_NIDENT]; /* ident bytes */
    Elf32_Half e_type;                /* file type */
    Elf32_Half e_machine;             /* target machine */
    Elf32_Word e_version;             /* file version */
    Elf32_Addr e_entry;               /* start address */
    Elf32_Off e_phoff;                /* phdr file offset */
    Elf32_Off e_shoff;                /* shdr file offset */
    Elf32_Word e_flags;               /* file flags */
    Elf32_Half e_ehsize;              /* sizeof ehdr */
    Elf32_Half e_phentsize;           /* sizeof phdr */
    Elf32_Half e_phnum;               /* number phdrs */
    Elf32_Half e_shentsize;           /* sizeof shdr */
    Elf32_Half e_shnum;               /* number shdrs */
    Elf32_Half e_shstrndx;            /* shdr string index */
} Elf32_Ehdr;

#endif /* ELF_H */