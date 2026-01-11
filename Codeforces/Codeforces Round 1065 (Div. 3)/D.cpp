// Problem: D. Rae Taylor and Trees (easy version)
// Contest: Codeforces Round 1065 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2171/problem/D
// Memory Limit: 256
// Time Limit: 3000
// Start: 20-11-2025 22:41:09 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

struct dsu
{
public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b)
  {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b)
  {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a)
  {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a)
  {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups()
  {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(std::remove_if(result.begin(), result.end(),
                   [&](const std::vector<int> & v) { return v.empty(); }),
      result.end());
    return result;
  }

private:
  int _n;
  std::vector<int> parent_or_size;
};

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> arr(n);
  for (int i=0; i<n; i++) cin >> arr[i];
  dsu tr(n+1);
  priority_queue<int, vector<int>, greater<int>> pq;
  int mn = arr[0];
  tr.merge(0, mn);
  pq.push(mn);
  for (int i=1; i<n; i++) {
    int x = arr[i];
    if (x > mn) {
      tr.merge(mn, x);
    } else pq.push(x);

    while (!pq.empty() && pq.top() < x) {
      tr.merge(pq.top(), x);
      mn = min(mn, pq.top());
      pq.pop();
    }

    if (x > mn) {
      pq.push(mn);
      mn = min(mn, x);
    }
  }

  // dsu tr2(n+1);
  // tr2.merge(0, arr[0]);
  // for (int i=0; i<n; i++) {
  //   for (int j=i+1; j<n; j++) {
  //     if (arr[i] < arr[j]) tr2.merge(arr[i], arr[j]);
  //   }
  // }

  // for (auto g : tr.groups()) {
  //   for (int i : g) cout << i << ' ';
  //   cout << el;
  // }
  // cout << el;

  // while (!pq.empty()) {
  //   cout << pq.top() << ' ';
  //   pq.pop();
  // }
  // cout << el;

  return tr.groups().size() == 1;
  // if (tr.groups().size() != tr2.groups().size()) return arr;
  // else return vector<int>(0);
}

void initialize()
{
  // vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  // cout << 720*7 << el;
  // do {
  //   cout << 7 << ' ';
  //   for (int i : arr) cout << i << ' ';
  //   cout << el;
  // } while (next_permutation(all(arr)));
}

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "Yes" : "No") << el;
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
