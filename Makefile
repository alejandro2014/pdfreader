CC=gcc
EXE=pdfreader
OBJDIR=obj
SRCDIR=src

${EXE}: obj/pdfreader.o
	${CC} obj/pdfreader.o -o ${EXE}

obj/pdfreader.o: src/pdfreader.c
	${CC} -c src/pdfreader.c -o obj/pdfreader.o

clean:
	rm obj/* ${EXE}
