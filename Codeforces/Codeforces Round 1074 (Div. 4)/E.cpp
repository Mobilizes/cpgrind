// Problem: E. The Robotic Rush
// Contest: Codeforces Round 1074 (Div. 4)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2185/problem/E
// Memory Limit: 256
// Time Limit: 3000
// Start: 18-01-2026 22:07:41 WIB

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

auto solve(int tecs = -1)
{
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<m; i++) cin >> b[i];
  string s; cin >> s;

  map<int, bool> vis;
  map<int, int> mp;

  vis[0] = true;
  int sum = 0;
  for (int i=0; i<k; i++) {
    if (s[i] == 'L') sum--;
    else sum++;

    if (!vis[sum]) mp[sum] = i;
    vis[sum] = true;
  }
  vis[0] = false;

  // for (auto [i, v] : mp) {
  //   cout << i << ' ' << v << el;
  // }
  // cout << el;

  sort(all(a));
  sort(all(b));

  vector<int> res(k, 0);
  int j = 0;
  for (int i=0; i<n; i++) {
    while (j < m && b[j] < a[i]) j++;
    int l = 0, r = 0;
    if (j > 0) {
      l = b[j-1] - a[i];
    }
    if (j < m) {
      r = b[j] - a[i];
    }
    int mn = k+1;
    if (vis[l]) {
      mn = min(mn, mp[l]);
    }
    if (vis[r]) {
      mn = min(mn, mp[r]);
    }
    if (mn != k+1) {
      res[mn]++;
    }
    // cout << l << ' ' << r << "; ";
  }

  res[0] = n - res[0];
  for (int i=1; i<k; i++) {
    res[i] = res[i-1] - res[i];
  }

  // cout << el;
  return res;
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
