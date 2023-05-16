
https://www.mccme.ru/mmmf-lectures/books/books/book.1.pdf ( 13 стр )


# include <stdio.h>
# include <math.h>

int main ()
{
unsigned int a,b,c,d,n;
double sqr;
printf("n= ");
scanf("%u",&n);
sqr = sqrt((double)n);
printf("%f\n",sqr);

for (a=0;a<=sqr;a++)
	for (b=a;b<=sqr;b++)
		for (c=b;c<=sqr;c++)
			for (d=c;d<=sqr;d++)
				if ((a*a+b*b+c*c+d*d)==n) {
					printf("\na=%d,b=%d,c=%d,d=%d",a,b,c,d);
				}
}
