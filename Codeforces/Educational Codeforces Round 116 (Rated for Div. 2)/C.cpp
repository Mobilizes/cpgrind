// Problem: C. Banknotes
// Contest: Educational Codeforces Round 116 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/1606/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 11-10-2025 14:17:45 WIB

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
  ll n, k; cin >> n >> k;
  array<int, 10> arr;
  arr.fill(0);

  for (int i=0; i<n; i++) {
    int x; cin >> x;
    arr[x] = 10;
  }

  int lst = 0;
  for (int i=0; i<10; i++) {
    if (arr[i] != 10) {
      arr[i] = lst;
    } else {
      lst = i;
    }
  }

  ll res = 0;
  ll curr = 0;
  ll cnt = k + 1;
  for (int i=0; i<10; i++) {
    if (i<9 && arr[i+1] != 10 && arr[i] != 10) continue;
    if (i == 9 && arr[i] != 10) continue;
    ll pow10 = 1;
    for (int j=0; j<i; j++) pow10 *= 10;
    ll req = 9;
    for (int j=arr[i]; j<i; j++) {
      req *= 10;
      req += 9;
    }

    res = max(res, cnt * pow10 + curr);

    if (cnt >= req) {
      curr += req * pow10;
      cnt -= req;
    } else {
      curr += cnt;
      cnt = 0;
    }
  }

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
