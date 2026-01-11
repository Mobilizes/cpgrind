// Problem: E. Number Maze
// Contest: 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2172/problem/E
// Memory Limit: 256
// Time Limit: 1000
// Start: 18-11-2025 16:47:17 WIB

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
  string s; cin >> s;
  int j, k; cin >> j >> k;

  int i = 1;
  string a, b;
  do {
    if (i == j) a = s;
    if (i == k) b = s;
    i++;
  } while (next_permutation(all(s)));

  int x=0, y=0;
  for (int i=0; i<s.length(); i++) {
    for (int j=0; j<s.length(); j++) {
      if (a[i] == b[j]) y++;
    }
  }

  for (int i=0; i<s.length(); i++) {
    if (a[i] == b[i]) {
      x++;
      y--;
    }
  }

  cout << x << 'A' << y << 'B' << el;
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
