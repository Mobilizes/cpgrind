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
  double dx; cin >> dx;
  ll l, r; cin >> l >> r;

  ll f = floor(dx);
  ll c = ceil(dx);

  if (f < l || c > r) {
    cout << -1 << el;
    return;
  }

  int idx = 1;
  while (fmod(dx, 1) > 1e-6) {
    dx *= 10;
    idx *= 10;
  }
  ll x = dx;
  ll g = gcd(x, idx);
  x /= g;
  idx /= g;

  ll csum = c * idx;
  ll fcnt = csum - x;

  cout << idx << el;
  for (int i=0; i<fcnt; i++) cout << f << ' ';
  for (int i=fcnt; i<idx; i++) cout << c << ' ';
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
