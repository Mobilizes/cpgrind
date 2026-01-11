// Problem: C1. Renako Amaori and XOR Game (easy version)
// Contest: Codeforces Round 1065 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2171/problem/C1
// Memory Limit: 256
// Time Limit: 2000
// Start: 20-11-2025 21:49:52 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
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
  vector<int> a(n), b(n);
  int x = 0;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    x ^= a[i];
  }
  for (int i=0; i<n; i++) {
    cin >> b[i];
    x ^= b[i];
  }

  if (x == 0) return "Tie";

  int bit = 20;
  for (; bit>=0; bit--) {
    if (x & 1 << bit) break;
  }
  for (int i=n-1; i>=0; i--) {
    if ((a[i] ^ b[i]) & 1 << bit) return i & 1 ? "Mai" : "Ajisai";
  }

  return "Ajisai";
}

void initialize()
{
}

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
// if you see good syntax format, i used clang-format
