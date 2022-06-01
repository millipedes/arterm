CC=gcc -g -Wall -Wextra
CFILES=$(wildcard src/*.c)
HFILES=$(wildcard src/include/*.h)
OBJFILES=$(CFILES:.c=.o)
OBJPATH=src/objects/
EXEFILE=bin/main

all:$(OBJFILES)
	$(CC) $(OBJFILES) -o $(EXEFILE) -lm

%.o: %.c $(HFILES)%.h
	$(CC) -c $(CFILES) $< -o $@ -lm

vim:
	nvim $(CFILES) 

vimh:
	nvim $(HFILES) 

run:
	$(EXEFILE)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) --leak-check=full --read-var-info

git-update:
	git add Makefile README.md src/ LICENSE .gitignore
	git commit -m "update commit"
	git push origin main

plant:
	plantuml docs/plant.txt
	convert docs/plant.png -channel RGB -negate docs/plant.png

feh:
	feh docs/plant.png&

clean:
	rm $(OBJFILES)
