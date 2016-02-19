#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <syscall.h>



static void
Merge (int *A, int *Left, int *Right, int l_elements, int r_elements);

void
MergeSort (int *A, int n)
{
  if ( n < 2)
    return;
  int mid, *left, *right;
  mid = n/2;
  left = (int *) malloc (sizeof (int) * mid);
  right = (int *) malloc (sizeof (int) * (n - mid));
  // Now to copy the elements 
  
  if (left == NULL || right == NULL)
    exit (-1);  

  int i;
  for (i=0; i<mid; i++)
    left[i] = A[i];

  for (i = mid ; i < (n); i++)
    right[i - mid] = A [i];
 
  /* Do a recursive call back */
   MergeSort (left, mid);
   MergeSort (right, n - mid);
   Merge (A, left, right, mid, n-mid);

   /* Must free, else huge memory leaks */
   free (left);
   free (right);

}


/* Merging a Linear time operation */
void
Merge (int *A, int *Left, int *Right, int l_elements, int r_elements)
{

  int i = 0, j = 0, k = 0;
  while (i < l_elements && j < r_elements)
    {

      if (Left[i] < Right [j])
        {
         A[k] = Left[i];
         i++; k++;
        }

      else 
        {
          A[k] = Right[j];
          k++;
          j++;
        }
     }
   while (i < l_elements)
     {
        A[k] = Left[i];
        k++; i++;
     }
      
   while (j < r_elements) 
     {
        A[k] = Right[j];
        k++; j++;
     }  

   
}
   


int
main (char **argv, int argc)
{

   int *a;
   int n;
   printf ("Enter the no of elements ");
   scanf("%d",&n);
   a = (int *) malloc (n * sizeof (n));
   if (a == NULL)
     return 0;
   int i;
   for (i = 0; i < n; i++)
    {
       a [i] = rand () % 32768;
       printf ("\n a[%d] : %d", i , a[i]);
    }

   MergeSort (a, n);
   printf ("\nSorted list");
   for (i = 0; i<n; i++)
    {
       printf ("\n a[%d] = %d", i, a[i]);
    }
   return 0;
}
          
 





