#include "Node.h"

struct Node* CreateNode() {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->work = (char*)malloc(sizeof(char) * 50);

	newNode->SetTime = SetNodeTime;
	newNode->SetNodeSet = SetNodeSet;
	newNode->SetNodeNext = SetNodeNext;
	newNode->PrintNode = Print;
	newNode->DeleteNode = Delete;

	newNode->WorkOut = Work;

	return newNode;
}

struct Node* SetNodeTime(struct Node* node, time_t work, time_t rest) {
	
	node->work_time = work;
	node->rest_time = rest;

	return node;
}

struct Node* SetNodeSet(struct Node* node, int set)
{
	node->set = set;
	return node;
}

struct Node* SetNodeNext(struct Node* node, struct Node* next)
{
	node->pNext = next;

	return node;
}

void Print(struct Node* node) {
	printf("%s\n", node->work);
}

void Delete(struct Node* node) {
	free(node->work);
}

void Work(struct Node* node) {

	// �Էµ� �ð��� �°� ȭ���� clear�ϸ鼭 timer ����
	// Using for(...) or while(...)

	// system("cls")	// �ܼ�â ����� ����


}