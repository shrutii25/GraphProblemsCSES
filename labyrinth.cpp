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

int n, m, endX, endY;
int dist[1001][1001];
char a[1001][1001];
bool vis[1001][1001];
map<pair<int, int>, pair<pair<int, int>, char>> par;

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (vis[x][y] == 1 || a[x][y] == '#')
        return false;

    return true;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    dist[x][y] = 0;
    while (!q.empty())
    {
        if (vis[endX][endY] == 1)
            break;
        else
        {
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();

            if (isValid(curx - 1, cury))
            {
                q.push({curx - 1, cury});
                vis[curx - 1][cury] = 1;
                par[{curx - 1, cury}] = {{curx, cury}, 'U'};
                dist[curx - 1][cury] = dist[curx][cury] + 1;
            }
            if (isValid(curx, cury + 1))
            {
                q.push({curx, cury + 1});
                vis[curx][cury + 1] = 1;
                par[{curx, cury + 1}] = {{curx, cury}, 'R'};
                dist[curx][cury + 1] = dist[curx][cury] + 1;
            }
            if (isValid(curx + 1, cury))
            {
                q.push({curx + 1, cury});
                vis[curx + 1][cury] = 1;
                par[{curx + 1, cury}] = {{curx, cury}, 'D'};
                dist[curx + 1][cury] = dist[curx][cury] + 1;
            }
            if (isValid(curx, cury - 1))
            {
                q.push({curx, cury - 1});
                vis[curx][cury - 1] = 1;
                par[{curx, cury - 1}] = {{curx, cury}, 'L'};
                dist[curx][cury - 1] = dist[curx][cury] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j, srcX, srcY;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                srcX = i;
                srcY = j;
            }
            if (a[i][j] == 'B')
            {
                endX = i;
                endY = j;
            }
        }
    }
    bfs(srcX, srcY);
    if (vis[endX][endY] == 0)
        cout << "NO";
    else
    {
        cout << "YES \n";
        vector<char> ans;
        pair<int, int> x, y;
        x = {endX, endY};
        y = {srcX, srcY};
        while (x != y)
        {
            char ch = par[x].second;
            ans.pb(ch);
            x = par[x].first;
        }
        reverse(ans.begin(), ans.end());
        cout << dist[endX][endY] << "\n";
        for (char v : ans)
        {
            cout << v;
        }
    }
    return 0;
}
