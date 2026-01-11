// Problem: D. Yet Another Array Problem
// Contest: Codeforces Round 1062 (Div. 4)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2167/problem/d
// Memory Limit: 256
// Time Limit: 2000
// Start: 28-10-2025 21:45:48 WIB

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

const int mxn = 100000;
vector<bool> sieve;
vector<int> primes;

auto solve(int tecs = -1)
{
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  int mn = INT_MAX;
  for (int i=0; i<n; i++) {
    for (int j : primes) {
      if (gcd(j, arr[i]) == 1) {
        mn = min(mn, j);
        break;
      }
    }
  }

  return mn;
}

// clang-format off
void initialize()
{
  sieve.assign(mxn, true);
  for (int i=2; i*i<mxn; i++) {
    if (sieve[i]) primes.push_back(i);
    for (int j=i*i; j<mxn; j+=i) sieve[j] = false;
  }
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
  } else if constexpr (is_integral_v<ReturnValue> || is_same_v<ReturnValue, string>) {
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
