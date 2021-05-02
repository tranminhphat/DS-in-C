#include <stdio.h>
#include <stdlib.h>

void main()
{
  int *p;
  int size;
  do
  {
    printf("Input the size of the array: ");
    scanf("%d", &size);
  } while (size == 0);

  // Input array
  for (int i = 0; i < size; i++)
  {
    int val;
    printf("Input the value of element at index %d: ", i);
    scanf("%d", &val);
    *(p + i) = val;
  }

  // Print array
  printf("\nArray:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(p + i));
  }
}