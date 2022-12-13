#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    Node *next, *prev;
 } *depan, *belakang;

Node *createNode(int value)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = newNode -> prev = NULL;
    return newNode;
}

void pushBelakang(int value)
{
    Node *newBelakang = createNode(value);

    if(!depan)
    {
        depan = belakang = newBelakang;
    }
    else
    {
        belakang -> prev = newBelakang;
        newBelakang -> next = belakang;
        belakang = newBelakang;
    }
}

void removeDepan()
{
    if(!depan)
    {
        return;
    }
    else if(!depan->prev)
    {
        free(depan);
        depan = NULL;
    }
    else
    {
        Node *newDepan = depan -> prev;
        depan -> prev = newDepan -> next = NULL;
        free(depan);
        depan = newDepan;
    }
}

void readNode(Node *currentNode)
{
    printf("Value: %d\n", currentNode -> value);
    printf("Position Sebelumnya: %p\n", currentNode -> prev);
    printf("Position Sekarang: %p\n", currentNode);
    printf("Position Sesudah: %p\n", currentNode -> next);
}

void printQueue()
{
    for ( Node *temp = belakang; temp != NULL; temp = temp -> next)
    {
        readNode(temp);
        puts("|");
        puts("v");
    }
    puts("NULL");
}

int main()
{
    pushBelakang(10);
    pushBelakang(20);
    pushBelakang(32);
    pushBelakang(5);

    printQueue(); 

    removeDepan();

    printQueue();

    return 0;
}

