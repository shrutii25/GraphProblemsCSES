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
typedef vector<ll> vl;
typedef map<ll, ll> ml;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
const unsigned int mod = 1000000007;

vl adj[100001];
bool vis[100001];
ll p[100001], d[100001];
queue<ll> q;

void bfs(ll node)
{
    q.push(node);
    ll x;
    vis[node] = 1;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (ll child : adj[x])
        {
            if (vis[child] == 0)
            {
                vis[child] = 1;
                q.push(child);
                d[child] = d[x] + 1;
                p[child] = x;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, u, v, i;
    vl path;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    bfs(1);
    p[1] = -1;
    if (vis[n] == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << d[n] + 1 << "\n";
        for (i = n; i != -1; i = p[i])
        {
            path.pb(i);
        }
        reverse(path.begin(), path.end());
        for (ll y : path)
            cout << y << " ";
    }
    return 0;
}
