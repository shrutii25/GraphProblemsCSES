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
ll parent[100001], cycle_end, cycle_start;

bool dfs(ll v, ll par)
{
    vis[v] = 1;
    for (ll u : adj[v])
    {
        if (u == par)
            continue;
        if (vis[u] == 0)
        {
            parent[u] = v;
            if (dfs(u, v))
            {
                return true;
            }
        }
        else
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, n, m;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    parent[1] = -1;
    cycle_start = -1;

    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0 && dfs(i, parent[i]))
            break;
    }

    if (cycle_start == -1)
        cout << "IMPOSSIBLE";
    else
    {
        vl cycle;
        ll k = 0;
        for (ll v = cycle_end; v != cycle_start; v = parent[v])
        {
            cycle.pb(v);
            k++;
        }
        cycle.pb(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << k + 2 << "\n";
        for (ll v : cycle)
            cout << v << " ";
        cout << cycle_start;
    }

    return 0;
}
