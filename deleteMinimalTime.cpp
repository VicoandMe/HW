#include<iostream>
#include<string>

using namespace std;

int main () {
  int mark[256] = {0};
	string s;
	cin>>s;
	int length = s.length();
	for (int i = 0; i < length; i++) {
	  mark[s[i] - '0']++;
	}
	int min = length;
	for (int i = 0; i < 256; i++) {
	  if (mark[i] != 0) {
		  if (min > mark[i]) {
			  min = mark[i];
			}
		}
	}
	string result;
  for (int i = 0; i < length; i++) {
	  if (mark[s[i] - '0'] > min) {
		  result.push_back(s[i]);
		}
	}
	cout<<result<<endl;
	return 0;
}
