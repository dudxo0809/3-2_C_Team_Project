#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"

/*

data.txt ���� ���


�� 1���� ����Ʈ�� ���� : list_start
�� 1���� ����Ʈ�� �� : list_end

	����Ʈ���� '��̸� -> ��Ʈ�� -> ��ð� -> �޽Ľð�' ������ ����

1���� ����Ʈ
	list_start	
	Pushup	// Node1->work		// ù��° � (ù��° ���)
	3		// Node1->set
	20		// Node1->work_time
	10		// Node1->rest_time
	Squat	// Node2->work		// �ι�° � (�ι�° ���)
	4		// Node2->set
	30		// Node2->work_time
	15		// Node2->rest_time
	list_end	// ������� 1���� ����Ʈ
	list_start	// �ٽ� 1���� ����Ʈ ����
	Pullup
	...
	...
	...
	list_end	
				// ������ ���� '\n' ����
	// ���̻� ������ ���� �� ���ٸ� ������ 1D ����Ʈ�ΰ���

			 ** txt���Ͽ� ���ܴ� ���ٰ� ������ **
				
*/




void Run(struct Manager manager) {


	FILE* fp;		// data.txt
	manager.list_2d = MakeList_2D();	// ���ƾ�� �����ϱ� ���� 2���� ����Ʈ ����

	struct List_2D* LL_2D = manager.list_2d;		// � ������ ��� ������ Linked List

	char cmd[20];						// ����ڿ��� �Է¹��� Ŀ�ǵ�


	while (1) {
		system("cls");					// ��µ� ȭ���� ���

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
			fp = fopen("data.txt", "r");		// data.txt������ �б���� open
			if (fp == NULL) {
				printf("\n\n << ����� �����Ͱ� �����ϴ�! >> \n");
				Sleep(1000);
				continue;
			}
			else {
				fp = fopen("data.txt", "r");	// data.txt������ �б���� open

				// ������
				// ������ �о� ��ũ�帮��Ʈ�� ����
				// LL �� ���� ������ -> LL_2D�� LL�� Insert
				// tok = strtok

				LL_2D->Delete(LL_2D);			// ���� ����Ʈ�� ������ ���̹Ƿ� ������ ����Ʈ�� ������

				char line[100];
				size_t len = 0;
				
				while (!feof(fp)) {				// ������ ���������� ����

					struct List* newList = MakeList();		// �� ����Ʈ�� ����
					fgets(line, 100, fp);
					line[strlen(line) - 1] = '\0';
					
					if (strcmp(line, "list_start") == 0) {
						
						char name[100];
						while (1) {

							fgets(name, 100, fp);
							name[strlen(name) - 1] = '\0';
							if (strcmp(name, "list_end") == 0)		// list_end������ 1���� ����Ʈ
								break;

							struct Node* newNode = CreateNode();	// � �����Է��� ���� ����ü ����

							
							char set[100];
							char work[100];
							char rest[100];
							
							fgets(set, 100, fp);				// ���Ϸκ��� ������ �о��
							fgets(work, 100, fp);
							fgets(rest, 100, fp);
							
							set[strlen(set) - 1] = '\0';		// '\n'�� NULL�� �ٲ�
							work[strlen(work) - 1] = '\0';
							rest[strlen(rest) - 1] = '\0';

							newNode->SetNodeName(newNode, name);	// ����ü�� ��� �ʱ�ȭ
							newNode->SetNodeSet(newNode, atoi(set));
							newNode->SetTime(newNode, atoi(work), atoi(rest));

							newList->Insert(newList, newNode);	// 1���� ����Ʈ�� ����� insert
						}
					}
					if(newList->IsEmpty(newList) != 1)		// ������ ������ '\n'�� pass�ϱ� ����
						LL_2D->Insert(LL_2D, newList);		// 2���� ����Ʈ�� insert
					
				}
				

				fclose(fp);
			}
			printf("\n\n << Data load completed >> \n");
			Sleep(1000);
		}
		else if (strcmp(cmd, "NEW") == 0) {
			fp = fopen("data.txt", "a");

			// ���μ�
			// ���Ͽ� ���ο� ������ ����
			// ���ÿ� ��ũ�� ����Ʈ ����
			// 
			// 2d list�� list insert

			char yn[20] = "y";		// �����Է��� ���� ���� & ����
			char work[30];
			int set;
			int worktime;
			int resttime;
			
			struct List* newlist = MakeList();			// ����Ʈ�� ����

			while (strcmp(yn,"y") == 0) {
				printf("������� �Է��Ͻðڽ��ϱ�? (y/n) : ");
				scanf("%s",yn);
				if (strcmp(yn, "n") == 0)				// n�Է½� ����� �Է� ����
					break;
				else if(strcmp(yn, "y") == 0) {}		// y�Է½� ����� �߰�
				else {
					printf("\n\n << Wrong Command!! >> \n");	// �߸��� Ŀ�ǵ� �Է�
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

				struct Node* newNode = CreateNode();	// stdin���� ������ �Է¹ް� � ����� ����� �ʱ�ȭ
				newNode->SetNodeName(newNode, work);
				newNode->SetNodeSet(newNode, set);
				newNode->SetTime(newNode, worktime, resttime);

				newlist->Insert(newlist, newNode);

			}
			if (newlist->IsEmpty(newlist) != 1) {
				LL_2D->Insert(LL_2D, newlist);			// ���带 list�� insert

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

			printf("����� �Է� �Ϸ�\n");

		}
		else if (strcmp(cmd, "START") == 0 ) {	// ���ƾ�� �����ְ� �����ϰ���
			printf("\n\n << starting... >> \n");
			Sleep(1000);
			

			if (LL_2D->IsEmpty(LL_2D)) {
				printf(" << No data! >> \n");
				Sleep(1000);
				continue;
			}
			else {
				// ����Ʈ ��ȸ�ϸ鼭 ���α׷� ����
				//
				// while(...){
				//		node->WorkOut();
				//		...
				// }
				// ������

				// 2D List���� ���ƾ�� ������ Consol ȭ�� �ʿ�//
				//
				int program_num;

				system("cls");					// ��µ� ȭ���� ���
				printf("============================\n");
				printf("======  Select Program  ====\n");
				printf("============================\n");
				struct List* cur_L = LL_2D->head;			// Pointer to traverse list_2D
				struct Node* cur_N;							// Pointer to traverse list
				int cnt = 1;
				while (cur_L != NULL) {		// 2���� ����Ʈ�� ���������� ��ȸ
					
					cur_N = cur_L->head;
					printf("%d : ", cnt++);
					while (cur_N != NULL) {	// 1���� ����Ʈ�� ���������� ��ȸ
						printf(" -> %s ", cur_N->work);
						cur_N = cur_N->pNext;
					}
					printf("\n");

					cur_L = cur_L->GetNextList(cur_L);	// ���� ����Ʈ�� �Ѿ
				}
				printf("============================\n");

				printf(">> ");
				scanf("%d", &program_num);

				if (program_num > LL_2D->size || program_num < 1) {	// � ��ƾ ��ȣ�� �ƴϸ� error
					printf("\n\n << Wrong Command!! >> \n");
					Sleep(1000);
					continue;
				}

				int i;
				cur_L = LL_2D->head;
				for (i = 1; i < program_num; i++) {
					cur_L = cur_L->GetNextList(cur_L);				// ���õ� � ��ƾ(1��������Ʈ)�� ����Ŵ
				}
				
				cur_N = cur_L->head;
				while (cur_N != NULL) {				// ���õ� � ��ƾ�� ����
					cur_N->WorkOut(cur_N);			// � Ÿ�̸� �Լ� ȣ��
					cur_N = cur_N->pNext;			// ���� ��ƾ�� ���� ����� �Ѿ
				}
			}
		}
		else if (strcmp(cmd, "EXIT") == 0) {

			LL_2D->Delete(LL_2D);					// ��ü ����Ʈ�� �Ҵ�� �޸𸮸� ������
			break;
		}
		else {
			printf("\n\n << Wrong command! >> \n");	// �߸��� ��ɾ� �Է�
			Sleep(1000);
			continue;
		}
	}

	return;
}