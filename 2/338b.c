#include <stdio.h>

void main()
{
   int j, k = 0, n1, n2;

   printf("Enter number of  element of set A\n");

   scanf("%d", &n1);
   int a[n1];

   printf("Enter the element of set A \n");
   for (int i = 0; i < n1; i++)
      scanf("%d", &a[i]);

   printf("Enter number of element of set B\n");

   scanf("%d", &n2);

   int b[n2];
   printf("Enter the element of set B \n");

   for (int i = 0; i < n2; i++)
      scanf("%d", &b[i]);

   int c[n1 + n2];

	for (int i = 0; i < n1; i++)
    {
		  c[i] = a[i];
		  //printf("%d",c[i]);
		  k++;
	}
   
	/*
   for (int i = 0; i < n1; i++)
   {
      for (j = 0; j < k; j++)
      {
         if (c[j] == a[i])
            break;
      }
      if (j == k)
      {
         c[k] = a[i];
         k++;
      }
   }*/

   for (int i = 0; i < n2; i++)
   {
      for (j = 0; j < k; j++)
      {
         if (c[j] == b[i])
            break;
      }
      if (j == k)
      {
         c[k] = b[i];
         k++;
      }
   }

   printf("Union:\n");
   for (int i = 0; i < k; i++)
      printf("%d ", c[i]);
}
