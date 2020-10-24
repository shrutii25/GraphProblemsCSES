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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, u, v, i;
    vl adj[100001];
    cin >> n >> m;
    vl side(n + 1, -1);
    while (m--)
    {
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    queue<ll> q;
    bool flag = 1;

    for (i = 1; i <= n; i++)
    {
        if (side[i] == -1)
        {
            q.push(i);
            side[i] = 0;
            for (ll z : adj[i])
            {
                if ((side[z] != -1) && (side[z] != (side[i] ^ 1)))
                {
                    side[i] = 1;
                    break;
                }
            }
            while (!q.empty())
            {
                ll x = q.front();
                q.pop();
                for (ll y : adj[x])
                {
                    if (side[y] == -1)
                    {
                        side[y] = side[x] ^ 1;
                        q.push(y);
                    }
                    else
                    {
                        if (side[y] != (side[x] ^ 1))
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag == 0)
                    break;
            }
            if (flag == 0)
                break;
        }
    }

    if (flag == 0)
        cout << "IMPOSSIBLE";
    else
    {
        for (i = 1; i <= n; i++)
        {
            if (side[i] == 0)
            {
                side[i] = 2;
            }
        }

        for (i = 1; i <= n; i++)
            cout << side[i] << " ";
    }
    return 0;
}
