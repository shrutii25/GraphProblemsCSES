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
ll y;

void dfs(ll node)
{
    vis[node] = 1;
    for (ll child : adj[node])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }
    y = node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, u, v, i, cc = 0;
    vector<pair<ll, ll>> ans;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            cc++;
            if (cc > 1)
                ans.pb({y, i});
            dfs(i);
        }
    }
    if (cc == 1)
    {
        cout << "0";
    }
    else
    {
        cout << cc - 1 << "\n";
        for (i = 0; i < cc - 1; i++)
            cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}
