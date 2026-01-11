// Problem: C. Bewitching Stargazer
// Contest: Good Bye 2024: 2025 is NEAR
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2053/C
// Memory Limit: 256
// Time Limit: 2000

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

ll n, k;

auto solve(int tecs = -1)
{
  cin >> n >> k;
  ll res = 0, cnt = 1;
  ll tn = n;
  while (tn >= k) {
    if (tn & 1) res += cnt;
    tn >>= 1;
    cnt <<= 1;
  }

  cout << (n+1) * res / 2 << el;
}

void initialize() {}

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else {
    static_assert(is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool>,
      "solve() has to be bool or void");
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

// 1 2 3 4 5 6 7 8 9 10 11   
// 1 2 3 4 5   7 8 9 10 11   6
// 1 2   4 5   7 8   10 11   6 + (3 + 9)=12
//
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 1 2 3 4 5 6 7   9 10 11 12 13 14 15  8  // it 1
// 1 2 3   5 6 7   9 10 11    13 14 15  8 + (4 + 12)=16  // it 2
// 1   3   5   7   9    11    13    15  8*1 + (4 + 12)=16=2*8 + (2 + 6 + 10 + 14)=32=4*8  // it 3 k = 2
//
// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 4 5   6 7 8 9 10
// 1 2   4 5   6 7   9 10  2
//
//
// 1 2 3 4 5 6 7 8 9 10 11 12
// 1 2 3 4 5 6   7 8 9 10 11 12
// 1 2 3   4 5 6   7 8 9    10 11 12 
// 1   3   4   6   7   9    10    12 = 2 + 5 + 8 + 11 = 26 = 2 * 13
