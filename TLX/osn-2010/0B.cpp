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

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

using u128 = __uint128_t;

void printu128(u128 x)
{
  string test = "";
  while (x) {
    test += x % 10 + '0';
    x /= 10;
  }
  reverse(all(test));
  cout << test << el;
}

vector<u128> fib;

auto solve(int tecs = -1)
{
  u128 x = 0;
  string s; cin >> s;
  u128 pow10 = 1;
  for (int i=s.length()-1; i>=0; i--) {
    x += (u128)(s[i] - '0') * pow10;
    pow10 *= 10;
  }

  for (int i=0; i<fib.size(); i++) {
    if (x < fib[i]) return 0;
    if (x == fib[i]) return i+1;
  }

  return 0;
}

void initialize()
{
  fib.push_back(0);
  fib.push_back(1);
  int i = 1;
  while (fib[i] + fib[i-1] <= 1e30) {
    fib.push_back(fib[i] + fib[i-1]);
    i++;
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
