#include "Josephu.h"

JosephuNode *JosephuLinkListInit(int num)
{
	int i;
	int password;
	JosephuNode *head, *tail;
	printf("Initializing the playground...\n");
	head = tail = (JosephuNode*)malloc(sizeof(JosephuNode));
	for (i = 1; i < num; i++)
	{
		tail->index = i;
		printf("Please enter the password of No. %d:", i);
		scanf_s("%d", &password);
		tail->passwd = password;
		tail->next = (JosephuNode*)malloc(sizeof(JosephuNode));
		tail = tail->next;
	}
	tail->index = i;
	printf("Please enter the password of No. %d:", i);
	scanf_s("%d", &password);
	tail->passwd = password;
	tail->next = head;
	return head;
}

void GameStart(JosephuNode *head, int password)
{
	int i, j;
	JosephuNode *ptr = (JosephuNode*)malloc(sizeof(JosephuNode));
	for (i = 1; ptr != head; i++)
	{
		for (j = 1; j < password; j++)
		{
			ptr = head;
			head = head->next;
		}
		ptr->next = head->next;
		printf("The No.%d person who got kicked by the game is Player No.%d with the password of %d.\n", i, head->index, head->passwd);
		password = head->passwd;
		free(head);
		head = ptr->next;
	}
	printf("The No.%d person who got kicked by the game is Player No.%d with the password of %d.\n", ++i, head->index, head->passwd);
	free(head);
	return;
}

int main(void)
{
	int num;
	int password;
	JosephuNode *head;
	printf("Please enter the number of gamers:");
	scanf_s("%d", &num);
	printf("Please enter the default password:");
	scanf_s("%d", &password);
	head = JosephuLinkListInit(num);
	printf("Here comes the result:\n");
	GameStart(head, password);
	system("pause");
	return 0;
}