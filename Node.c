#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"
//==========================================================================//
//
//	struct Node* newNode = CreateNode();	// 이런식으로 사용
//
//==========================================================================//
struct Node* CreateNode() {

	// Dynamic allocation 
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->work = (char*)malloc(sizeof(char) * 50);

	// Initialize member func
	newNode->SetTime = _SetNodeTime;
	newNode->SetNodeSet = _SetNodeSet;
	newNode->SetNodeNext = _SetNodeNext;
	newNode->SetNodeName = _SetNodeName;
	newNode->PrintNode = Print;
	newNode->DeleteNode = Delete;
	newNode->WorkOut = Work;

	// set next Node pointer NULL
	newNode->pNext = NULL;
	

	return newNode;	// return this
}

struct Node* _SetNodeTime(struct Node* node, time_t work, time_t rest) {
	
	node->work_time = work;
	node->rest_time = rest;

	return node;
}

struct Node* _SetNodeSet(struct Node* node, int set)
{
	node->set = set;
	return node;
}

struct Node* _SetNodeNext(struct Node* node, struct Node* next)
{
	node->pNext = next;

	return node;
}

void _SetNodeName(struct Node* node, char* name) {
	strcpy(node->work, name);
}

void Print(struct Node* node) {
	printf("%s\n", node->work);
}

void Delete(struct Node* node) {
	free(node->work);
}

void Work(struct Node* node) {

	// 입력된 시간에 맞게 화면을 clear하면서 timer 측정
	// Using for(...) or while(...)

	// system("cls")	// 콘솔창 출력을 지움
	// 김영태
	int current_set = 1;
	for (current_set = 1; current_set <= node->set; current_set++) {
		
		time_t timer = node->work_time;
		time_t rest = node->rest_time;

		for (; timer > 0; timer--) {
			system("cls");

			printf("===================================\n");
			printf("=                                  \n");
			printf("=           < Working >            \n");
			printf("=                                  \n");
			printf("=   Work  %s                       \n", node->work);
			printf("=                                  \n");
			printf("=   Set   %d set / %d set          \n", current_set, node->set);
			printf("=                                  \n");
			printf("=                                  \n");
			printf("=   Timer %lld sec / %lld sec      \n", timer, node->work_time);
			printf("=                                  \n");
			printf("=                                  \n");
			printf("=                                  \n");
			printf("===================================\n");
			
			Sleep(1000);
		}

		for (; rest > 0; rest--) {
			system("cls");

			printf("===================================\n");
			printf("=                                  \n");
			printf("=           < Resting >            \n");
			printf("=                                  \n");
			printf("=   Work  %s                       \n", node->work);
			printf("=                                  \n");
			printf("=   Set   %d set / %d set          \n", current_set, node->set);
			printf("=                                  \n");
			printf("=                                  \n");
			printf("=   Timer %lld sec / %lld sec      \n", rest, node->rest_time);
			printf("=                                  \n");
			printf("=                                  \n");
			printf("=                                  \n");
			printf("===================================\n");

			Sleep(1000);
		}
	}
	

	system("cls");
}