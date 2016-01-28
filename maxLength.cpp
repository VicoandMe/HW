#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main() {
  char str[129];
	gets(str);
	int max_len = 0;
	int now_len = 0;
	for (int i = 0; i < strlen(str); i++) {
	  if (str[i] != ' ') {
		  now_len ++;
		} else {
		  now_len = 0;
		}
	  if (now_len != 0) {
		  max_len = now_len;
		}
	}
	cout<<max_len<<endl;
}
