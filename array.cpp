#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <set>
#include<numeric>
using namespace std;

typedef set<int>         si;
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define present(c, element) ((c).find(element) != (c).end())
#define maxn 100+5
int a[maxn];

int findmissing() {
	return 5050 - accumulate(a,a+99,0);
}

int findonlyduplicate() {
	int i = 0;
	int val = a[i++];
	si t;
	while (val != 0 && !present(t, val)) {
		t.insert(val);
		val = a[i++];
	}
	return val;
}

void printArray(int start, int end) {
	REP(i, start, end - 1) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void printline() {
	printf("\n---------------------------------------------\n");
}

int main() {
	memset(a, 0, sizeof(a));
	srand((unsigned)time(0));

	printf("find the missing number in given integer array of 1 to 100:\n");
	int missing = rand() % 100 + 1;
	printf("%d is missing of 1 to 100\n", missing);
	int j = 0;
	REP(i, 1, 100) {
		if (i != missing) a[j++] = i;
	}
	printf("I find %d is missing\n", findmissing());
	printline();

	printf("find the duplicate number on a given integer array\n");
	int d1 = rand() % 99;
	int d2 = rand() % 99;
	a[d1] = a[d2];
	printf("%d is duplicate\n", a[d1]);
	printf("I find %d is duplicate\n", findonlyduplicate());
	printline();

	printf("find the largest and smallest number in an unsorted integer array\n");
	d1 = rand() % 99;
	d2 = rand() % 99;
	if (d1 > d2) swap(d1, d2);
	printf("the smallest and largest number in the array is %d and %d\n", a[d1], a[d2 - 1]);
	random_shuffle(a + d1, a + d2);
	printf("this is the array: ");
	printArray(d1, d2);
	printf("the max and min are %d,%d\n", *max_element(a + d1, a + d2), *min_element(a + d1, a + d2));
	printline();

	printf("find all pairs of integer array whose sum is equal to a given number");

	return 0;
}