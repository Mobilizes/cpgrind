// Problem: B. Split
// Contest: Codeforces Round 1067 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2158/problem/B
// Memory Limit: 256
// Time Limit: 1000
// Start: 29-11-2025 21:43:55 WIB

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
  vector<pii> arr(2*n+1);
  for (int i=1; i<=2*n; i++) arr[i].second = i;
  for (int i=1; i<=2*n; i++) {
    int x; cin >> x;
    arr[x].first++;
  }

  sort(all(arr));

  vector<int> l, r;
  for (int i=0; i<=2*n; i++) {
    int v = arr[i].first;
    if (v == 0) continue;
    // cout << v << " " << arr[i].second << "; ";
    l.push_back(arr[i].second);
    for (int j=0; j<v-1; j++) r.push_back(arr[i].second);
  }

  for (int i=r.size()-1; i>=n; i--) {
    l.push_back(r[i]);
    r.erase(r.end());
  }

  for (int i=l.size()-1; i>=n; i--) {
    r.push_back(l[i]);
    l.erase(l.end());
  }

  // for (int i : l) cout << i << " ";
  // cout << "; ";
  // for (int i : r) cout << i << " ";
  // cout << "; ";

  int res = 0;
  bool flag = true;
  for (int i=1; i<l.size(); i++) {
    if (l[i-1] != l[i]) {
      res += flag;
      flag = false;
    }
    flag = !flag;
  }

  res += flag;

  flag = true;
  for (int i=1; i<r.size(); i++) {
    if (r[i-1] != r[i]) {
      res += flag;
      flag = false;
    }
    flag = !flag;
  }

  res += flag;

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
