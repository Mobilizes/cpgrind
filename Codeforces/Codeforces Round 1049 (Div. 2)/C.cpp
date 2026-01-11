// Problem: C. Ultimate Value
// Contest: Codeforces Round 1049 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2140/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 15-10-2025 17:17:28 WIB

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

auto solve(int tecs = -1)
{
  ll n;
  cin >> n;
  vector<ll> arr(n);
  vector<pll> mn_odd(n, {INT_MAX, -1});
  vector<pll> mn_even(n, {INT_MAX, -1});
  ll res = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i > 0) {
      mn_odd[i] = min(mn_odd[i], mn_odd[i - 1]);
      mn_even[i] = min(mn_even[i], mn_even[i - 1]);
    }
    if (i & 1) {
      res -= arr[i];
      if (mn_even[i].first > arr[i]) mn_even[i] = {arr[i], i};
    } else {
      res += arr[i];
      if (mn_odd[i].first > arr[i]) mn_odd[i] = {arr[i], i};
    }
  }

  ll curr = 0;
  for (int i = 1; i < n; i++) {
    if (i & 1) {
      curr = max(curr, (arr[i] - mn_odd[i].first) * 2 + (i - mn_odd[i].second));
    } else {
      curr = max(curr, (mn_even[i].first - arr[i]) * 2 + (i - mn_even[i].second));
    }
  }
  curr = max(n - 2 + (n & 1), curr);

  return res + curr;
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
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else if constexpr (is_integral_v<ReturnValue>) {
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
