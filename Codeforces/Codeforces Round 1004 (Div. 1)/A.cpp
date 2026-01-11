// Problem: A. Object Identification
// Contest: Codeforces Round 1004 (Div. 1)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2066/problem/A
// Memory Limit: 256
// Time Limit: 2000
// Start: 08-10-2025 00:53:44 WIB

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

const bool is_testcases = true;
const bool desync_stdio = false;

// clang-format off
auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  vector<int> flag(n+1, -1);
  for (int i=0; i<n; i++) {
    flag[arr[i]] = i + 1;
  }

  int q1, q2;
  for (int i=1; i<=n; i++) {
    if (flag[i] == -1) {
      int j = max(1, i - 1);
      while (flag[j] == -1) j++;

      cout << "? " << i << " " << j << el;
      cout.flush();

      cin >> q1;
      if (q1 == 0) {
        cout << "! A" << el;
      } else {
        cout << "! B" << el;
      }
      cout.flush();

      return;
    }
  }

  cout << "? " << flag[1] << " " << flag[n] << el;
  cout.flush();

  cin >> q1;
  if (q1 == 0) {
    cout << "! A" << el;
    return;
  }

  cout << "? " << flag[n] << " " << flag[1] << el;
  cout.flush();

  cin >> q2;
  if (q2 == 0) {
    cout << "! A" << el;
    return;
  }

  if (q1 != q2) {
    cout << "! A" << el;
  } else {
    if (q1 < n - 1) {
      cout << "! A" << el;
    } else {
      cout << "! B" << el;
    }
  }
}

void initialize()
{
}
// clang-format on

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else if constexpr (is_integral_v<ReturnValue>) {
    cout << f(tecs) << el;
  } else {
    static_assert(
      is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool> || is_integral_v<ReturnValue>,
      "solve() return type is not supported");
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
