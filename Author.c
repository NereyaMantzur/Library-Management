#include <stdio.h>
#include <stdlib.h>

#include "Author.h"
#include "General.h"

Author* initAuthor()
{
	Author* newAuthor = (Author*)malloc(sizeof(Author));
	if (!newAuthor)
	{
		return NULL;
	}

	printf("Please enter author name: ");
	newAuthor->name = getStr();
	newAuthor->BookD_List = NULL;
	return newAuthor;
}

int initBookNode()
{
	BookNode* bookNode = (BookNode*)malloc(sizeof(BookNode));
	if (!bookNode)
	{
		return 0;
	}
	bookNode->next = NULL;
	bookNode->prev = NULL;
	return 1;
}

void insert(Author* author, BookNode* bookNode)
{
	if (!author->BookD_List->next)
	{
		author->BookD_List->next = bookNode;
		bookNode->prev = author->BookD_List;
		bookNode->next = NULL;
		return;
	}
	BookNode* temp = author->BookD_List->next;
	author->BookD_List->next = bookNode;
	bookNode->prev = author->BookD_List;
	bookNode->next = temp;
	temp->prev = bookNode;
}

void printAuthor(Author* author)
{
	printf("%s", author->name);
}

void freeAuthor(Author* author)
{
	free(author);
}
