#include <cstdlib>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <iostream>

int totalElementsInList = 0;

using namespace std;

struct node{
	int key;
	struct node *next;
	struct node *prev;
};

struct node *InsertInDoubleLinkedCircularList(struct node *last, int element)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));

	newNode -> key = element;
	if(last == NULL)
	{
		newNode -> next = newNode;
		newNode -> prev = newNode;
	}
	else
	{
		newNode -> next = last -> next;
		newNode -> prev = last;

		last -> next = newNode;

		newNode -> next -> prev = newNode;
	}
	last = newNode;
	return last;
}

struct node *DeleteNodeDoubleLinkedCircularList(struct node *actual, struct node *last)
{
	struct node *temp;
	if(last == NULL)
		cout<<"The double linked circular list is empty."<<endl;

	else
	{
		if(last == last -> next)
		{
			free(last);
			last = NULL;
		}
		else
		{
			temp = actual -> next;
			actual -> next = temp -> next;
			temp -> next -> prev = actual;
			if(last == temp)
			{
				last = actual;
			}
			free(temp);
		}
	}
	return last;
}

struct node *horario(struct node *last,int kOriginal)
{
    int k;
    k = kOriginal % totalElementsInList;
    if(k == 0)
        k = kOriginal;

	for(int i=1;i < k;i++)
	   last = last->next;

	last = DeleteNodeDoubleLinkedCircularList(last,last);
	totalElementsInList--;

	return last;
}

struct node *antihorario(struct node *last,int kOriginal)
{
    int k;
    k = kOriginal % totalElementsInList;
    if(k == 0)
        k = kOriginal;

	for(int i=1;i < k;i++)
	   last = last->prev;

	last = DeleteNodeDoubleLinkedCircularList(last,last);
	totalElementsInList--;
	last = last->prev;
	return last;
}
