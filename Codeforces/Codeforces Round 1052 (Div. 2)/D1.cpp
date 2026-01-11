// Problem: D1. Max Sum OR (Easy Version)
// Contest: Codeforces Round 1052 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2146/D1
// Memory Limit: 256
// Time Limit: 2000
// Start: 14-10-2025 17:40:24 WIB

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
  ll l, r;
  cin >> l >> r;
  ll big2 = 1 << ((int)log2(r) + 1);

  vector<bool> picked(r + 1, false);
  vector<ll> res(r + 1, 0);
  for (ll i = r; i >= l; i--) {
    res[i] = big2 - 1 - i;
    while (res[i] > r || picked[res[i]]) {
      big2 /= 2;
      res[i] = big2 - 1 - i;
    }
    picked[res[i]] = true;
  }

  cout << r * (r + 1) << el;
  for (ll i=0; i<=r; i++) cout << res[i] << ' ';
  cout << el;
  // return (1 << big2) - 1;
}

// pick a pair :
// 1. no value loss
// 2. fits perfectly
//
// 0 1 2 3 4 5 6 7 8 9
// 7 8 5 4 3 2 9 0 1 6

// 0  1  2  3  4  5  6  7  8  9  10  11  12
// 0  2  1  12 11 10 9  8  7  6  5   4   3
//
// 0 1 2 3 4 5 6 7 8 9
// 1 0 5 4 3 2 9 8 7 6
//
// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18
// 0  2  1  12 11 10 9  8  7  6  5  4  3  18 17 16 15 14 13

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
