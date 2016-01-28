#include <stdlib.h>
#include "OJ.h"


/*
功能:
	给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。
	90分以上为A 80-89分为B 70-79分为C 60-69分为D 60分以下为E

输入:
	整数score

输出:
	无

返回:
	分级结果
	分数不在100范围时返回-1
*/

int ScoreLevel(int score)
{
  if (score > 100 || score < 0) {
	  return -1;
	} else if (score >= 90) {
	  return 'A';
	} else if (score >= 80 && score < 90) {
	  return 'B';
	} else if (score >= 70 && score <80) {
	  return 'C';
	} else if (score >= 60 && score <70) {
	  return 'D';
	} else if (score < 60) {
	  return 'E';
	}
	return -1;
}
