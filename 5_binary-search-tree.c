#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

Node *createNewNode(int value);
void inOrder(Node *root);
Node *insertNode(Node *root, int value);

int main()
{
  Node *root = NULL;
  root = insertNode(root, 50);
  insertNode(root, 30);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 70);
  insertNode(root, 60);
  insertNode(root, 80);

  inOrder(root);

  return 0;
}

Node *createNewNode(int value)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = new_node->right = NULL;

  return new_node;
}

void inOrder(Node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    printf("%d \n", root->value);
    inOrder(root->right);
  }
}

// Trace out what the current node is to understand.
Node *insertNode(Node *currentNode, int value)
{
  if (currentNode == NULL)
  {
    return createNewNode(value);
  }

  if (value < currentNode->value)
  {
    currentNode->left = insertNode(currentNode->left, value);
  }

  if (value > currentNode->value)
  {
    currentNode->right = insertNode(currentNode->right, value);
  }

  return currentNode;
}
