#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n, m, k;
vvl A, B;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m;

  A = vvl(n, vl(m));
  for (auto&& r : A) {
    for (auto&& x : r) {
      cin >> x;
    }
  }

  cin >> m >> k;

  B = vvl(m, vl(k));
  for (auto&& r : B) {
    for (auto&& x : r) {
      cin >> x;
    }
  }

  auto ans = vvl(n, vl(k));
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < k; ++j) {
      ans[i][j] = 0;
      for (auto u = 0; u < m; ++u) {
        ans[i][j] += A[i][u] * B[u][j];
      }
    }
  }

  for (const auto& r : ans) {
    for (const auto& x : r) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}