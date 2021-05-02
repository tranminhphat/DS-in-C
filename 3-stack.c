#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  int top;
  int size;
  int *array;
} Stack;

Stack *createEmptyStack(int size);
void printStack(Stack *st);
int isStackFull(Stack *st);
int isStackEmpty(Stack *st);
void push(Stack *st, int item);
void pop(Stack *st);
void peek(Stack *st);

int main()
{
  int size, option, item;
  printf("Input the size of stack: ");
  scanf("%d", &size);

  Stack *st = createEmptyStack(size);

  do
  {
    printf("\n************************* MENU ************************");
    printf("\n0.DISPLAY STACK");
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.PEEK");
    printf("\n4.EXIT");
    printf("\nEnter your choice : ");
    scanf("%d", &option);
    switch (option)
    {
    case 0:
      printStack(st);
      break;
    case 1:
      printf("\nEnter the value of item: ");
      scanf("%d", &item);
      push(st, item);
      break;
    case 2:
      pop(st);
      break;
    case 3:
      peek(st);
      break;
    case 4:
      break;
    default:
      printf("\n Invalid choice!");
      break;
    }
  } while (option != 4);
  return 0;
}

Stack *createEmptyStack(int size)
{
  Stack *st = (Stack *)malloc(sizeof(Stack));
  st->top = -1;
  st->size = size;
  st->array = (int *)malloc(size * sizeof(int));

  return st;
}

void printStack(Stack *st)
{
  printf("STACK:\n");
  if (st->top == -1)
  {
    printf("Empty\n");
  }
  else
  {
    for (int i = st->top; i >= 0; i--)
    {
      printf("\n%d", st->array[i]);
    }
  }
}

int isStackFull(Stack *st)
{
  return st->top == st->size - 1;
}

int isStackEmpty(Stack *st)
{
  return st->top == -1;
}

void push(Stack *st, int item)
{
  if (isStackFull(st))
  {
    printf("Can not push, stack is full");
    return;
  }

  st->top++;
  st->array[st->top] = item;
}

void pop(Stack *st)
{
  if (isStackEmpty(st))
  {
    printf("Can not pop, stack is empty");
    return;
  }

  st->top--;
}

void peek(Stack *st)
{
  if (isStackEmpty(st))
  {
    printf("Can not peek, stack is empty");
    return;
  }

  printf("\nPeek value: %d", st->array[st->top]);
}