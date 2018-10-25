#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct JosephuNode {
	int index;
	int passwd;
	struct JosephuNode *next;
}JosephuNode;

JosephuNode *JosephuLinkListInit(int num);
void GameStart(JosephuNode *head, int password);