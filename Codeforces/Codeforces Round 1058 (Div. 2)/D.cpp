// Problem: D. MAD Interactive Problem
// Contest: Codeforces Round 1058 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2160/problem/D
// Memory Limit: 256
// Time Limit: 2000
// Start: 12-10-2025 23:27:10 WIB

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

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> pos(n+1);
  vector<int> res(n*2);

  int cnt;
  vector<int> q = {1};
  for (int i=2; i<=2*n; i++) {
    q.push_back(i);
    cout << "? " << q.size();
    for (int j : q) cout << " " << j;
    cout << el;
    cout.flush();

    cin >> cnt;
    if (cnt != 0) {
      q.pop_back();
      pos[cnt] = i;
      res[i-1] = cnt;
    }
  }

  for (int i : q) {
    cout << "? " << n+1;
    for (int j=1; j<=n; j++) cout << " " << pos[j];
    cout << " " << i << el;
    cout.flush();

    cin >> cnt;
    res[i-1] = cnt;
  }
  cout << el;

  cout << "! ";
  for (int i=0; i<n*2; i++) {
    cout << res[i] << ' ';
  }
  cout << el;
  cout.flush();
}

// clang-format off
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
