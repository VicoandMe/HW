#include <stdlib.h>
#include "PhoneBookProcess.h"


/*
����: ����Ƿ�������������˾ӵ����ͬ�ĵ绰����,��ͳ�����

�������: inFileName  - �������Ե绰����������б��Դ�ļ���      [��ʽ�����Ŀ˵��PPT]
        outFileName - ���ͳ���ظ�����Ľ����Ŀ���ļ���                  [��ʽ�����Ŀ˵��PPT]

�������: ��
����: 0 - �ɹ�
        1 - �������ִ������ļ�������
*/

int trans[27];

int PhoneBookProcess(const char *inFileName,const char *outFileName) 
{
	trans['A' - 'A'] = 2;
	trans['B' - 'A'] = 2;
  trans['C' - 'A'] = 2;
  trans['D' - 'A'] = 3;
  trans['E' - 'A'] = 3;
  trans['F' - 'A'] = 3;
  trans['G' - 'A'] = 4;
  trans['H' - 'A'] = 4;
  trans['I' - 'A'] = 4;
  trans['J' - 'A'] = 5;
  trans['K' - 'A'] = 5;
  trans['L' - 'A'] = 5;
  trans['M' - 'A'] = 6;
  trans['N' - 'A'] = 6;
  trans['O' - 'A'] = 6;
  trans['P' - 'A'] = 7;
  trans['Q' - 'A'] = 7;
  trans['R' - 'A'] = 7;
  trans['S' - 'A'] = 7;
  trans['T' - 'A'] = 8;
  trans['U' - 'A'] = 8;
  trans['V' - 'A'] = 8;
  trans['W' - 'A'] = 9;
  trans['X' - 'A'] = 9;
  trans['Y' - 'A'] = 9;
  trans['Z' - 'A'] = 9;
	
	return 0;
}
