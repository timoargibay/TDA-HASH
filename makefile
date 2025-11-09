VALGRIND_FLAGS=--leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2 --show-leak-kinds=all --trace-children=yes
CFLAGS =-std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -Wtrampolines -O2 -g
CC = gcc

all: clean valgrind-alumno

compilar_todo: src/*.c main.c
	gcc $(CFLAGS) -c src/hash.c -o archivos_objeto/hash.o
	gcc $(CFLAGS) -c src/extras_tp1.c -o archivos_objeto/extras_tp1.o
	gcc $(CFLAGS) -c src/tp1.c -o archivos_objeto/tp1.o
	gcc $(CFLAGS) archivos_objeto/*.o pruebas_alumno.c -o pruebas_alumno
	gcc $(CFLAGS) archivos_objeto/*.o main.c -o main

valgrind-main: compilar_todo
	valgrind $(VALGRIND_FLAGS) ./main ejemplo_main_valgrind.txt buscar nombre Pikachu
	valgrind $(VALGRIND_FLAGS) ./main ejemplo_main_valgrind.txt buscar id 84

valgrind-pruebas: compilar_todo
	valgrind $(VALGRIND_FLAGS) ./pruebas_alumno

pruebas_alumno: src/*.c pruebas_alumno.c
	$(CC) $(CFLAGS) src/*.c pruebas_alumno.c -o pruebas_alumno

clean:
	rm -f pruebas_alumno 
format:
	clang-format -i -style=file src/*.c
	clang-format -i -style=file src/*.h
	clang-format -i -style=file pruebas_alumno.c main.c

preparar_entrega: compilar_todo format
	rm -f main
	rm -f pruebas_alumno
	rm -f archivos_objeto/*.o
