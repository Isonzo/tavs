# Tavs
A simple utility to open C source and header files in pairs in Neovim.
Give some files, Tavs match the ones with the same name.

## Prerequisites
- Neovim
- C compiler to compile by source (makefile uses gcc, but it's very simple to edit)
- A globbing shell (such as bash, zsh, ksh, csh, and anything that expands a '*')

## Installation
### Manual
1. Compile the single c file with something like: `$ gcc main.c -o tavs`
2. Add the resulting binary to your PATH.
### Makefile
`make install CC=<compiler> INSTALL_PATH=<path to PATH>`
For example, if I wanted to use `clang` and put it in my system path, I would do  
`make install CC=clang INSTALL_PATH=/usr/bin/`

## Usage
Tavs takes any number of files as arguments:
`$ tavs <file1> <file2> ...`  
It will open them in neovim, making sure source and header files with the same name stay in the same tab, split vertically.
With a globbing shell this means that you can also feed Tavs something like `$ tavs src/*.c include/*.h` and it will continue working as expected.

## Limitations
I have defined `MAX_FILES` to be 128 and `MAX_CMD_LENGTH` to be 4096.  
This is completely arbitrary.
Feel free to change it before compiling.
I may also change it to suit my needs better in the future, but for now, this more than enough for me.
I mean, who would want to open 60+ tavs in neovim anyways?
