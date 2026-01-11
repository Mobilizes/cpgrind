// Problem: C. Subset Multiplication
// Contest: EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2124/C
// Memory Limit: 256
// Time Limit: 3000
// Start: 26-08-2025 09:48:26 WIB

#include <bits/stdc++.h>
#include <numeric>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

const bool is_testcases = true;
const bool desync_stdio = false;

auto solve(int tecs=-1)
{
  int n; cin >> n;
  vector<ll> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  ll res = 1;
  for (int i=0; i<n-1; i++) {
    if (arr[i] == 1 || arr[i+1] == 1) continue;
    if ((arr[i] % arr[i+1] != 0) && (arr[i+1] % arr[i] != 0)) {
      ll mn = min(arr[i], arr[i+1]);
      if (arr[i] == mn) {
        arr[i] *= mn;
      } else {
        arr[i+1] *= mn;
      }
      res *= mn;
    }
  }

  cout << res << el;
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
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else {
    static_assert(is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool>,
      "solve() has to be bool or void");
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
