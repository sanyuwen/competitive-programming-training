#include "stdafx.h"
#include <forward_list>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iterator>
#include <numeric>
#include <deque>
using namespace std;

typedef vector<int>         vi;
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

void elimDups(vector<string> &words)
{
	// sort words alphabetically so we can find the duplicates
	sort(words.begin(), words.end());
	// unique reorders the input range so that each word appears once in the
	// front portion of the range and returns an iterator one past the unique range
	auto end_unique = unique(words.begin(), words.end());
	for_each(all(words), [](string s) {cout << s.c_str() << " "; });
	printline();
	// erase uses a vector operation to remove the nonunique elements
	words.erase(end_unique, words.end());
	for_each(all(words), [](string s) {cout << s.c_str() << " "; });
	printline();
}

void elimDups(list<string> &words)
{
	// sort words alphabetically so we can find the duplicates
	words.sort();
	// unique reorders the input range so that each word appears once in the
	// front portion of the range and returns an iterator one past the unique range
	words.unique();
	// erase uses a vector operation to remove the nonunique element
}

int main(int argc, char **argv) {
	//memset(a, 0, sizeof(a));
	srand((unsigned)time(0));

	/*printf("find middle element of a singly lingked list in one pass:\n");
	int len = rand() % 15 + 1;
	forward_list<int> lst(len);
	generate(all(lst), []() {return rand() % 100; });
	for_each(all(lst), [](int a) {printf("%d ", a); });
	printf("\n");
	auto p1 = lst.begin(), p2 = lst.begin();
	while (true) {
	p2++;
	if (p2 == lst.end()) break;
	p2++;
	if (p2 == lst.end()) break;
	p1++;
	}
	printf("length of %d list : the middle element is %d.\n", len, *p1);*/

	ifstream fin("input.txt");
	istream_iterator<int> in_iter(fin), e;
	ofstream fout1("even.txt");
	ofstream fout2("odd.txt");
	ostream_iterator<int> out_iter1(fout1, " ");
	ostream_iterator<int> out_iter2(fout2, "\n");
	vi t(in_iter, e);
	remove_copy_if(all(t), out_iter1, [](int i) {return i % 2 == 1; });//even
	remove_copy_if(all(t), out_iter2, [](int i) {return i % 2 == 0; });//odd
	fin.close();
	fout2.close();
	fout1.close();

	/*istream_iterator<string> instr(cin), eof;
	list<string> words(instr,eof);
	elimDups(words);
	ostream_iterator<string> outstr(cout, " ");
	copy(all(words), outstr);*/

	//very interesting , using \n the print it inmediately
	/*istream_iterator<string> instr(cin), eof;
	ostream_iterator<string> outstr(cout, " ");
	copy(instr, eof, outstr);*/

	/*printf("remove duplicate nodes in an unsorted linked list:\n");
	ostream_iterator<int> out(cout," ");
	forward_list<int> a;
	auto p = a.before_begin();
	p = a.insert_after(p, 2, 2);
	p = a.insert_after(p, 3, 8);
	p = a.insert_after(p, 4, 3);
	copy(all(a), out);
	printf("\n");
	a.sort();
	p = unique(all(a));
	copy(a.begin(),p, out);*/

	/*printf("find the length of a singly linked list:\n");
	forward_list<int> b(10);
	cout<<distance(all(b))<<endl;*/

	/*printf("find the 3rd node from the end in a singly linked list:\n");
	ostream_iterator<int> out(cout, " ");
	forward_list<int> c(10);
	int i = 0;
	generate(all(c), []() { return rand()%100+1; });
	copy(all(c), out);
	cout << endl;
	const int j = 3;
	auto it = c.begin(),p=c.begin();
	p++;
	p++;
	p++;
	while (p != c.end()) {
		p++;
		it++;
	}
	cout << *it << endl;*/

	return 0;
}