CC = gcc
FLAGS= -Wall -Werror -g

all: main 
run: Main
	./$^
main: main.o
	$(CC) $(FLAGS) $^ -o Main
%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm *.o Main 
.PHONY: all run