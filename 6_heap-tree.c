#include <stdio.h>
#include <stdlib.h>

int size = 0;
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int array[], int size, int i)
{

  if (size == 1)
  {
    printf("The tree has only a single node");
    return;
  }

  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i - 1;

  if (left < size && array[left] > array[largest])
  {
    largest = left;
  }

  if (right < size && array[right] > array[largest])
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(&array[i], &array[largest]);
    heapify(array, size, largest);
  }
}

void insert(int array[], int value)
{
  if (size == 0)
  {
    array[0] = value;
    size += 1;
  }
  else
  {
    array[size] = value;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}

void deleteNode(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int main()
{
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);

  printf("Max-Heap array: ");
  printArray(array, size);

  deleteNode(array, 4);

  printf("After deleting an element: ");

  printArray(array, size);
}
