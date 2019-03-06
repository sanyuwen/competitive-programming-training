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

#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define present(c, element) ((c).find(element) != (c).end())
#define all(c) c.begin(),c.end()
struct node {
	int value;
	int leftindex;
	int rightindex;
	node(int value) {
		this->value = value;
		this->leftindex = -1;
		this->rightindex = -1;
	}
	void operator<<(iostream cout) {
		printf("Value: %d, Leftchild: %d, Rightchild: %d\n", this->value, this->leftindex, this->rightindex);
	}
};

void addNode(vector<node> &BST, int father, int value, bool isLeft) {
	node a(value);
	BST.push_back(a);
	int index = BST.size();
	node p = BST.at(father);
	if (isLeft == true) p.leftindex = index;
	else p.rightindex = index;
}

int main(int argc, char **argv) {
	vector<node> BST;
	int father, value;
	int isLeft; //0 indicate right, 1 indicate left
	while (scanf("%d%d%d", &father, &value, &isLeft) == 3) {
		if(father<static_cast<int>(BST.size()))
			addNode(BST,father, value, static_cast<bool>(isLeft));
		else printf("not valid.\n");
	}

	//ostream_iterator<node> out(cout, "\n");
	//copy(all(BST), out);

	return 0;
}