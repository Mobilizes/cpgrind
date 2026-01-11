// Problem: Counting Towers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2413
// Memory Limit: 512
// Time Limit: 1000
// Start: 28-10-2025 13:10:14 WIB

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

const bool is_testcases = true;
const bool desync_stdio = false;

const ll mod = 1000000007;
const ll mx_n = 1000000 + 5;
ll dp[mx_n][2];

auto solve(int tecs = -1)
{
  int n; cin >> n;

  return (dp[n][0] + dp[n][1]) % mod;
}

// clang-format off
void initialize()
{
  dp[1][0] = 1;
  dp[1][1] = 1;

  for (int i=2; i<mx_n; i++) {
    dp[i][0] = 2*dp[i-1][0] + dp[i-1][1];
    dp[i][0] %= mod;

    dp[i][1] = dp[i-1][0] + 4*dp[i-1][1];
    dp[i][1] %= mod;
  }
}
// clang-format on

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else if constexpr (is_integral_v<ReturnValue> || is_same_v<ReturnValue, string>) {
    cout << f(tecs) << el;
  } else {
    static_assert(
      is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool> || is_integral_v<ReturnValue>,
      "solve() return type is not supported");
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
