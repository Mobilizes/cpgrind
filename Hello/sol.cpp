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

int n, m, q;
vector<vector<char>> arr(1000, vector<char>(1000));
vector<vector<pii>> br(1000, vector<pii>(1000, {-1, -1}));
vector<vector<int>> dists(1000, vector<int>(1000, INT_MAX));
int si, sj;
int ei, ej;

array<array<int, 2>, 4> dir = {{
  {0, 1},
  {1, 0},
  {-1, 0},
  {0, -1},
}};

array<char, 4> dirc = {'r', 'd', 'u', 'l'};
array<char, 4> dircr = {'l', 'u', 'd', 'r'};

auto solve(int tecs = -1)
{
  // 2 <= n, m <= 1000; 0 <= q <= (n * m) / 2
  cin >> n >> m >> q;

  // a_{i,j} = {'.', '#', 's', 'e'}
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 's') {
        si = i;
        sj = j;
        dists[si][sj] = 0;
      }
      if (arr[i][j] == 'e') {
        ei = i;
        ej = j;
      }
    }
  }

  // 0 < a, c < n; 0 < b, d < m; a != c && b != d;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    br[a][b] = {c, d};
  }

  queue<tuple<int, int, int, int>> q;
  q.push({si, sj, -1, 0});

  while (!q.empty()) {
    auto tp = q.front();
    int i = get<0>(tp), j = get<1>(tp);
    int diridx = get<2>(tp), dist = get<3>(tp);

    for (int i = 0; i < 4; i++) {
      if (diridx == 3 - i) continue;
    }
  }
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
