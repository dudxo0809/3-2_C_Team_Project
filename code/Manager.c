#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"




void Run(struct Manager manager) {

	FILE* fp;
	manager.list = MakeList();

	struct List* LL = manager.list;		// 운동 정보가 담긴 노드들의 Linked List

	char cmd[20];						// 사용자에게 입력받을 커맨드

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

		system("cls");					// 출력된 화면을 비움

		if (strcmp(cmd, "LOAD") == 0) {
			fp = fopen("data.txt", "r");		// data.txt파일을 읽기모드로 open
			if (fp == NULL) {
				printf("저장된 데이터가 없습니다!\n");
				continue;
			}
			else {
				fp = fopen("data.txt", "r");	// data.txt파일을 읽기모드로 open

				// 파일을 읽어 링크드리스트에 저장

				fclose(fp);
			}
		}
		else if (strcmp(cmd, "NEW") == 0) {
			fp = fopen("data.txt", "w");

			// 파일에 새로운 데이터 저장
			// 동시에 링크드 리스트 생성
			// 
			// 노드 생성, 노드 멤버 초기화, 리스트에 노드 입력...
			// struct Node* n1 = CreateNode();
			// n1->SetTime(n1, 60, 10);
			// LL->Insert(n1);


			fclose(fp);

			printf("운동정보 입력 완료\n");

		}
		else if (strcmp(cmd, "START") == 0) {
			printf("starting\n");

			if (LL->IsEmpty) {
				printf("No data!\n");
				continue;
			}
			else {
				// 리스트 순회하면서 프로그램 실행
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