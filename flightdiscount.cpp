#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <climits>
using namespace std;
#define ll long long int
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(x.begin(), x.end())
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin; it != a.end; it++)
#define PI 3.1415926535897932384626
#define INF 100000000000000
typedef vector<ll> vl;
typedef map<ll, ll> ml;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
const unsigned int mod = 1000000007;

vpl adj[100001], adj1[100001];
bool vis[100001];
vl dist(100001, INF), dist1(100001, INF);

void bfs(vpl a[], vl &d, ll s)
{
    priority_queue<pl, vpl, greater<pl>> pq;
    pq.push({0, s});
    d[s] = 0;
    while (!pq.empty())
    {
        ll cur = pq.top().second;
        ll curdis = pq.top().first;
        pq.pop();
        if (vis[cur] == 1)
            continue;

        vis[cur] = 1;
        for (pl v : a[cur])
        {
            if ((curdis + v.second) < d[v.first])
            {
                d[v.first] = (curdis + v.second);
                pq.push({d[v.first], v.first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, c;
    cin >> n >> m;
    vector<pair<pair<ll, ll>, ll>> list;
    while (m--)
    {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj1[b].pb({a, c});
        list.pb({{a, b}, c});
    }

    bfs(adj, dist, 1);

    for (ll i = 1; i <= n; i++)
        vis[i] = 0;

    bfs(adj1, dist1, n);

    ll ans = INF;
    for (pair<pair<ll, ll>, ll> p : list)
    {
        ans = min(ans, dist[p.first.first] + dist1[p.first.second] + ((p.second) / 2));
    }

    cout << ans;

    return 0;
}
