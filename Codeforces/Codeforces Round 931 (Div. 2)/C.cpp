// Problem: C. Find a Mine
// Contest: Codeforces Round 931 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/1934/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 06-01-2026 19:39:07 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

int ask(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  int res; cin >> res;
  return res;
}

auto solve(int tecs = -1)
{
  int n, m; cin >> n >> m;
  int tl = ask(1, 1);
  int tr = ask(1, m);
  int bl = ask(n, 1);

  int p1j = max((tl + 1 + m - tr) / 2, 1);
  int p1i = max(tl + 2 - p1j, 1);
  int p2j = max((tl + bl + 3 - n) / 2, 1);
  int p2i = max(tl + 2 - p2j, 1);

  int res = ask(p1i, p1j);
  if (res != 0) {
    cout << "! " << p2i << " " << p2j << endl;
  } else {
    cout << "! " << p1i << " " << p1j << endl;
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

