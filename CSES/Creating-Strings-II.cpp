// Problem: Creating Strings II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1715
// Memory Limit: 512
// Time Limit: 1000
// Start: 16-11-2025 21:02:23 WIB

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
#define all(a) begin(a), end(a)

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

const int mx_n = 1000000;
int mod = 1000000007;

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
  string s; cin >> s;
  int n = s.length();
  // cout << 1 << ' ';
  // for (int ln = 1; ln <= n; ln++) {
  //   map<string, bool> mp;
  //   for (int i = 0; i < (1 << ln); i++) {
  //     string t;
  //     for (int j = 0; j < n; j++) {
  //       if ((i & (1 << j)) != 0) continue;
  //       t += s[j];
  //     }
  //     mp[t] = true;
  //   }
  //
  //   cout << mp.size() << ' ';
  // }
  // cout << el;

  // vector<int> exists('z'+1, -1);
  // vector<ll> dp(n+1);
  // dp[0] = 1;
  // for (int i=1; i<=n; i++) {
  //   dp[i] = dp[i-1];
  //   if (exists[s[i-1]] == -1) {
  //     dp[i] *= 2;
  //   } else {
  //     dp[i] += ((dp[i-1] - dp[exists[s[i-1]] - 1]) + mod) % mod;
  //   }
  //   dp[i] %= mod;
  //   exists[s[i-1]] = i;
  //
  //   cout << dp[i] << ' ';
  // }
  //
  // return dp[n];

  vector<int> cnt('z'+1, 0);
  for (int i=0; i<n; i++) cnt[s[i]]++;
  ll res = fac[n];
  for (int i='a'; i<='z'; i++) {
    res *= inv[cnt[i]];
    res %= mod;
  }
  return res;

  // for (auto i : mp) cout << i.F << el;

  // return mp.size();
}

void initialize()
{
  precompute();
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
