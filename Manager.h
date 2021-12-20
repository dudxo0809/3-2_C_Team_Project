#pragma once
#include "List_2D.h"
#include <stdio.h>
#include <string.h>

//==========================================================================//
//
//	전체 프로그램의 동작을 관리하는 구조체 Manager
// 
//	-> 멤버로 List_2D와 Run함수를 가짐
// 
//==========================================================================//
struct Manager{
	
	struct List_2D* list_2d;

	void(*run)(struct Manager);

};


void Run(struct Manager);