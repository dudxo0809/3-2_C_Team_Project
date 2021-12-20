#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"

/*

data.txt 파일 양식


각 1차원 리스트의 시작 : list_start
각 1차원 리스트의 끝 : list_end

	리스트마다 '운동이름 -> 세트수 -> 운동시간 -> 휴식시간' 순으로 저장

1차원 리스트
	list_start	
	Pushup	// Node1->work		// 첫번째 운동 (첫번째 노드)
	3		// Node1->set
	20		// Node1->work_time
	10		// Node1->rest_time
	Squat	// Node2->work		// 두번째 운동 (두번째 노드)
	4		// Node2->set
	30		// Node2->work_time
	15		// Node2->rest_time
	list_end	// 여기까지 1차원 리스트
	list_start	// 다시 1차원 리스트 시작
	Pullup
	...
	...
	...
	list_end	
				// 마지막 줄은 '\n' 저장
	// 더이상 파일을 읽을 수 없다면 마지막 1D 리스트인것임

			 ** txt파일에 예외는 없다고 가정함 **
				
*/




void Run(struct Manager manager) {


	FILE* fp;		// data.txt
	manager.list_2d = MakeList_2D();	// 운동루틴을 저장하기 위한 2차원 리스트 생성

	struct List_2D* LL_2D = manager.list_2d;		// 운동 정보가 담긴 노드들의 Linked List

	char cmd[20];						// 사용자에게 입력받을 커맨드


	while (1) {
		system("cls");					// 출력된 화면을 비움

		printf("============================\n");
		printf("======= Input Command ======\n");
		printf("============================\n");
		printf("= LOAD  : Load saved data  =\n");
		printf("= NEW   : Make new data    =\n");
		printf("= START : Start program    =\n");
		printf("= EXIT  : Exit program     =\n");
		printf("============================\n\n");

		printf(" Please enter a command > ");
		scanf("%s", cmd);

		

		if (strcmp(cmd, "LOAD") == 0) {
			fp = fopen("data.txt", "r");		// data.txt파일을 읽기모드로 open
			if (fp == NULL) {
				printf("\n\n << 저장된 데이터가 없습니다! >> \n");
				Sleep(1000);
				continue;
			}
			else {
				fp = fopen("data.txt", "r");	// data.txt파일을 읽기모드로 open

				// 윤성민
				// 파일을 읽어 링크드리스트에 저장
				// LL 에 먼저 저장후 -> LL_2D에 LL을 Insert
				// tok = strtok

				LL_2D->Delete(LL_2D);			// 새로 리스트를 생성할 것이므로 기존의 리스트를 삭제함

				char line[100];
				size_t len = 0;
				
				while (!feof(fp)) {				// 파일의 마지막까지 읽음

					struct List* newList = MakeList();		// 새 리스트를 생성
					fgets(line, 100, fp);
					line[strlen(line) - 1] = '\0';
					
					if (strcmp(line, "list_start") == 0) {
						
						char name[100];
						while (1) {

							fgets(name, 100, fp);
							name[strlen(name) - 1] = '\0';
							if (strcmp(name, "list_end") == 0)		// list_end까지가 1차원 리스트
								break;

							struct Node* newNode = CreateNode();	// 운동 정보입력을 위한 구조체 생성

							
							char set[100];
							char work[100];
							char rest[100];
							
							fgets(set, 100, fp);				// 파일로부터 정보를 읽어옴
							fgets(work, 100, fp);
							fgets(rest, 100, fp);
							
							set[strlen(set) - 1] = '\0';		// '\n'을 NULL로 바꿈
							work[strlen(work) - 1] = '\0';
							rest[strlen(rest) - 1] = '\0';

							newNode->SetNodeName(newNode, name);	// 구조체의 멤버 초기화
							newNode->SetNodeSet(newNode, atoi(set));
							newNode->SetTime(newNode, atoi(work), atoi(rest));

							newList->Insert(newList, newNode);	// 1차원 리스트에 운동정보 insert
						}
					}
					if(newList->IsEmpty(newList) != 1)		// 파일의 마지막 '\n'을 pass하기 위함
						LL_2D->Insert(LL_2D, newList);		// 2차원 리스트에 insert
					
				}
				

				fclose(fp);
			}
			printf("\n\n << Data load completed >> \n");
			Sleep(1000);
		}
		else if (strcmp(cmd, "NEW") == 0) {
			fp = fopen("data.txt", "a");

			// 윤인석
			// 파일에 새로운 데이터 저장
			// 동시에 링크드 리스트 생성
			// 
			// 2d list에 list insert

			char yn[20] = "y";		// 정보입력을 위한 버퍼 & 변수
			char work[30];
			int set;
			int worktime;
			int resttime;
			
			struct List* newlist = MakeList();			// 리스트를 생성

			while (strcmp(yn,"y") == 0) {
				printf("운동정보를 입력하시겠습니까? (y/n) : ");
				scanf("%s",yn);
				if (strcmp(yn, "n") == 0)				// n입력시 운동정보 입력 중지
					break;
				else if(strcmp(yn, "y") == 0) {}		// y입력시 운동정보 추가
				else {
					printf("\n\n << Wrong Command!! >> \n");	// 잘못된 커맨드 입력
					Sleep(1000);
					continue;
				}

				printf("Insert work name : ");
				
				while ((getchar()) != '\n');	// to pass '\n'
				fgets(work, 20, stdin);			// get line include ' '
				work[strlen(work) - 1] = 0;		// insert NULL character
				
				printf("Insert work set : ");
				scanf("%d", &set);
				printf("Insert work time(sec) : ");
				scanf("%d", &worktime);
				printf("Insert rest time(sec) : ");
				scanf("%d", &resttime);

				struct Node* newNode = CreateNode();	// stdin으로 정보를 입력받고 운동 노드의 멤버를 초기화
				newNode->SetNodeName(newNode, work);
				newNode->SetNodeSet(newNode, set);
				newNode->SetTime(newNode, worktime, resttime);

				newlist->Insert(newlist, newNode);

			}
			if (newlist->IsEmpty(newlist) != 1) {
				LL_2D->Insert(LL_2D, newlist);			// 운동노드를 list에 insert

				struct Node* cur;
				cur = newlist->head;

				fputs("list_start\n", fp);
				while (cur != NULL) {

					char _set[50];						// Buffer
					char _work[50];
					char _rest[50];

					fputs(cur->work, fp); fputs("\n", fp);
					_itoa(cur->set, _set, 10);				// convert int to char*
					fputs(_set, fp); fputs("\n", fp);
					_itoa(cur->work_time, _work, 10);
					fputs(_work, fp); fputs("\n", fp);
					_itoa(cur->rest_time, _rest, 10);
					fputs(_rest, fp); fputs("\n", fp);

					cur = cur->pNext;
				}
				fputs("list_end\n", fp);
			}
			else
				newlist->Delete(newlist);	// if list is empty

			fclose(fp);

			printf("운동정보 입력 완료\n");

		}
		else if (strcmp(cmd, "START") == 0 ) {	// 운동루틴을 보여주고 선택하게함
			printf("\n\n << starting... >> \n");
			Sleep(1000);
			

			if (LL_2D->IsEmpty(LL_2D)) {
				printf(" << No data! >> \n");
				Sleep(1000);
				continue;
			}
			else {
				// 리스트 순회하면서 프로그램 실행
				//
				// while(...){
				//		node->WorkOut();
				//		...
				// }
				// 윤성민

				// 2D List에서 운동루틴을 선택할 Consol 화면 필요//
				//
				int program_num;

				system("cls");					// 출력된 화면을 비움
				printf("============================\n");
				printf("======  Select Program  ====\n");
				printf("============================\n");
				struct List* cur_L = LL_2D->head;			// Pointer to traverse list_2D
				struct Node* cur_N;							// Pointer to traverse list
				int cnt = 1;
				while (cur_L != NULL) {		// 2차원 리스트의 마지막까지 순회
					
					cur_N = cur_L->head;
					printf("%d : ", cnt++);
					while (cur_N != NULL) {	// 1차원 리스트의 마지막까지 순회
						printf(" -> %s ", cur_N->work);
						cur_N = cur_N->pNext;
					}
					printf("\n");

					cur_L = cur_L->GetNextList(cur_L);	// 다음 리스트로 넘어감
				}
				printf("============================\n");

				printf(">> ");
				scanf("%d", &program_num);

				if (program_num > LL_2D->size || program_num < 1) {	// 운동 루틴 번호가 아니면 error
					printf("\n\n << Wrong Command!! >> \n");
					Sleep(1000);
					continue;
				}

				int i;
				cur_L = LL_2D->head;
				for (i = 1; i < program_num; i++) {
					cur_L = cur_L->GetNextList(cur_L);				// 선택된 운동 루틴(1차원리스트)를 가리킴
				}
				
				cur_N = cur_L->head;
				while (cur_N != NULL) {				// 선택된 운동 루틴을 수행
					cur_N->WorkOut(cur_N);			// 운동 타이머 함수 호출
					cur_N = cur_N->pNext;			// 현재 루틴의 다음 운동으로 넘어감
				}
			}
		}
		else if (strcmp(cmd, "EXIT") == 0) {

			LL_2D->Delete(LL_2D);					// 전체 리스트의 할당된 메모리를 해제함
			break;
		}
		else {
			printf("\n\n << Wrong command! >> \n");	// 잘못된 명령어 입력
			Sleep(1000);
			continue;
		}
	}

	return;
}