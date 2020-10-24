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

vpl adj[100001];
bool vis[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, c;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    priority_queue<pl, vpl, greater<pl>> pq;
    vl dist(n + 1, INF);
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        ll cur = pq.top().second;
        ll curdis = pq.top().first;
        pq.pop();
        if (vis[cur] == 1)
            continue;

        vis[cur] = 1;
        for (pl v : adj[cur])
        {
            if ((curdis + v.second) < dist[v.first])
            {
                dist[v.first] = (curdis + v.second);
                pq.push({dist[v.first], v.first});
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
