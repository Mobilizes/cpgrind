// Problem: C. Monocarp's String
// Contest: Educational Codeforces Round 183 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2145/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 06-10-2025 21:58:35 WIB

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
  string s; cin >> s;

  int ta = 0, tb = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == 'a') ta++;
    if (s[i] == 'b') tb++;
  }

  if (ta == tb) {
    return 0;
  }
  
  // abaa
  // 1 0, 0 0, 1 0, 2 0

  vector<pair<int, int>> arr(n);
  arr[0] = {s[0] == 'a', s[0] == 'b'};
  for (int i=1; i<n; i++) {
    arr[i] = arr[i-1];
    if (s[i] == 'a') {
      arr[i].first++;
    }
    if (s[i] == 'b') {
      arr[i].second++;
    }
  }


  int res = INT_MAX;
  int l = 0, r = 0;
  int diff;

  while (r < n - 1 || l < r) {
    int a = arr[r].first;
    int b = arr[r].second;

    if (l > 0) {
      a -= arr[l - 1].first;
      b -= arr[l - 1].second;
    }

    if (ta > tb) {
      diff = ta - tb - a + b;
    } else {
      diff = tb - ta - b + a;
    }

    if (diff == 0) {
      res = min(res, r - l + 1);
    }

    if (ta > tb) {
      if (ta - tb - a == 0 && diff != 0) {
        if (l == r && r < n - 1) {
          r++;
        } else {
          l++;
        }
      } else {
        if (r < n - 1) {
          r++;
        } else {
          l++;
        }
      }
    } else {
      if (ta - tb - b == 0 && diff != 0) {
        if (l == r && r < n - 1) {
          r++;
        } else {
          l++;
        }
      } else {
        if (r < n - 1) {
          r++;
        } else {
          l++;
        }
      }
    }
  }

  if (res == INT_MAX) res = -1;
  if (res == n) res = -1;
  return res;

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
