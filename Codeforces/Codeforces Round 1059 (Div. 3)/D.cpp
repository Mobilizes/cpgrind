// Problem: D. Beautiful Permutation
// Contest: Codeforces Round 1059 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2162/problem/D
// Memory Limit: 256
// Time Limit: 2000
// Start: 09-11-2025 23:13:48 WIB

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
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

int ask(int mode, int l, int r) {
  cout << mode << " " << l << " " << r << endl;
  int x; cin >> x;
  return x;
}

auto solve(int tecs = -1)
{
  int n; cin >> n;
  int diff = ask(2, 1, n) - (n*(n+1)) / 2;

  map<pii, int> mp;
  int rr = n;
  int r = 1;
  while (r < rr) {
    int m = (r + rr) / 2;
    if (!mp[{1, m}]) {
      int x = ask(2, 1, m);
      int y = ask(1, 1, m);
      mp[{1, m}] = x - y;
    }

    if (mp[{1, m}] == diff) {
      rr = m;
    } else {
      r = m + 1;
    }
  }

  int l = r - diff + 1;

  cout << "! " << l << " " << r << endl;
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
