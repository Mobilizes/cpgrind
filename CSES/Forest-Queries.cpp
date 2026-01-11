// Problem: Forest Queries
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1652
// Memory Limit: 512
// Time Limit: 1000
// Start: 29-11-2025 20:42:26 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(a) begin(a), end(a)

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n, q; cin >> n >> q;
  vector<string> arr(n+1, string(n+1, 0));
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> res(n+1, vector<int>(n+1, 0));
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      res[i][j] += res[i-1][j];
      res[i][j] += res[i][j-1];
      res[i][j] -= res[i-1][j-1];
      res[i][j] += arr[i][j] == '*';
      // cout << res[i][j] << ' ';
    }
    // cout << el;
  }

  for (int tsc=0; tsc<q; tsc++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << res[c][d] - res[a-1][d] - res[c][b-1] + res[a-1][b-1] << el;
  }
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
