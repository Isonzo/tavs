CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic
INSTALL_PATH := ~/bin/
BIN_NAME :=tavs

build:
	$(CC) $(CFLAGS) src/main.c -o $(BIN_NAME)

install: build
	mv $(BIN_NAME) $(INSTALL_PATH)

debug:
	$(CC) $(CFLAGS) src/main.c -g
