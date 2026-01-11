// Problem: Digit Queries
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2431
// Memory Limit: 512
// Time Limit: 1000
// Start: 06-12-2025 21:50:17 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

array<ll, 21> pos;
array<ll, 21> nine;

auto solve(int tecs = -1)
{
  ll k; cin >> k;
  // if (k < 10) return k;
  int i;
  for (i=16; i>=0; i--) {
    if (pos[i] < k) {
      break;
    }
  }
  ll n = k - pos[i];
  ll d = i + 1;
  ll next = (n + d - 1) / d;
  ll curr = nine[d-1] + next;
  ll idx = (n-1) % d;
  return to_string(curr)[idx];
}

void initialize()
{
  pos[1] = 9;
  nine[1] = 9;
  ll ten = 10;
  for (int i=2; i<=16; i++) {
    pos[i] = 9 * ten * i + pos[i-1];
    nine[i] = 9 * ten + nine[i-1];
    ten *= 10;
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
