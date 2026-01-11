// Problem: C. Binary Search
// Contest: Codeforces Round 678 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/1436/problem/C
// Memory Limit: 256
// Time Limit: 1000
// Start: 08-10-2025 11:13:41 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;

const int mx_n = 1001;
int mod = 1e9 + 7;

ll fac[mx_n + 1], inv[mx_n + 1];

ll power(ll x, ll y) {
    ll res = 1;
    x %= mod;
    while(y) {
        if(y & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y = y >> 1;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for(int i = 1; i <= mx_n; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv[mx_n] = power(fac[mx_n], mod - 2);
    for(int i = mx_n; i >= 1; i--) {
        inv[i - 1] = (inv[i] * i) % mod;
    }
}

ll choose(int n, int k) {
    return (((fac[n] * inv[k]) % mod) * inv[n - k]) % mod;
}

// clang-format off
auto solve(int tecs = -1)
{
  int n, x, pos;
  cin >> n >> x >> pos;

  int less = 0, more = 0;
  int l=1, r=n;
  while (l < r) {
    int m = (l + r) / 2;
    if (m <= pos) {
      l = m+1;
      if (l-1 != pos) less++;
    } else {
      r = m;
      if (l-1 != pos) more++;
    }
  }

  cout << less << " " << more << el;
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
