# asm-z80
an assembler for the Z80 created for Softec/Inova in 1985 based on text pattern matching

This version is the 1988 release that had been ported from QNX to MS-DOS and compiled with Borland Turbo C

## Files

*asmz80.c* is the actual assembler and it includes *table.c* with all the
instructions and address modes explicitly listed. No makefile is needed as
just compiling the first file should be good enough.

*install.c* was our version of the "app store". It could take an existing
binary installation and upgrade it using a difference file. This file could
be made publicly available (via a BBS, bulletin board system, for example)
but only existing clients would be able to use it. Of course, if somebody
got a pirated copy of any version they would then be able to upgrade forever.

Several helper files allow "install" to work. *funcoes.asm* is a tiny
library to make prettier MS-DOS screens. *geradif.c* creates the difference
file given two versions of some binary. *leia_me* is the actual manual in
a custom not quite text format that is interpreted by *leia.asm*.

Here is part of the README file in Portuguese distributed with the program:

## Como Executar o ASMZ80

    ASMZ80
    ASMZ80 FONTE
    ASMZ80 FONTE;
    ASMZ80 FONTE,
    ASMZ80 FONTE,,
    ASMZ80 FONTE,SAIDA
    ASMZ80 FONTE,SAIDA,
    ASMZ80 FONTE,SAIDA;
    ASMZ80 FONTE,SAIDA,LISTAGEM

## Como usar as opções

/Oexpressão - OFFSET

/Rexpressão - RELOCATE
