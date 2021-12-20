#pragma once
#include "Node.h"
//==========================================================================//
//
//	운동 루틴을 저장하기 위한 구조체 List
// 
//	-> 1개의 운동정보를 저장하는 구조체 Node로 구성됨
//	-> 가장 첫번째 Node를 가리키는 head poniter와
//	   가장 마지막 Node를 가리키는 tail pointer가 존재
//	-> List의 멤버함수 Insert를 호출 해서 Node를 insert할 수 있음
//	-> Node를 삭제하는 함수는 구현X
// 
//==========================================================================//
struct List{

	// Member variables=====================================================//
	struct Node* head;
	struct Node* tail;

	struct List* nextList;
	//======================================================================//

	// Member Func==========================================================//
	int (*IsEmpty)(struct List*);
	struct Node* (*Insert)(struct List*, struct Node*);
	void (*Delete)(struct List*);

	void (*SetNextList)(struct List*, struct List*);
	struct List* (*GetNextList)(struct List*);
	//======================================================================//
};

// Functions for Initialize member functions ===============================//
struct List* MakeList();
int Empty(struct List*);
struct Node* InsertNode(struct List* , struct Node*);

void DeleteList(struct List*);

void SetNextList(struct List*, struct List*);
struct List* GetNextList(struct List*);
//==========================================================================//