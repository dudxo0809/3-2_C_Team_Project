#pragma once
#include "Node.h"
//==========================================================================//
//
//	� ��ƾ�� �����ϱ� ���� ����ü List
// 
//	-> 1���� ������� �����ϴ� ����ü Node�� ������
//	-> ���� ù��° Node�� ����Ű�� head poniter��
//	   ���� ������ Node�� ����Ű�� tail pointer�� ����
//	-> List�� ����Լ� Insert�� ȣ�� �ؼ� Node�� insert�� �� ����
//	-> Node�� �����ϴ� �Լ��� ����X
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