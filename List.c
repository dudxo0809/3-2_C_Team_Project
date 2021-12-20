#include "List.h"

struct List* MakeList() {

	struct List* newList = (struct List*)malloc(sizeof(struct List));
	newList->IsEmpty = Empty;
	newList->Insert = InsertNode;
	newList->Delete = DeleteList;
	newList->SetNextList = SetNextList;
	newList->GetNextList = GetNextList;

	newList->head = NULL;
	newList->tail = NULL;
	newList->nextList = NULL;

	return newList;
}

int Empty(struct List* list) {
	if (list->head == NULL && list->tail == NULL)
		return 1;	// if list is empty ? return 1 : 0
	else
		return 0;
}

struct Node* InsertNode(struct List* list, struct Node* node) {

	// 리스트에 노드 저장
	// 김영태
	struct Node* ret;

	if (list->IsEmpty(list) == 1) {	// if empty ?
		list->head = node;			// newNode is head and tail
		list->tail = node;
		ret = node;
	}
	else {
		list->tail->SetNodeNext(list->tail, node);
		list->tail = node;
		ret = node;
	}


	return ret;
}

// Deallocate all list
void DeleteList(struct List* list) {	
	struct Node* cur = list->head;
	while (!list->IsEmpty) {
		cur->DeleteNode(cur);
		cur = cur->pNext;
	}
}

void SetNextList(struct List* list, struct List* next) {
	list->nextList = next;
}
struct List* GetNextList(struct List* list) {
	return list->nextList;
}