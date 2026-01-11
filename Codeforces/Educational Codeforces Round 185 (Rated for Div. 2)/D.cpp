// Problem: D. Almost Roman
// Contest: Educational Codeforces Round 185 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2170/problem/D
// Memory Limit: 512
// Time Limit: 3000
// Start: 28-11-2025 23:54:36 WIB

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
  int n, q; cin >> n >> q;
  string s; cin >> s;

  int sum = 0;
  int minb = 0;
  int minf = 0;
  int pairs = 0;
  int total = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == 'X') sum += 10;
    if (s[i] == 'V') sum += 5;
    if (s[i] == 'I') {
      sum += (i+1 < n && s[i+1] != 'I' ? -1 : 1);
    }
    if (s[i] == '?') {
      total++;
      if (i+1<n && s[i+1] != 'I' && s[i+1] != '?') minb++;
    }
  }

  for (int tsc=0; tsc<q; tsc++) {
    int x, v, i; cin >> x >> v >> i;
  }
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
