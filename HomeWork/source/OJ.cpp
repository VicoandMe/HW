
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

����: nPapers��ʾ�Ծ����Ŀ(1��Papers��20)��nRemain��ʾʣ���ʱ��(1��nRemain��10000)��paper[][2]��һ��Papers*2�����飬

ÿһ�е�����Ԫ������Ϊ������һ���Ծ������ʱ�䡢��������Ծ�ļ�ֵ

���: *pMaxValueΪ��õ�����ֵ
����:
0:�쳣
1:����ɹ�����


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
