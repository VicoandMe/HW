#include <stdlib.h>
#include "OJ.h"


/*
����:
	����һ�ٷ��Ƴɼ���Ҫ������ɼ��ȼ���A������B������C������D������E����
	90������ΪA 80-89��ΪB 70-79��ΪC 60-69��ΪD 60������ΪE

����:
	����score

���:
	��

����:
	�ּ����
	��������100��Χʱ����-1
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
