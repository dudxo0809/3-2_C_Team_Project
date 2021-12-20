#pragma once
#include "Node.h"

struct List{

	struct Node* head;
	struct Node* tail;

	int (*IsEmpty)(struct List*);
	struct List* (*Insert)(struct List*);
	void (*Delete)(struct List*);

};

struct List* MakeList();
int Empty();
struct Node* InsertNode(struct Node*);

void DeleteList(struct List*);