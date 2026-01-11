// Problem: C. Maximum GCD on Whiteboard
// Contest: Codeforces Round 1061 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2156/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 24-10-2025 22:08:00 WIB

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
  int n, k; cin >> n >> k;
  map<int, int> mp;
  for (int i=0; i<n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  vector<int> arr(n+2);
  // arr[n+1] = n;
  // for (int i=n; i>=1; i--) {
  //   arr[i] = arr[i+1];
  //   arr[i] -= mp[i+1];
  // }
  arr[0] = n;
  for (int i=1; i<=n; i++) {
    arr[i] = arr[i-1];
    arr[i] -= mp[i-1];
  }

  // for (int i=1; i<=n; i++) cout << arr[i] << ' ';
  // cout << el;

  int res = 1;
  for (int i=2; i<=n; i++) {
    int cnt = n - mp[i] - mp[2*i] - mp[3*i];
    if (i*4 <= n) cnt -= arr[4*i];
    // cout << cnt << ", ";

    if (cnt <= k) res = max(res, i);
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
