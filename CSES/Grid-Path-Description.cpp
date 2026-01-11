// Problem: Grid Path Description
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1625
// Memory Limit: 512
// Time Limit: 1000
// Start: 01-01-2026 01:01:28 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) begin(a), end(a)

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

const int sz = 7;

// int di[4] = {1, 0, 0, -1};
// int dj[4] = {0, -1, 1, 0};
// char dir[4] = {'D', 'L', 'R', 'U'};

bool inbound(int i, int j) {
  return i >= 0 && i < sz && j >= 0 && j < sz;
}

bool vis[sz][sz] = {false};
string path;
int res = 0;

void gen_path(int i, int j, int idx) {
  if ((idx == sz*sz-1) || (i == sz-1 && j == 0)) {
    res += ((idx == sz*sz - 1) && (i == sz-1 && j == 0));
    return;
  }

  if ((!inbound(i-1, j) || vis[i-1][j]) && (!inbound(i+1, j) || vis[i+1][j])) {
    if ((inbound(i, j-1) && !vis[i][j-1]) && (inbound(i, j+1) && !vis[i][j+1])) return;
  }
  if ((!inbound(i, j-1) || vis[i][j-1]) && (!inbound(i, j+1) || vis[i][j+1])) {
    if ((inbound(i-1, j) && !vis[i-1][j]) && (inbound(i+1, j) && !vis[i+1][j])) return;
  }

  vis[i][j] = true;

  if (path[idx] == '?' || path[idx] == 'D') if (inbound(i+1, j) && !vis[i+1][j]) gen_path(i+1, j, idx+1);
  if (path[idx] == '?' || path[idx] == 'U') if (inbound(i-1, j) && !vis[i-1][j]) gen_path(i-1, j, idx+1);
  if (path[idx] == '?' || path[idx] == 'L') if (inbound(i, j-1) && !vis[i][j-1]) gen_path(i, j-1, idx+1);
  if (path[idx] == '?' || path[idx] == 'R') if (inbound(i, j+1) && !vis[i][j+1]) gen_path(i, j+1, idx+1);

  vis[i][j] = false;
}

auto solve(int tecs = -1)
{
  cin >> path;

  gen_path(0, 0, 0);

  return res;
}

void initialize()
{
}

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
// if you see good syntax format, i used clang-format
