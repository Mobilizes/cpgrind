#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

const bool is_testcases = false;
const bool desync_stdio = false;

auto solve(int tecs=-1)
{
  string s; cin >> s;
  int n = s.length();

  int osn = 0;
  int res = -1;
  int curr = 0;
  int no_p = 0;

  for (char c : s) {
    if (c == 'P') curr++;
  }

  for (int i=0; i<n; i++) {
    if (s[i] == 'O') osn |= 1;
    if (s[i] == 'S') osn |= 2;
    if (s[i] == 'N') osn |= 4;

    if (s[i] == 'O' || s[i] == 'S' || s[i] == 'N') {
      no_p++;
    }

    if (s[i] == 'P' && osn == 7) {
      res = max(res, no_p + curr);
    }

    if (s[i] == 'P') {
      curr--;
    }
  }

  cout << res << el;
}

void initialize()
{
}

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
