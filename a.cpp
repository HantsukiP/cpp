#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > PII;
#define mm(x, y) memset(x, y, sizeof x)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
#define lowbit(x) (x & -x)
#define all(x) (x).begin(), (x).end()
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define ins(x) insert(x)
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define x first
#define y second
const int N = 200010, INF = 0x3f3f3f3f, M = N << 1;

int n,m;
int s, t;
int h[N], e[M], ne[M],w[M], idx;
int a[N];
bool st[N];
int dist[N];
int sum[N];
int res[N];
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int s)
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0,s});
	dist[s] = 0;
	sum[s] = 1;
	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();
		
		int ver = t.second, distance = t.first;
		if(st[ver]) continue;
		st[ver] = true;
		res[ver] += a[ver];

		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > w[i] + distance)
			{
				dist[j]  = w[i] + distance;
				sum[j] = sum[ver];
				res[j] = res[ver];
				heap.push({dist[j],j});
			}
			else if(dist[j] == dist[ver] + distance)
			{
				sum[j] += sum[ver];
				res[j] = max(res[j], res[ver]);
			}
				
		}
	}
}


signed main(){
	mm(h,-1);
	cin >> n >> m >> s >> t;
	rep(i,0,n-1) cin >> a[i];

	rep(i,1,m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	dijkstra(s);

	cout << sum[t] << " " << res[t];
	return 0;
}


