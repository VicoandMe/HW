#include "IPAddressValid.h"
#include<string.h>
#include<stdio.h>

bool isIPAddressValid(const char* pszIPAddr)
{
	if (pszIPAddr == 0) {
	  return false;
	}
	int length = strlen(pszIPAddr);
	int head = 0;
	int tail = length-1;
	for(; pszIPAddr[head] == ' ' && head < length; head++){}
	for(; pszIPAddr[tail] == ' ' && tail > 0; tail--){}
	if (head > tail) {
	  return false;
	}
	int dotcount = 0;
  int num = 0;
	for(int i = head; i <= tail; i++) {
	  if (pszIPAddr[i] == '.') {
			if(i == head || i == tail) {
			  return false;
			}
			dotcount++;
			num = 0;
			if (pszIPAddr[i-1] < '0' || pszIPAddr[i-1] > '9') {
			  return false;
			}
		  if (pszIPAddr[i+1] < '0' || pszIPAddr[i+1] > '9') {
			  return false;
			}
		} else if (pszIPAddr[i] > '0' && pszIPAddr[i] <'9') {
			num = num*10 + (int)(pszIPAddr[i] - '0');
			if (num > 255) {
			  return false;
			}
		}
    if (pszIPAddr[i] == ' ') {
		  return false;
		}
		if (pszIPAddr[i] == '0') {
		  if (i == head && pszIPAddr[i+1] != '.') {
				return false;
			}
			if (i != head && i != tail) {
			    if (pszIPAddr[i-1] == '.' && pszIPAddr[i+1] != '.') {
				    return false;
				  }
			}
		}
	  if (pszIPAddr[i] < '0' && pszIPAddr[i] >'9') {
		  return false;
		}
	}
	if (dotcount != 3) {
		return false;
	}
	return true;
}

//int main() {
//	char a[] = "255.255..255\0";
//  if(isIPAddressValid(a)) {
//	  printf("YES");
//	} else {
//	  printf("NO");
//	}
//}
