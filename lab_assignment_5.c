#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int length = 0;
	while (head != NULL)
	{
		head = head -> next;
		length++;
	}
	return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int size = length(head);
	char *ptr;
	int i = 0;
	ptr = (char*) malloc((size+1)*sizeof(char));
	while(i<size)
	{
		ptr[i] = head -> letter;
		head = head -> next;
		i++;
	}
	return ptr;
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *temp;
	node *newNode = (node*) malloc(sizeof(node));
	newNode -> letter = c;
	newNode -> next = NULL;	
	if (*pHead == NULL)
		{
		*pHead = newNode;
		return;
		}
	else{
		temp = *pHead;
		while( temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = newNode;
		}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node *tmp = *pHead;
    while (tmp != NULL) {
        *pHead = tmp -> next;
        free(tmp);
		tmp = *pHead;
    }
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}