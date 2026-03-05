ifeq ($(OS),Windows_NT)
EXE := .exe
RM := del /Q
else
EXE :=
RM := rm -f
endif

main$(EXE) : main.o utils.o
	gcc -o main$(EXE) main.o utils.o

main.o : main.c utils.h
	gcc -c main.c

utils.o : utils.c utils.h
	gcc -c utils.c

clean :
	-$(RM) main$(EXE) main.o utils.o