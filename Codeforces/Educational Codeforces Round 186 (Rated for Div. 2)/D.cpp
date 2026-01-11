// Problem: D. Christmas Tree Decoration
// Contest: Educational Codeforces Round 186 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2182/problem/D
// Memory Limit: 512
// Time Limit: 2000
// Start: 31-12-2025 20:57:38 WIB

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

const int mx_n = 1000001;
int mod = 998244353;

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

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> arr(n+1);
  for (int i=0; i<=n; i++) cin >> arr[i];

  if (n == 1) {
    return 1LL;
  }

  int mx = *max_element(arr.begin()+1, arr.end());
  int cnt = 0;
  int cnt1 = 0;
  for (int i=1; i<=n; i++) {
    if (arr[i] >= mx) {
      if (arr[i] == mx) cnt++;
      cnt1++;
      continue;
    }
    arr[0] -= mx-1 - arr[i];
    if (arr[0] < 0) return 0LL;
    arr[i] = mx-1;
  }

  return (1 + min(arr[0], n - cnt1))*(fac[cnt] * fac[n-cnt]) % mod;
}

void initialize()
{
  precompute();

  // vector<int> arr(4, 0);
  // int idx = 0;
  // while (arr.back() != 3) {
  //   cout << 3 << el;
  //   arr[1 + idx]++;
  //   for (int i : arr) cout << i << ' ';
  //   cout << el;
  //   idx = (idx + 1) % 3;
  // }
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
