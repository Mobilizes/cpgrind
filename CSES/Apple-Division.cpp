// Problem: Apple Division
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1623
// Memory Limit: 512
// Time Limit: 1000
// Start: 29-10-2025 23:37:29 WIB

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

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<ll> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  ll sum = accumulate(all(arr), 0LL);

  ll res = INT_MAX;
  for (int i=1; i<(1<<n); i++) {
    ll curr = 0;
    for (int j=0; j<n; j++) {
      if (!(i & (1 << j))) continue;
      curr += arr[j];
    }
    res = min(res, abs(curr - (sum - curr)));
  }

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
