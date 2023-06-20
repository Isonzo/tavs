build:
	gcc src/* -o tabs

install: build
	mv tabs ~/bin/

debug:
	gcc src/* -g
