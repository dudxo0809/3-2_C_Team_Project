#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//==========================================================================//
//
//	운동 정보를 저장하기 위한 구조체 Node
//  
//	-> List 구조체를 구성하는 기본 단위
//	-> 운동의 이름, 운동 세트수, 1set당 운동시간, 1set당 휴식시간을 저장함
//	-> 현재 운동이 끝나고 다음운동을 가리키기 위한 포인터 변수가 존재함
//	-> Node구조체의 멤버함수를 호출해 멤버 변수를 초기화 할 수 있다. (Setter func)
//	-> Node구조체의 멤버함수를 호출해 운동 정보 출력, 
//	   노드의 heap memory deallocation, 운동 타이머 동작을 수행할 수 있다.
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