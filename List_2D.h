#pragma once
#include "List.h"

//==========================================================================//
//
//	운동루틴 여러개를 저장할 수 있는 구조체 List_2D
//  
//	-> List구조체가 모여 List_2D를 구성함
//	-> Manager에서 여러 운동 루틴중 하나를 선택 할 수 있음
// 
//==========================================================================//
struct List_2D {

	// Member variables=====================================================//
	int size;

	struct List* head;
	struct List* tail;
	//======================================================================//

	// Member Func==========================================================//
	int (*IsEmpty)(struct List_2D*);
	struct List* (*Insert)(struct List_2D*, struct List*);
	void (*Delete)(struct List_2D*);		// Deallocate
	//======================================================================//
};

// Functions for Initialize member functions ===============================//
struct List_2D* MakeList_2D();
int Empty_2D(struct List_2D*);
struct List* InsertList(struct List_2D* , struct List*);

void DeleteList_2D(struct List_2D*);
//==========================================================================//