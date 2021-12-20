#include "List_2D.h"


struct List_2D* MakeList_2D() {

	// µ¿ÀûÇÒ´ç
	struct List_2D* newList = (struct List_2D*)malloc(sizeof(struct List_2D));

	if (newList != NULL) {	// ¸â¹ö ÃÊ±âÈ­
		newList->IsEmpty = Empty_2D;
		newList->Insert = InsertList;
		newList->Delete = DeleteList_2D;

		newList->size = 0;
		newList->head = NULL;
		newList->tail = NULL;
	}

	return newList;
}

int Empty_2D(struct List_2D* list) {
	if (list->head == NULL && list->tail == NULL)
		return 1;
	else
		return 0;
}

struct List* InsertList(struct List_2D* list_2d, struct List* list) {

	// À±ÀÎ¼®
	//
	struct List* ret;
	if (list_2d->IsEmpty(list_2d) == 1) {
		list_2d->head = list;
		list_2d->tail = list;
		ret = list;
	}
	else {
		list_2d->tail->SetNextList(list_2d->tail, list);
		list_2d->tail = list;
		ret = list;
	}

	list_2d->size++;

	return ret;
}

// Deallocate heap memory
void DeleteList_2D(struct List_2D* list_2d) {
	
	// À±ÀÎ¼®
	//Deallocate 2D-List
	struct List* cur_L = list_2d->head;		
	while (cur_L != NULL) {

		struct Node* cur_N = cur_L->head;
		while (cur_N != NULL) {
			struct Node* temp_N = cur_N->pNext;
			free(cur_N);
			cur_N = temp_N;
		}

		struct List* temp_L = cur_L->GetNextList(cur_L);
		free(cur_L);
		cur_L = temp_L;
	}

	list_2d->head = NULL;
	list_2d->tail = NULL;
}