// Problem: Longest Common Subsequence
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3403
// Memory Limit: 512
// Time Limit: 1000
// Start: 02-11-2025 14:33:57 WIB

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
#define all(a) begin(a), end(a)

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

/*
 *   6 5 1 2 3 4
 * 3 0 0 0 0 1 1
 * 1 0 0 1 1 1 1
 * 3 0 0 1 1 2 2
 * 2 0 0 1 2 2 2
 * 7 0 0 1 2 2 2
 * 4 0 0 1 2 2 3
 * 8 0 0 1 2 2 3
 * 2 0 0 1 2 2 3
 *
 *   6 7 8 9 1 2 3 4 5
 * 1 0 0 0 0 1 1 1 1 1
 * 2 0 0 0 0 1 2 2 2 2
 * 3 0 0 0 0 1 2 3 3 3
 * 4 0 0 0 0 1 2 3 4 4
 * 6 1 1 1 1 1 2 3 4 4
 * 7 1 2 2 2 2 2 3 4 4
 * 8 1 2 3 3 3 3 3 4 4
 * 9 1 2 3 4 4 4 4 4 4
 * 5 1 2 3 4 4 4 4 4 5
 *
 *   3 3 5 3 3
 * 5 0 0 1 1 1
 * 5 0 0 1 1 1
 * 3 1 1 2 2 2
 * 5 1 1 2 2 2
 * 5 1 1 2 2 2
*/

auto solve(int tecs = -1)
{
  int n, m; cin >> n >> m;
  vector<int> a(n+1, -1), b(m+1, -2);
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int i=1; i<=m; i++) cin >> b[i];

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
      // cout << dp[i][j] << ' ';
    }
    // cout << el;
  }

  vector<int> res;
  int i=n, j=m;
  while (dp[i][j] > 0 && i > 0 && j > 0) {
    if (dp[i][j-1] < dp[i][j] && dp[i-1][j] < dp[i][j]) {
      j--;
      res.push_back(a[i]);
    } else if (i-1 > 0 && dp[i-1][j] == dp[i][j]) {
      i--;
    } else {
      j--;
    }
    // cout << el;
  }
  reverse(all(res));

  cout << res.size() << el;
  return res;
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
