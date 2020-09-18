#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

typedef set<int>         si;
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define present(c, element) ((c).find(element) != (c).end())
#define all(c) c.begin(),c.end()
#define maxn 100+5
char a[maxn];



void printchar(char c) {
	printf("%c ", c);
}

void printline() {
	printf("\n---------------------------------------------\n");
}

set<char> findduplicate(string s) {
	string::iterator it = s.begin();
	set<char> duplicate;
	while (it != s.end()) {
		char c = *it;
		if (find(s.begin(), it, c) != it) duplicate.insert(c);
		it++;
	}
	return duplicate;
}

bool checkanagrams(string s1, string s2) {
	sort(all(s1));
	sort(all(s2));
	return s1.compare(s2) == 0 ? true : false;
}
bool checkanagrams2(string s1, string s2) {
	bool r = false;
	if (s1.size() == s2.size())
		r = is_permutation(all(s1), s2.begin());
	return r;
}

bool onlydigits(string s) {
	return count_if(all(s), [](char c) {return isdigit(c) == 0; }) == 0;
}

bool checkRotation(string a, string b) {
	bool r = false;
	if (a.size() == b.size() && a.append(a).find(b) != string::npos)
		r = true;
	return r;
}

int main() {
	memset(a, 0, sizeof(a));

	/*printf("print duplicate characters from string:\n");
	scanf("%s", &a);
	string s(a);
	set<char> t = findduplicate(s);
	for_each(all(t), printchar);
	printline();*/

	//printf("check if two strings are anagrams of each other\n");
	//scanf("%s", &a);
	//string s1(a);
	//scanf("%s", &a);
	//string s2(a);
	//cout<<"Is anagrams?";
	//if (checkanagrams2(s1, s2)) cout << " true" << endl;
	//else cout << "false" << endl;

	/*printf("chech if a string contains only digits\n");
	scanf("%s", &a);
	string s3(a);
	if (onlydigits(s3)) cout << " true" << endl;
	else cout << "false" << endl;*/

	/*printf("find all permutaions of string\n");
	scanf("%s", &a);
	string s3(a);
	sort(all(s3));
	do {
	cout << s3.c_str() << endl;
	} while (next_permutation(all(s3)));*/

	/*printf("reverse words in a given sentence:\n");
	string s4,word;
	vector<string> sentence;
	getline(cin, s4);
	istringstream line(s4);
	while (line >> word) {
		reverse(all(word));
		word.append(" ");
		sentence.push_back(word);
	}
	cout << accumulate(all(sentence), string("")).c_str() << endl;*/

	printf("check if two string is a rotation of each other:\n");
	scanf("%s", a);
	string s5(a);
	scanf("%s", a);
	string s6(a);
	printf("is rotation of each other?\n");
	if (checkRotation(s5, s6)) cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}