#include "List.h"

struct List* MakeList() {

	struct List* newList = (struct List*)malloc(sizeof(struct List));
	newList->IsEmpty = Empty;
	newList->Insert = InsertNode;
	newList->Delete = DeleteList;

	return newList;
}

int Empty(struct List* list) {
	if (!list->head && !list->tail)
		return 1;
	else
		return 0;
}

struct Node* InsertNode(struct Node* node) {

	// ����Ʈ�� ��� ����

}

void DeleteList(struct List* list) {
	struct Node* cur = list->head;
	while (!list->IsEmpty) {
		cur->DeleteNode(cur);
		cur = cur->pNext;
	}
}