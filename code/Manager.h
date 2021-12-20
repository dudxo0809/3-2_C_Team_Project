#pragma once
#include "List.h"
#include <stdio.h>
#include <string.h>

struct Manager{
	
	struct List* list;

	void(*run)(struct Manager);

};


void Run(struct Manager);