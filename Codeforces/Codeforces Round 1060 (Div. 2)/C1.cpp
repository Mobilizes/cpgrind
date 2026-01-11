// Problem: C1. No Cost Too Great (Easy Version)
// Contest: Codeforces Round 1060 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2154/problem/C1
// Memory Limit: 256
// Time Limit: 3000
// Start: 28-11-2025 02:47:48 WIB

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

int mx_n = 200000;
vector<int> primes;

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];


}

vector<bool> sieve(int n)
{
  vector<bool> prime(n + 1, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = 0;
      }
    }
  }
  return prime;
}

void initialize()
{
  auto sv = sieve(sqrt(mx_n));
  for (int i=2; i<=sqrt(mx_n); i++) {
    if (sv[i]) primes.push_back(i);
  }
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
