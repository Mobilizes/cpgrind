// Problem: C. Reverse XOR
// Contest: Codeforces Round 1058 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2160/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 12-10-2025 22:30:15 WIB

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
  ll n; cin >> n;
  ll z = 64 - __builtin_clzll(n);

  string s = "";
  for (int i=0; i<128; i++) s += "0";
  for (ll i=(1LL << 30); i>0; i /= 2LL) {
    if (n & i) {
      s += "1";
      n ^= i;
    } else {
      s += "0";
    }
  }

  for (int i=s.length() - z; i>=0; i--) {
    string sb = s.substr(i);
    if (sb[sb.length() / 2] == '1' && sb.length() & 1) continue;
    string rsb = sb;
    reverse(rsb.begin(), rsb.end());
    if (sb == rsb) return true;
  }

  return false;
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
