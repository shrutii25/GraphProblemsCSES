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

vl adj[100001], ans;
int vis[100001];

bool dfs(ll v)
{
    vis[v] = 1;
    for (ll u : adj[v])
    {
        if (vis[u] == 1 || (vis[u] == 0 && !dfs(u)))
            return 0;
    }
    vis[v] = 2;
    ans.pb(v);
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, i, a, b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        adj[a].pb(b);
    }

    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (!dfs(i))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    for (ll u : ans)
        cout << u << " ";

    return 0;
}
