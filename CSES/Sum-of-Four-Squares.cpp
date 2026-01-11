// Problem: Sum of Four Squares
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3355
// Memory Limit: 512
// Time Limit: 1000
// Start: 19-11-2025 08:32:13 WIB

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

const int mx_n = 10000005;

vector<int> primes;
unordered_map<ll, array<ll, 4>> mp;

using u64 = __uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod)
{
  u64 result = 1;
  base %= mod;
  while (e) {
    if (e & 1) result = (u128)result * base % mod;
    base = (u128)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
  u64 x = binpower(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int r = 1; r < s; r++) {
    x = (u128)x * x % n;
    if (x == n - 1) return false;
  }
  return true;
};

bool MillerRabin(u64 n)
{
  if (n < 2) return false;

  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}

array<ll, 4> sumofsquares(ll n) {
  if (!mp[n].empty()) return mp[n];

  for (int i=0; i*i<=n; i++) {
    for (int j=0; i*i+j*j<=n; j++) {
      for (int k=0; i*i+j*j+k*k<=n; k++) {
        for (int l=0; i*i+j*j+k*k+l*l<=n; l++) {
          if (i*i + j*j + k*k + l*l == n) {
            return mp[n] = {i, j, k, l};
          }
        }
      }
    }
  }

  throw runtime_error("math is a lie");
}

array<ll, 4> combine(array<ll, 4> & a, array<ll, 4> b)
{
// c1 = abs(a1b1 - a2b2 - a3b3 - a4b4)
// c2 = abs(a1b2 + a2b1 + a3b4 - a4b3)
// c3 = abs(a1b3 - a2b4 + a3b1 + a4b2)
// c4 = abs(a1b4 + a2b3 - a3b2 + a4b1)
  return {
    abs(a[0]*b[0] - a[1]*b[1] - a[2]*b[2] - a[3]*b[3]),
    abs(a[0]*b[1] + a[1]*b[0] + a[2]*b[3] - a[3]*b[2]),
    abs(a[0]*b[2] - a[1]*b[3] + a[2]*b[0] + a[3]*b[1]),
    abs(a[0]*b[3] + a[1]*b[2] - a[2]*b[1] + a[3]*b[0]),
  };
}

auto solve(int tecs = -1)
{
  ll n; cin >> n;
  if (!mp[n].empty()) {
    return mp[n];
  }

  // for (int i=0; i*i<=n; i++) {
  //   for (int j=0; j*j<=n; j++) {
  //     for (int k=0; k*k<=n; k++) {
  //       for (int l=0; l*l<=n; l++) {
  //         if (i*i+j*j+k*k+l*l == n) {
  //           cout << i << ' ' << j << ' ' << k << ' ' << l << el;
  //           return;
  //         }
  //       }
  //     }
  //   }
  // }
}

// lagrange four squares theorem:
// split n to 2, p and q
// p = (a1^2 + a2^2 + a3^2 + a4^2)
// q = (b1^2 + b2^2 + b3^2 + b4^2)
// pq = (c1^2 + c2^2 + c3^2 + c4^2)
// c1 = abs(a1b1 - a2b2 - a3b3 - a4b4)
// c2 = abs(a1b2 + a2b1 + a3b4 - a4b3)
// c3 = abs(a1b3 - a2b4 + a3b1 + a4b2)
// c4 = abs(a1b4 + a2b3 - a3b2 + a4b1)
//
// amazing resource: https://youtu.be/Q95PB_Dcjoo?si=7ky3cxJ2NLUVds70&t=1052
//
// 12: 4*3
// 4: 2 0 0 0
// 3: 1 1 1 0
// 12: 2 2 2 0
//
// 55: 5*11
// 5: 2 1 0 0
// 11: 3 1 1 0
// 55: 5 5 2 1
//
// 5: 2 1 0 0
// 11: 1 3 1 0
// 55: 1 7 2 1

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
  vector<bool> sv = sieve(sqrt(mx_n));
  for (int i=2; i<sv.size(); i++) {
    if (sv[i]) primes.push_back(i);
  }

  mp[1] = {1, 0, 0, 0};
  mp[2] = {1, 1, 0, 0};

  // primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 57};

  // for (int p : primes) {
  //   for (int i=0; i*i<=p; i++) {
  //     for (int j=0; i*i+j*j<=p; j++) {
  //       for (int k=0; i*i+j*j+k*k<=p; k++) {
  //         for (int l=0; i*i+j*j+k*k+l*l<=p; l++) {
  //           if (i*i + j*j + k*k + l*l == p) {
  //             mp[p] = {i, j, k, l};
  //           }
  //         }
  //       }
  //     }
  //   }
  //   cout << p << ' ';
  // }
  // cout << el;
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
