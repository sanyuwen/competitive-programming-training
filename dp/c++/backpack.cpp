#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;


#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define all(c) c.begin(), c.end()
#define maxn 10
int w[maxn], v[maxn];
int n, W,calltimes;

int rec(int i, int j) {
	//select from objects of index i with limit of j for maxinum value
	calltimes++;
	REP(t, 0, i - 1) printf(" ");
	printf("%d,%d,%d\n", i, j,calltimes);
	int ans = 0;
	if (i < n) {
		if (j < w[i]) ans = rec(i + 1, j);
		else ans = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return ans;
}

void solve() {
	calltimes = 0;
	printf("ans is: %d\ncall rec times is %d", rec(0, W),calltimes);
}

int main() {
	freopen("input.txt", "r", stdin);
	memset(w, -1, sizeof(w));
	memset(v, -1, sizeof(v));
	scanf("%d%d", &n, &W);
	REP(i, 1, n) {
		scanf("%d%d", &w[i-1], &v[i-1]);
	}
	solve();
	return 0;
}