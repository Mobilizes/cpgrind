// Problem: Minimal Grid Path
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3359
// Memory Limit: 512
// Time Limit: 1000
// Start: 27-10-2025 13:04:24 WIB

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

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<string> s(n);
  vector<vector<bool>> arr(n+1, vector<bool>(n+1, false));

  for (int i=1; i<=n; i++) {
    cin >> s[i-1];
  }

  for (int i=0; i<=1; i++) {
    arr[i][0] = true;
    arr[0][i] = true;
  }

  for (int d=1; d<=2*n-1; d++) {
    int j = min(d, n);
    int i = max(d-n+1, 1);
    char mn = 'Z'+1;
    while (i<=n && j>=1) {
      if (arr[i-1][j] || arr[i][j-1]) mn = min(mn, s[i-1][j-1]);
      i++; j--;
    }

    j = min(d, n);
    i = max(d-n+1, 1);
    while (i<=n && j>=1) {
      if (s[i-1][j-1] == mn && (arr[i-1][j] || arr[i][j-1])) arr[i][j] = true;
      i++; j--;
    }
  }

  stack<array<int, 3>> stk;
  stk.push({1, 1, 0});
  string res = "";
  for (int i=0; i<2*n-1; i++) res += '0';

  while (!stk.empty()) {
    auto t = stk.top();
    stk.pop();
    // if (s[t[0]-1][t[1]-1] < 'A') cout << t[0] << ' ' << t[1] << el;
    res[t[2]] = s[t[0] - 1][t[1] - 1];

    if (t[0] == n && t[1] == n) break;

    if (t[0]+1 <= n && arr[t[0]+1][t[1]]) stk.push({t[0]+1, t[1], t[2]+1});
    if (t[1]+1 <= n && arr[t[0]][t[1]+1]) stk.push({t[0], t[1]+1, t[2]+1});
  }

  return res;
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
