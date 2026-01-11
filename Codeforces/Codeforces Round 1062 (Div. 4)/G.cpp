// Problem: G. Mukhammadali and the Smooth Array
// Contest: Codeforces Round 1062 (Div. 4)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2167/problem/G
// Memory Limit: 256
// Time Limit: 1000
// Start: 05-11-2025 08:27:25 WIB

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

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  vector<ll> c(n);
  for (int i=0; i<n; i++) {
    cin >> c[i];
  }

  vector<ll> dp(n);
  for (int i=0; i<n; i++) {
    dp[i] = c[i];
    ll mx = 0;
    for (int j=0; j<i; j++) {
      if (arr[j] <= arr[i]) mx = max(mx, dp[j]);
    }
    dp[i] += mx;
  }

  return accumulate(all(c), 0LL) - *max_element(all(dp));
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
