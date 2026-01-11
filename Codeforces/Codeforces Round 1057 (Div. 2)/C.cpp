// Problem: C. Symmetrical Polygons
// Contest: Codeforces Round 1057 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2153/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 10-10-2025 21:42:08 WIB

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

// clang-format off
auto solve(int tecs = -1)
{
  int n; cin >> n;
  map<ll, int> mp;
  for (int i=0; i<n; i++) {
    ll x; cin >> x;
    mp[x]++;
  }

  ll biasres = 0;
  int flag = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second == 1 && flag == 0) continue;
  }

  ll res = 0;
  int sticksused = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second >= 2) {
      res += (it->second / 2) * 2 * it->first;
      sticksused += (it->second / 2) * 2;
    }
  }

  bool flag1 = false;
  bool flag2 = false;
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    if (it->first >= res) continue;
    if (it->second % 2 == 0) continue;

    if (!flag1) {
      res += it->first;
      sticksused++;
      flag1 = true;
    } else if (!flag2 && it->second > 2) {
      res += it->first;
      sticksused++;
      flag2 = true;
    }

    if (flag1 && flag2) {
      break;
    }
  }

  return res;
}

// 3 2
// 4 2
// 5 4
// 6 4
// 7 6
// 8 6
// amount of pair of sticks needed to be equal is : (i - 1) // 2

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
