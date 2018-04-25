#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;

typedef long long        ll;
typedef vector<int>      vi;
typedef pair<int, int>   ii;
typedef vector<ii>       vii;
typedef set<int>         si;
typedef map<string, int> msi;

#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define TRvi(c,it)  for(vi::iterator it=(c).begin();it!=(c).end();it++)
#define TRvii(c,it)  for(vii::iterator it=(c).begin();it!=(c).end();it++)
#define TRmsi(c,it)   for(msi::iterator it=(c).begin();it!=(c).end();it++)
//macro below may not be supported by some platform	
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it != c.end(); it++)
#define present(c, element) ((c).find(element) != (c).end())
#define cpresent(c, element) (find(all(c),element) != (c).end())
#define all(c) c.begin(), c.end()
#define ins(x) inserter(x,x.begin())

#define INF 2000000000
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
//memset(dist, MEMSET_INF, sizeof(dist)); //useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof(dp_memo));   //useful to initialize DP memoization table
//memset(arr, 0, sizeof(arr)); //useful to clear array of integers

void print_permutation(int n, int a[], int cur, char b[]){
	if(cur==n){
		REP(i,0,cur-1) cout<<b[a[i]-1]<<" ";
		cout<<endl;
	}else{
		REP(j,1,n){
			bool flag=true;
			REP(t,0,cur-1){
				if(a[t]==j){
					flag=false;
					break;
				}
			}
			if(flag){
				a[cur]=j;
				print_permutation(n,a,cur+1,b);
			}
		}
	}
}

void print_subset(int n, int a[], int cur){  //element in the set is 0,1,2,3.....n-1
	REP(i,0,cur-1) cout<<a[i]<<" ";
	cout<<endl;
	int s=cur==0?0:a[cur-1]+1;  //least one
	REP(j,s,n-1){
		a[cur]=j;
		print_subset(n,a,cur+1);
	}
}

void print_subset2(int n, int a[], int cur, char b[]){  //element in the set is 0,1,2,3.....n-1
	REP(i,0,cur-1) cout<<b[a[i]]<<" ";
	cout<<endl;
	int s=cur==0?0:a[cur-1]+1;  //least one
	REP(j,s,n-1){
		a[cur]=j;
		print_subset2(n,a,cur+1,b);
	}
}

void print_subset1(int n, int B[], int cur){
	if(n==cur){
		REP(i,0,n-1){
			if(B[i]) cout<<i<<" ";
		}
		cout<<endl;
	}else{
		B[cur]=1;  //put current element
		print_subset1(n,B,cur+1);
		B[cur]=0;  //not put it
		print_subset1(n,B,cur+1);
	}
}

void print_subset_s(int n, int s){
	REP(i,0,n-1){
		if(s&(1<<i)) cout<<i<<" ";
	}
	cout<<endl;
}

void print_subset3(int n){
	REP(i,0,(1<<n)-1){
		print_subset_s(n,i);
	}
}

void print_conbinatrics(char b[], int n){
	
}


int main()
{
	freopen("output.txt","w",stdout);
	int a[5],B[5];
	char b[5]={'a','b','c','d','a'};
	//print_permutation(5,a,0,b);
	//print_subset(5,a,0);
	//print_subset1(5,a,0);
	//print_subset2(5,a,0,b);
	print_subset3(5);
	return 0;
}
