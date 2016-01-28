#include <stdlib.h>
#include <iostream>
#include "OJ.h"
using namespace std;
// ���ܣ�������ҵĸ���
// ���룺 unsigned int  nPlayNum   ��ҵĸ��� 0 < nPlayNum < 10000;
// �������
// ���أ���

int playerNum = 0;
int lastNum = 0;
bool circle[10001];

int current;
void SetPlayerNum (unsigned int  nPlayNum)
{
  playerNum = nPlayNum;
	lastNum = nPlayNum;
  for (int i = 1; i <= playerNum; i++) {
	  circle[i] = 1;
	}
	current = 1;
}
// ���ܣ�����nInitialNum��ֵ����ȡ�����ݹ����������˵ı��
// ���룺unsigned int  nInitialNum  ���ֵĳ�ʼֵ 0 < nInitialNum < 10000��
// �������
// ���أ������˳�Բ�����˵ı��

void findNext() {
	if (lastNum == 0) {
	  return;
	}
  if (current == playerNum) {
		  current = 1;
		} else {
		  current++;
		}
	while(circle[current] != 1) {
	  if (current == playerNum) {
		  current = 1;
		} else {
		current++;
		}
	}
}

bool isOut(int num) {
  if (num % 7 == 0) {
	  return true;
	}
	while(num) {
	  if (num % 10 == 7) {
		  return true;
		}
		num = num/10;
	}
	return false;
}
unsigned int GetPlayerOut (unsigned int  nInitialNum)
{
	int n = nInitialNum;
	while(lastNum >= 1) {
		if (circle[current] == 1) {
		  n++;
		}
		if(isOut(n)) {
		  findNext();
			circle[current] = 0;
			lastNum --;
			int ret = current;
			findNext();	
			return ret;
		}
		if(current == playerNum) {
		  current = 1;
		} else {
		  current ++;
		}
	}
	return 0;
}
// ���ܣ���Ϸ����,�ͷ���Դ
// ���룺��
// �������
// ���أ���
void GameOver()
{
  for (int i = 1; i <= playerNum; i++) {
	  circle[i] = 0;
	}
	playerNum = 0;
	current = 0;
}

//int main() {
//  SetPlayerNum(1);
//	cout<<GetPlayerOut(9999)<<endl;

//}
