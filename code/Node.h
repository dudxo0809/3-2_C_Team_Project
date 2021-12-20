#pragma once
#include <stdlib.h>
#include <time.h>

struct Node{
	
	char* work;
	int set;

	time_t rest_time;
	time_t work_time;
	
	struct Node* pNext;

	struct Node* (*SetTime)(struct Node* node, time_t work, time_t rest);
	struct Node* (*SetNodeSet)(struct Node* node, int set);
	struct Node* (*SetNodeNext)(struct Node* node, struct Node* next);

	void (*PrintNode)(struct Node*);
	void (*DeleteNode)(struct Node*);

	void (*WorkOut)(struct Node*);

};

struct Node* CreateNode();
struct Node* SetNodeTime(struct Node* node, time_t work, time_t rest);
struct Node* SetNodeSet(struct Node* node, int set);
struct Node* SetNodeNext(struct Node* node, struct Node* next);

void Print(struct Node* node);

void Delete(struct Node* node);

void Work(struct Node* node);