// Problem: Monsters
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1194
// Memory Limit: 512
// Time Limit: 1000
// Start: 02-11-2025 01:18:23 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define lcm(a, b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

int n, m;
vector<vector<ll>> arr(1000, vector<ll>(1000, INT_MAX));
int si, sj;

auto solve(int tecs = -1)
{
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      char c; cin >> c;
      if (c == '.') arr[i][j] = INT_MAX-1;
      else if (c == 'M') arr[i][j] = -1;
      else if (c == 'A') {
        arr[i][j] = INT_MAX-1;
        si = i;
        sj = j;
      }
    }
  }

  queue<array<ll, 3>> q;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (arr[i][j] == -1) {
        arr[i][j] = INT_MAX - 1;
        q.push({i, j, 0});
      }
    }
  }

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    if (f[0] < 0 || f[0] >= n || f[1] < 0 || f[1] >= m || arr[f[0]][f[1]] == INT_MAX) continue;
    if (vis[f[0]][f[1]]) continue;
    vis[f[0]][f[1]] = true;

    if (arr[f[0]][f[1]] <= f[2]) continue;
    arr[f[0]][f[1]] = f[2];

    f[2]++;
    q.push({f[0]+1, f[1], f[2]});
    q.push({f[0], f[1]+1, f[2]});
    q.push({f[0]-1, f[1], f[2]});
    q.push({f[0], f[1]-1, f[2]});
  }

  vector<vector<ll>> dist(n, vector<ll>(m, 0));
  q.push({si, sj, 1});
  int ei, ej;
  bool flag = false;

  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    int i = t[0];
    int j = t[1];
    int len = t[2];

    if (arr[i][j] == INT_MAX) continue;
    if (dist[i][j]) continue;
    if (len-1 >= arr[i][j]) continue;
    dist[i][j] = len;

    // cout << i << ' ' << j << el;

    if (i == 0 || i == n-1 || j == 0 || j == m-1 ) {
      ei = i;
      ej = j;
      flag = true;
      break;
    }

    len++;
    q.push({i, j+1, len});
    q.push({i, j-1, len});
    q.push({i-1, j, len});
    q.push({i+1, j, len});
  }

  // for (int i=0; i<n; i++) {
  //   for (int j=0; j<m; j++) {
  //     if (arr[i][j] == INT_MAX) cout << '#' << ' ';
  //     else if (arr[i][j] == INT_MAX-1) cout << '.' << ' ';
  //     else cout << arr[i][j] << ' ';
  //   }
  //   cout << el;
  // }

  // for (int i=0; i<n; i++) {
  //   for (int j=0; j<m; j++) {
  //     cout << vis[i][j] << "\t";
  //   }
  //   cout << el;
  // }

  if (flag) {
    cout << "YES" << el;
    string res = "";
    while (dist[ei][ej] > 1) {
      if (ej - 1 >= 0 && dist[ei][ej] - 1 == dist[ei][ej - 1]) {
        ej--;
        res += 'R';
      }
      else if (ej + 1 < m && dist[ei][ej] - 1 == dist[ei][ej + 1]) {
        ej++;
        res += 'L';
      }
      else if (ei - 1 >= 0 && dist[ei][ej] - 1 == dist[ei - 1][ej]) {
        ei--;
        res += 'D';
      }
      else if (ei + 1 < m && dist[ei][ej] - 1 == dist[ei + 1][ej]) {
        ei++;
        res += 'U';
      }
    }
    reverse(begin(res), end(res));

    cout << res.length() << el;
    cout << res << el;
  } else {
    cout << "NO" << el;
  }
}

// clang-format off
void initialize()
{
}
// clang-format on

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_integral_v<ReturnValue> || is_same_v<ReturnValue, string> ||
                       is_same_v<ReturnValue, const char *>) {
    cout << f(tecs) << el;
  } else if constexpr (is_floating_point_v<ReturnValue>) {
    cout << fixed << setprecision(floating_precision) << f(tecs) << el;
  } else if constexpr (ranges::range<ReturnValue>) {
    for (auto i : f(tecs)) cout << i << ' ';
    cout << el;
  } else {
    f(tecs);
  }
}

int main()
{
  if constexpr (desync_stdio) {
    Mob;
  }

  initialize();
  if constexpr (is_testcases) {
    int testcase;
    cin >> testcase;
    for (int tecs = 1; tecs <= testcase; tecs++) {
      call_solve(solve, tecs);
    }
  } else {
    call_solve(solve);
  }
}
