#pragma once
#include "List_2D.h"
#include <stdio.h>
#include <string.h>

//==========================================================================//
//
//	��ü ���α׷��� ������ �����ϴ� ����ü Manager
// 
//	-> ����� List_2D�� Run�Լ��� ����
// 
//==========================================================================//
struct Manager{
	
	struct List_2D* list_2d;

	void(*run)(struct Manager);

};


void Run(struct Manager);