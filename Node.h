#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//==========================================================================//
//
//	� ������ �����ϱ� ���� ����ü Node
//  
//	-> List ����ü�� �����ϴ� �⺻ ����
//	-> ��� �̸�, � ��Ʈ��, 1set�� ��ð�, 1set�� �޽Ľð��� ������
//	-> ���� ��� ������ ������� ����Ű�� ���� ������ ������ ������
//	-> Node����ü�� ����Լ��� ȣ���� ��� ������ �ʱ�ȭ �� �� �ִ�. (Setter func)
//	-> Node����ü�� ����Լ��� ȣ���� � ���� ���, 
//	   ����� heap memory deallocation, � Ÿ�̸� ������ ������ �� �ִ�.
// 
//==========================================================================//
struct Node{
	
	// Member variables=====================================================//
	char   *work;
	int	   set;

	time_t work_time;
	time_t rest_time;
	
	struct Node* pNext;
	//======================================================================//

	// Member Func==========================================================//
	struct Node* (*SetTime)(struct Node* node, time_t work, time_t rest);
	struct Node* (*SetNodeSet)(struct Node* node, int set);
	struct Node* (*SetNodeNext)(struct Node* node, struct Node* next);
	void (*SetNodeName)(struct Node* node, char* name);

	void (*PrintNode)(struct Node*);
	void (*DeleteNode)(struct Node*);

	void (*WorkOut)(struct Node*);	// timer
	//======================================================================//
};


// Functions for Initialize member functions ===============================//
struct Node* CreateNode();
struct Node* _SetNodeTime(struct Node* node, time_t work, time_t rest);
struct Node* _SetNodeSet(struct Node* node, int set);
struct Node* _SetNodeNext(struct Node* node, struct Node* next);
void		 _SetNodeName(struct Node* node, char* name);

void Print(struct Node* node);

void Delete(struct Node* node);

void Work(struct Node* node);
//==========================================================================//