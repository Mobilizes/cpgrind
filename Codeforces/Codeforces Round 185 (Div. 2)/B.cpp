// Problem: B. Archer
// Contest: Codeforces Round 185 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/312/problem/B
// Memory Limit: 256
// Time Limit: 2000
// Start: 08-10-2025 02:13:28 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;

// clang-format off
auto solve(int tecs = -1)
{
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  double a, b, c, d;
  cin >> a >> b >> c >> d;

  // P = p + (1-p)(1-q) * P
  // P - (1-p)(1-q)P = p
  // P(1 - (1-p)(1-q)) = p
  // P = p / (1 - (1-p)(1-q))

  double p = a / b;
  double q = c / d;

  cout << setprecision(15) << p / (1.0 - (1 - p)*(1 - q)) << el;
}

void initialize() {}
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
