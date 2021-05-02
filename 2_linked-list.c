#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

void insertAtEnd(Node **ref, int value);
void insertAtBeginning(Node **ref, int value);
void insertAfter(Node **ref, int nodeIndex, int value);
void deleteNode(Node **ref, int nodeIndex);
void deleteFirstNode(Node **ref);
void deleteLastNode(Node **ref);
void printList(Node **ref);

void main()
{
  int option;
  int index;
  int value;
  Node *head = NULL;

  do
  {
    printf("\n************************* MENU ************************");
    printf("\n0.DISPLAY LIST");
    printf("\n1.INSERT AT END");
    printf("\n2.INSERT AT BEGINNING");
    printf("\n3.INSERT AFTER A PARTICULAR NODE");
    printf("\n4.DELETE A PARTICULAR NODE");
    printf("\n5.DELETE FIRST NODE");
    printf("\n6.DELETE LAST NODE");
    printf("\n7.EXIT");
    printf("\nEnter your choice : ");
    scanf("%d", &option);
    switch (option)
    {
    case 0:
      printList(&head);
      break;
    case 1:
      printf("\nEnter the value: ");
      scanf("%d", &value);
      insertAtEnd(&head, value);
      break;
    case 2:
      printf("\nEnter the value: ");
      scanf("%d", &value);
      insertAtBeginning(&head, value);
      break;
    case 3:
      printf("\nEnter the index of the given node: ");
      scanf("%d", &index);
      printf("\nEnter the value: ");
      scanf("%d", &value);
      insertAfter(&head, index, value);
      break;
    case 4:
      printf("\nEnter the index of the deleted node: ");
      scanf("%d", &index);
      deleteNode(&head, index);
      break;
    case 5:
      deleteFirstNode(&head);
      break;
    case 6:
      deleteLastNode(&head);
      break;
    case 7:
      break;
    default:
      printf("\n Invalid choice!");
      break;
    }
  } while (option != 7);
}

void printList(Node **ref)
{
  Node *head = *ref;
  printf("Linked list: ");
  while (head != NULL)
  {
    printf("%d->", head->value);
    head = head->next;
  }
  printf("NULL");
}

void insertAtEnd(Node **ref, int value)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;

  Node *head = *ref;
  if (head == NULL)
  {
    *ref = new_node;
    free(head);
    return;
  }

  while (head->next != NULL)
  {
    head = head->next;
  }

  head->next = new_node;
}

void insertAtBeginning(Node **ref, int value)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = *ref;

  *ref = new_node;
}

void insertAfter(Node **ref, int index, int value)
{
  Node *temp = *ref;
  while (index > 0 && temp != NULL)
  {
    if (temp == NULL)
    {
      printf("Given node can not be NULL");
      return;
    }
    temp = temp->next;
    index = index - 1;
  };

  if (index > 0)
  {
    printf("Given node can not be NULL");
    return;
  }

  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = temp->next;

  temp->next = new_node;
}

void deleteNode(Node **ref, int index)
{
  Node *temp = *ref;
  Node *prev;

  while (index > 0 && temp != NULL)
  {
    if (temp == NULL)
    {
      printf("Deleted node can not be NULL");
      return;
    }
    prev = temp;
    temp = temp->next;
    index = index - 1;
  };

  if (index > 0)
  {
    printf("Deleted node can not be NULL");
    return;
  }

  prev->next = temp->next;
}

void deleteFirstNode(Node **ref)
{
  Node *head = *ref;
  if (head == NULL)
  {
    printf("Linked list is empty");
    return;
  }
  *ref = head->next;
}

void deleteLastNode(Node **ref)
{
  Node *head = *ref;
  Node *prev;

  if (head == NULL)
  {
    printf("Linked list is empty");
    return;
  }

  while (head->next != NULL)
  {
    prev = head;
    head = head->next;
  }

  prev->next = NULL;
}