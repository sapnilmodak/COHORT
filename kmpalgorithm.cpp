#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int n = s.length();
	int kmp[n+1];
	int i=0, j =-1;
	kmp[0]=-1;
	while(i<n) {
		while(j != -1 && s[i]!= s[j] ) j = kmp[j];

		j++;
		i++;
		kmp[i] = j;
	}
	//mathchin a string p in string s so we will make a string p#s and use

	//given a string s = "abcabcdcbac" find minimum number of char to add to make it palindrome

}