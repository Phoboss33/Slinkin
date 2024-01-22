main : squnitA.o squnitA.h main.c
	cc -o main main.c squnitA.o -fsanitize=address

squnitA.o : squnitA.c squnitA.h
	cc -c squnitA.c -fsanitize=address

clean :
	rm -f squnitA.o main