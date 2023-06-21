CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic
INSTALL_PATH := ~/bin/
BIN_NAME :=tavs

build:
	$(CC) $(CFLAGS) src/main.c -o $(BIN_NAME)

install: build
	mv tabs $(INSTALL_PATH)

debug:
	$(CC) $(CFLAGS) src/main.c -g
