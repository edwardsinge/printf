all: main

main: *.c
	gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o printf
0-main: printf.c test/0-main.c
	gcc -Wall -Werror -Wextra -pedantic printf.c test/0-main.c -o 0-maiin
