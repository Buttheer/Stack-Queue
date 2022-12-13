#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
  int value;
  Node *next, *prev; 
} *depan, *belakang;

Node *createNode(int value)
{
  Node *newBelakang = (Node *)malloc(sizeof(Node));
  newBelakang->value = value;
  newBelakang->next = newBelakang->prev = NULL;
  return newBelakang;
}

void pushBelakang(int value)
{
  Node *newBelakang = createNode(value);

  if (!depan)
  { 
    depan = belakang = newBelakang;
  }
  else
  {                      
    belakang->prev = newBelakang; 
    newBelakang->next = belakang; 
    belakang = newBelakang;      
  }
}

void pushQueue(int res)
{
  Node *newNode = createNode(res);

  if (!depan || belakang->value < res)
  { // if linked list is empty
    pushBelakang(res);
  }
  else if (depan->value > res)
  {
    depan->next = newNode;
    newNode->prev = depan;
   depan = newNode;
  }
  else
  {
    Node *currentNode = belakang->next;
    while (currentNode->value > res){
        currentNode = currentNode->next;
    } 
    newNode->next = currentNode;
    currentNode->prev->next = newNode;
    newNode->prev = currentNode->prev;
    currentNode->prev = newNode;
  }
}

void removeDepan()
{
  if (!depan)
  { // if linked is empty
    return;
  }
  else if (!depan->prev) // if only 1 node, top has no node below it
  {
    free(depan);  // free allocated memory
    depan = NULL; // set the value to NULL
  }
  else // if there are more than 1 node,
  {
    Node *newdepan = depan->prev;        // the new top candidate will be below the current top
    depan->prev = newdepan->next = NULL; // isolate the current top
    free(depan);                         // free the allocated memory
    depan = newdepan;                    // the new top will replace the deleted top
  }
}

void readNode(Node *currentNode)
{
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node sebelumnya: %p\n", currentNode->prev);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void printQueue()
{
  for (Node *temp = belakang; temp != NULL; temp = temp->next)
  {
    readNode(temp);
    puts("|");
    puts("v");
  }
  puts("NULL");
}


int main (){
    pushQueue(10);
    pushQueue(20);
    pushQueue(32);
    pushQueue(5);

    printQueue(); 

    removeDepan();

    printQueue();

    return 0;
}