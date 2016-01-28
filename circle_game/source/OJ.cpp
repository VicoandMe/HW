#include <stdlib.h>
#include <iostream>
#include "OJ.h"
using namespace std;
// 功能：设置玩家的个数
// 输入： unsigned int  nPlayNum   玩家的个数 0 < nPlayNum < 10000;
// 输出：无
// 返回：无

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
// 功能：根据nInitialNum的值，获取到根据规则下桌的人的编号
// 输入：unsigned int  nInitialNum  本轮的初始值 0 < nInitialNum < 10000；
// 输出：无
// 返回：本轮退出圆桌的人的编号

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
// 功能：游戏结束,释放资源
// 输入：无
// 输出：无
// 返回：无
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
