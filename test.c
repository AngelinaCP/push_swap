#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct Node
{
	int	x;
	struct Node *next;
} Node;

void insert_end(Node **root, int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (!new_node)
		exit (1);
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	Node *curr = *root;

	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

void insert_beggining(Node **root, int value)
{
	Node	*new_node = malloc(sizeof(Node));
	if (!new_node)
		exit (1);
	new_node->x = value;
	new_node->next = *root;
	
	*root = new_node;
}

void	insert_after(Node *node, int value)
{
	Node	*new_node = malloc(sizeof(Node));

	if (new_node == NULL)
		exit(2);
	new_node->x = value;
	new_node->next = node->next;
	node->next = new_node;
}

void	insert_sorted(Node **root, int value)
{
	Node	*curr;

	curr = *root;
	if (*root == NULL || (*root)->x >= value)
	{
		insert_beggining(root, value);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->x >= value)
			break;
		curr = curr->next;
	}
	insert_after(curr, value);
}

void	remove_element(Node **root, int value)
{
	if (*root == NULL)
		return ;
	Node	*curr = *root;
	Node	*to_remove = NULL;
	
	if ((*root)->x == value)
	{
		to_remove = *root;
		*root = (*root)->next;
		free (to_remove);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->x == value)
		{
			to_remove = curr->next;
			curr->next = curr->next->next;
			free (to_remove);
		}
		curr = curr->next;
	}
}

void deallocate(Node **root)
{
	Node	*curr = *root;
	while (curr)
	{
		Node *aux = curr;
		curr = curr->next;
		free (aux);
	}
	*root = NULL;
}

void reverse(Node **root)
{
	Node *prev = NULL;
	Node *curr = *root;

	while (curr != NULL)
	{
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*root = prev;
}

int main(void)
{
	Node *root = NULL;
	// Node *root = malloc(sizeof(Node));
	// if (!root)
	// 	exit (1);
	// root->x = 5;
	// root->next = NULL;
	insert_beggining(&root, 2);
	 insert_after(root, 12);
	 insert_end(&root, 10);
	 insert_end(&root, 5);
	 insert_end(&root, 8);
	 insert_end(&root, 7);
	 insert_end(&root, 9);
	 reverse(&root);
//	insert_sorted(&root, 5);
//	insert_sorted(&root, 4);
//	insert_sorted(&root, 1);
//	insert_sorted(&root, 7);
//	remove_element(&root, 1);
	Node	*curr = root;

	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}

	return (0);
} 