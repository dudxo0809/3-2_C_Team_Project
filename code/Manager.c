#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"




void Run(struct Manager manager) {

	FILE* fp;
	manager.list = MakeList();

	struct List* LL = manager.list;		// � ������ ��� ������ Linked List

	char cmd[20];						// ����ڿ��� �Է¹��� Ŀ�ǵ�

	while (1) {
		printf("============================\n");
		printf("======= Input Command ======\n");
		printf("============================\n");
		printf("= LOAD  : load before data =\n");
		printf("= NEW   : Make new data    =\n");
		printf("= START : Start program    =\n");
		printf("= EXIT  : Exit program     =\n");	
		printf("============================\n");

		scanf("%s", cmd);

		system("cls");					// ��µ� ȭ���� ���

		if (strcmp(cmd, "LOAD") == 0) {
			fp = fopen("data.txt", "r");		// data.txt������ �б���� open
			if (fp == NULL) {
				printf("����� �����Ͱ� �����ϴ�!\n");
				continue;
			}
			else {
				fp = fopen("data.txt", "r");	// data.txt������ �б���� open

				// ������ �о� ��ũ�帮��Ʈ�� ����

				fclose(fp);
			}
		}
		else if (strcmp(cmd, "NEW") == 0) {
			fp = fopen("data.txt", "w");

			// ���Ͽ� ���ο� ������ ����
			// ���ÿ� ��ũ�� ����Ʈ ����
			// 
			// ��� ����, ��� ��� �ʱ�ȭ, ����Ʈ�� ��� �Է�...
			// struct Node* n1 = CreateNode();
			// n1->SetTime(n1, 60, 10);
			// LL->Insert(n1);


			fclose(fp);

			printf("����� �Է� �Ϸ�\n");

		}
		else if (strcmp(cmd, "START") == 0) {
			printf("starting\n");

			if (LL->IsEmpty) {
				printf("No data!\n");
				continue;
			}
			else {
				// ����Ʈ ��ȸ�ϸ鼭 ���α׷� ����
				//
				// while(...){
				//		node->WorkOut();
				//		...
				// }
			}
		}
		else if (strcmp(cmd, "EXIT") == 0) {

			LL->Delete(LL);
			break;
		}
		else {
			printf("Wrong command!\n");
			continue;
		}
	}

	return;
}