#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int, int>   ii;
typedef vector<ii>       vii;
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define TRvii(c,it)  for(vii::iterator it=(c).begin();it!=(c).end();it++)

void dfs(vector<vii> g, int start) {
	if (start<1 || start>g.size()) {
		cout << "invalid start vertice" << endl;
		return;
	}
	else {
		stack<int> s;
		vector<bool> isVisited(g.size(), false);
		s.push(start);
		while (!s.empty()) {
			int current = s.top(); s.pop();
			if (isVisited[current - 1] == false) {
				isVisited[current - 1] = true;
				cout << current << " ";
				TRvii(g[current - 1], it) {
					s.push(it->first + 1);
				}
			}
		}
	}
}

void bfs(vector<vii> g, int start) {
	if (start<1 || start>g.size()) {
		cout << "invalid start vertice" << endl;
		return;
	}
	else {
		queue<int> s;
		vector<bool> isVisited(g.size(), false);
		s.push(start);
		while (!s.empty()) {
			int current = s.front(); s.pop();
			if (isVisited[current - 1] == false) {
				isVisited[current - 1] = true;
				cout << current << " ";
				TRvii(g[current - 1], it) {
					s.push(it->first + 1);
				}
			}
		}
	}
}

int main() {
	freopen("graph_example.txt", "r", stdin);
	int V;
	scanf("%d", &V);
	vector<vii> graphAdjList(V, vii());  //int weighted graph
	int total_neighbor;
	REP(i, 0, V - 1) {
		scanf("%d", &total_neighbor);
		int id, weight;
		REP(j, 1, total_neighbor) {
			scanf("%d%d", &id, &weight);
			graphAdjList[i].push_back(ii(id - 1, weight));  //first is the index of neighbor in the adjlist
		}
	}
	dfs(graphAdjList, 1);
	cout << endl;
	bfs(graphAdjList, 1);
	return 0;
}