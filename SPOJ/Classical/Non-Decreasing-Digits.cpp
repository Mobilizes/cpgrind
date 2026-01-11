// Problem: Non-Decreasing Digits
// Contest: Classical
// Judge: SPOJ
// URL: https://www.spoj.com/problems/NY10E/
// Memory Limit: 1536
// Time Limit: 1000
// Start: 03-10-2025 00:19:00 WIB

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

vector<ll> dp;

// clang-format off
auto solve(int tecs = -1)
{
  int tsc; cin >> tsc;
  int n; cin >> n;

  cout << tsc << " " << dp[n] << el;
}

void initialize()
{
  int cnt = 0;
  for (int i=100; i<1000; i++) {
    int f = i / 100;
    int s = (i / 10) % 10;
    int t = i % 10;

    if ((f > s && f != 0) || (f > t && f != 0) || (s > t && s != 0)) {
      continue;
    }

    cout << i << el;

    // if (i >= 100) {
    //   mp[f]++;
    // }
  }

  cout << cnt << el;

  dp.assign(65, 0);
  dp[1] = 10;
}
// clang-format on

// 1 10
// 2 55 = (90 + 10) - (10*9/2) = 100 - 45 = 55
// 3 220 = (900 + 55) - (10*(10*9/2) - ) = 955
// 111 222 333 444 555 666 777 888 999
// 10  21  32  43  54  65  76  87  99

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
