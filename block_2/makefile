main : squnitL.o squnitL.h main.c
	cc -o main main.c squnitL.o -fsanitize=address

squnitL.o : squnitL.c squnitL.h
	cc -c squnitL.c -fsanitize=address

clean :
	rm -f squnitL.o main