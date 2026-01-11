// Problem: D. Kevin and Numbers
// Contest: IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2061/problem/D
// Memory Limit: 256
// Time Limit: 2000
// Start: 28-11-2025 01:07:45 WIB

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

bool possible(int v, int i, map<int, int>& mp) {
  if (v == 0) return false;
  if (v == 1 && mp[v] == 0) return false;
  if (mp[v] > 0) {
    mp[v]--;
    return true;
  }

  return possible(v / 2, v / 2, mp) && possible(i - v / 2, i - v / 2, mp);
}

auto solve(int tecs = -1)
{
  int n, m; cin >> n >> m;
  map<int, int> a;
  vector<int> b(m);
  for (int i=0; i<n; i++) {
    int x; cin >> x;
    a[x]++;
  }
  for (int i=0; i<m; i++) {
    cin >> b[i];
  }

  for (int i=0; i<m; i++) {
    if (!possible(b[i], b[i], a)) return false;
  }

  for (auto i : a) {
    // cout << i.first << ' ' << i.second << el;
    if (i.second) return false;
  }

  return true;
}

// 1 1 1 1
// 4
// YES
//
// 1 2 3 4
// 3 5
//
// finding x+y = b_i, means you need to find if x is possible in a, x is b_i//2, then y is b_i - x
// after finding b_i, combine all the a_i that is < than b_i - 1, if partner is compatible with x, skip

void initialize()
{
}

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "Yes" : "No") << el;
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
