#define _CRT_SECURE_NO_DEPRECATE

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
