
#include "OJ.h"
#include<queue>
using namespace std;

struct HW {
  int time;
	int value;
	double cp;
	friend bool operator < (struct HW n1, struct HW n2) {
	  return n1.cp < n2.cp;
	}
};

  
/*

输入: nPapers表示试卷的数目(1≤Papers≤20)，nRemain表示剩余的时间(1≤nRemain≤10000)，paper[][2]是一个Papers*2的数组，

每一行的两个元素依次为做完这一份试卷所需的时间、做完这份试卷的价值

输出: *pMaxValue为获得的最大价值
返回:
0:异常
1:计算成功返回


*/
int GetMaxValue(int nPapers, int nRemain, int paper[][2], double* pMaxValue)
{
	if (nPapers==0 || nRemain==0 || pMaxValue==0 || paper[0]==0) {
	  return 0;
	}

	priority_queue<struct HW> cut;
	for (int i = 0; i < nPapers; i++) {
	  struct HW temp;
    temp.time = paper[i][0];
	  temp.value = paper[i][1];
		temp.cp = paper[i][1] / paper[i][0];
	  cut.push(temp);
	}
	
	*pMaxValue = 0;
	while(nRemain > 0 && !cut.empty()) {
	  struct HW topH = cut.top();
		if (nRemain >= topH.time) {
		  nRemain = nRemain - topH.time;
			*pMaxValue += topH.value;
		} else {
		  *pMaxValue += nRemain * topH.cp;
			nRemain = 0;
		}
		cut.pop();
	}
	return 1;
}
