CC =  gcc
CFLAGS = -g -Wall 

all: isort txtfind

isort: isort.o

txtfind: txtfind.o

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm *.o isort txtfind

.PHONY : clean all 
