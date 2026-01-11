// Problem: D. From 1 to Infinity
// Contest: Codeforces Round 1043 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2132/D
// Memory Limit: 256
// Time Limit: 1500
// Start: Fri 22 Aug 2025 09:13:46 PM WIB

#include <bits/stdc++.h>
#include <algorithm>

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

array<ll, 17> dgts;
array<ll, 17> a;

ll sumdigits(ll n) {
  if (n < 10) return (n * (n+1)) / 2;

  ll d = log10(n);
  ll p = ceil(pow(10, d));
  ll msd = n / p;

  return (msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) + sumdigits(n % p));
}

auto solve(int tecs=-1)
{
  ll k; cin >> k;

  if (k < 10) {
    cout << k*(k+1)/2 << el;
    return;
  }

  int idx;
  for (idx=1; idx<=17; idx++) {
    if (dgts[idx] > k) {
      idx--;
      break;
    }
  }

  ll curr = k - dgts[idx];
  ll digit = idx+2;

  ll progress = curr % digit;
  curr /= digit;

  string nines = "";
  for (int i=0; i<digit-1; i++) nines += '9';
  curr += nines.empty() ? 0 : stoll(nines);

  ll res = sumdigits(curr);

  string s = to_string(curr+1);
  for (int i=0; i<progress; i++) res += s[i] - '0';

  cout << res << el;
}

void initialize()
{
  for (ll i=1; i<=17; i++) {
    ll dgtsum = 9;
    for (int j=1; j<i; j++) dgtsum *= 10;
    dgts[i-1] = (dgtsum * i + (i > 1 ? dgts[i-2] : 0));
  }

  a[0] = 0;
  a[1] = 45;
  for (int i = 2; i <= 17; i++) a[i] = a[i - 1] * 10 + 45 * (ll)(ceil(pow(10, i - 1)));
}

template <typename T>
void call_solve(T f, int tecs = -1)
{
  if (is_testcases) {
    using ret = invoke_result_t<decltype(f), int>;
    if constexpr (is_same_v<ret, bool>) {
      cout << (f(tecs) ? "YES" : "NO") << el;
    } else if constexpr (is_same_v<ret, void>) {
      f(tecs);
    } else {
      static_assert(is_same_v<ret, void> || is_same_v<ret, bool>, "solve() has to be bool or void");
    }
  }
}

int main()
{
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
