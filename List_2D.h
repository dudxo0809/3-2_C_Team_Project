#pragma once
#include "List.h"

//==========================================================================//
//
//	���ƾ �������� ������ �� �ִ� ����ü List_2D
//  
//	-> List����ü�� �� List_2D�� ������
//	-> Manager���� ���� � ��ƾ�� �ϳ��� ���� �� �� ����
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