#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
  int front, rear, size, capacity;
  int *array;
} Queue;

Queue *createEmptyQueue(int capacity);
void printQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enQueue(Queue *q, int item);
void deQueue(Queue *q);

int main()
{
  int capacity, option, item;
  printf("Input the capacity of queue: ");
  scanf("%d", &capacity);

  Queue *q = createEmptyQueue(capacity);

  do
  {
    printf("\n************************* MENU ************************");
    printf("\n0.DISPLAY QUEUE");
    printf("\n1.ENQUEUE");
    printf("\n2.DEQUEUE");
    printf("\n3.EXIT");
    printf("\nEnter your choice : ");
    scanf("%d", &option);
    switch (option)
    {
    case 0:
      printQueue(q);
      break;
    case 1:
      printf("\nEnter the value of item: ");
      scanf("%d", &item);
      enQueue(q, item);
      break;
    case 2:
      deQueue(q);
      break;
    case 3:
      break;
    default:
      printf("\n Invalid choice!");
      break;
    }
  } while (option != 3);
  return 0;
}

Queue *createEmptyQueue(int capacity)
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->rear = capacity - 1;
  q->capacity = capacity;
  q->size = 0;
  q->array = (int *)malloc(capacity * sizeof(int));

  return q;
}

int isQueueEmpty(Queue *q)
{
  return q->size == 0;
}

int isQueueFull(Queue *q)
{
  return q->size == q->capacity;
}

void printQueue(Queue *q)
{
  printf("QUEUE: ");
  if (isQueueEmpty(q))
  {
    printf("Empty\n");
    return;
  }
  for (int i = q->rear; i >= q->front; i--)
  {
    printf("%d ", q->array[i]);
  }
}

void enQueue(Queue *q, int item)
{
  if (isQueueFull(q))
  {
    printf("Can not enqueue, queue is full");
    return;
  }

  q->rear = (q->rear + 1) % q->capacity;
  q->array[q->rear] = item;
  q->size++;
}

void deQueue(Queue *q)
{
  if (isQueueEmpty(q))
  {
    printf("Can not dequeue, queue is empty");
    return;
  }

  q->front = (q->front + 1) % q->capacity;
  q->size--;
}