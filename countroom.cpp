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

int n, m;
char a[1000][1000];
bool vis[1000][1000];

bool isValid(int x, int y)
{
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
        return false;

    if (vis[x][y] == 1 || a[x][y] == '#')
        return false;

    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;

    if (isValid(x - 1, y))
        dfs(x - 1, y);

    if (isValid(x, y + 1))
        dfs(x, y + 1);

    if (isValid(x + 1, y))
        dfs(x + 1, y);

    if (isValid(x, y - 1))
        dfs(x, y - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j, cnt;
    cin >> n >> m;

    fo(i, n)
    {
        fo(j, m)
        {
            cin >> a[i][j];
        }
    }
    cnt = 0;
    fo(i, n)
    {
        fo(j, m)
        {
            if (a[i][j] == '.' && vis[i][j] == 0)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}
