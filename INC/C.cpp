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
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) cin >> arr[i];

  bool flag = true;
  for (int i = 1; i < n; i++) flag &= arr[i] == arr[i - 1];
  if (flag) return 0;

  // if (n == 1) return 0;

  int res = 0;
  bool down = arr[1] < arr[0];
  int i;
  for (i=1; i<n; i++) {
    res++;
    if (arr[i] != arr[i-1]) {
      down = arr[i] < arr[i-1];
      break;
    }
  }

  for (; i < n; i++) {
    if (down && arr[i] > arr[i - 1]) {
      // cout << "up" << el;
      res++;
      down = !down;
    } else if (!down && arr[i] < arr[i - 1]) {
      // cout << "down" << el;
      res++;
      down = !down;
    } else if (arr[i] == arr[i - 1]) {
      // cout << "same" << el;
      res++;
      down = !down;
    }
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
