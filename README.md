# TabS
A simple utility to open C source and header files in pairs in Neovim.
Give some files, TabS match the ones with the same name.

## Prerequisites
- Neovim
- C compiler to compile by source (makefile uses gcc, but it's very simple to edit)
- A globbing shell (such as bash, zsh, ksh, csh, and anything that expands a '*')

## Installation
1. Compile the single c file with something like: `$ gcc main.c -o tabs`
2. Add the resulting binary to your PATH.

## Usage
TabS takes any number of files as arguments:
`$ tabs <file1> <file2> ...`  
It will open them in neovim, making sure source and header files with the same name stay in the same tab, split vertically.
With a globbing shell this means that you can also feed TabS something like `$ tabs src/*.c include/*.h` and it will continue working as expected.

## Limitations
I have defined `MAX_FILES` to be 128 and `MAX_CMD_LENGTH` to be 4096.  
This is completely arbitrary.
Feel free to change it before compiling.
I may also change it to suit my needs better in the future, but for now, this more than enough for me.
I mean, who would want to open 60+ tabs in neovim anyways?
