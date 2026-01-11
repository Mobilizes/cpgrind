// Problem: C. Building Permutation
// Contest: Codeforces Round 175 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/285/C
// Memory Limit: 256
// Time Limit: 1000
// Start: 31-12-2025 22:21:29 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];
  sort(all(arr));

  vector<int> exi(n+1, 0);
  for (int i=0; i<n; i++) {
    if (arr[i] > 0 && arr[i] <= n) exi[arr[i]]++;
  }

  ll res = 0;
  int v = 1;
  for (int i=0; i<n; i++) {
    while (exi[v] >= 1) v++;
    if (arr[i] > 0 && arr[i] <= n) {
      if (exi[arr[i]] == 1) continue;
      exi[arr[i]]--;
    }
    res += abs(v - arr[i]);
    exi[v]++;
  }

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
