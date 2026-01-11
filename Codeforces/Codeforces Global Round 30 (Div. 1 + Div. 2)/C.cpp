// Problem: C. Dungeon
// Contest: Codeforces Global Round 30 (Div. 1 + Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2164/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 06-11-2025 22:05:54 WIB

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
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  int n, m; cin >> n >> m;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<n; i++) {
    int x; cin >> x;
    pq.push(x);
  }

  vector<pii> b(m);
  for (int i=0; i<m; i++) cin >> b[i].F;
  for (int i=0; i<m; i++) cin >> b[i].S;

  vector<pii> arr, thr;
  for (int i=0; i<m; i++) {
    if (b[i].S == 0) thr.push_back(b[i]);
    else arr.push_back(b[i]);
  }
  
  sort(all(arr));
  sort(all(thr));

  int res = 0;
  int j = 0;
  for (int i=0; i<arr.size(); i++) {
    if (pq.empty()) break;
    while (pq.top() < arr[i].F) {
      // cout << pq.size() << "?" << pq.top() << "-" << arr[i].F << ";" << arr[i].S << ", ";
      if (j < thr.size() && pq.top() >= thr[j].F) {
        // cout << thr[j].F << ", ";
        j++;
        res++;
      }
      pq.pop();
      if (pq.empty()) break;
    }
    if (pq.empty()) break;
    res++;
    pq.push(max(pq.top(), arr[i].S));
    pq.pop();
  }

  for (; j < thr.size(); j++) {
    if (pq.empty()) break;
    if (pq.top() < thr[j].F) break;
    res++;
    // cout << thr[j].F << ", ";
    pq.pop();
  }

  // for (int i=0; i<arr.size(); i++) {
  //   cout << arr[i].F << ' ' << arr[i].S << el;
  // }
  // for (int i=0; i<thr.size(); i++) {
  //   cout << thr[i].F << ' ' << thr[i].S << el;
  // }
  // cout << el;

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
