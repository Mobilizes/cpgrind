// Problem: D. OutOfMemoryError
// Contest: Codeforces Round 1074 (Div. 4)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2185/problem/D
// Memory Limit: 256
// Time Limit: 2000
// Start: 18-01-2026 22:02:07 WIB

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
  int n, m, h; cin >> n >> m >> h;
  vector<ll> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  vector<ll> tmp = arr;
  stack<int> stk;

  for (int i=0; i<m; i++) {
    ll idx, v; cin >> idx >> v;
    idx--;
    stk.push(idx);
    tmp[idx] += v;
    if (tmp[idx] > h) {
      while (!stk.empty()) {
        tmp[stk.top()] = arr[stk.top()];
        stk.pop();
      }
    }
  }

  return tmp;
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
