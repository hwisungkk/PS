#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, n, m;
int in_degree[501];
bool adj[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> last_year(n);
        for (int i = 0; i < n; ++i) {
            cin >> last_year[i];
        }

        // 그래프 초기화
        memset(adj, false, sizeof(adj));
        memset(in_degree, 0, sizeof(in_degree));

        // 작년 순위 기반 간선 추가
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                adj[last_year[i]][last_year[j]] = true;
                in_degree[last_year[j]]++;
            }
        }

        cin >> m;
        bool inconsistent = false;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;

            // 간선 방향 변경
            if (adj[a][b]) {
                adj[a][b] = false;
                in_degree[b]--;
                adj[b][a] = true;
                in_degree[a]++;
            } else if (adj[b][a]) {
                adj[b][a] = false;
                in_degree[a]--;
                adj[a][b] = true;
                in_degree[b]++;
            } else {
                // 간선이 없으면 모순된 정보
                inconsistent = true;
            }
        }

        if (inconsistent) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        // 위상 정렬
        queue<int> q;
        vector<int> result;
        bool ambiguous = false;

        // 진입차수 0인 노드 큐에 삽입
        for (int i = 1; i <= n; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }

        for (int i = 0; i < n; ++i) {
            if (q.empty()) {
                cout << "IMPOSSIBLE\n";
                break;
            }
            if (q.size() > 1) {
                ambiguous = true;
            }

            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v = 1; v <= n; ++v) {
                if (adj[u][v]) {
                    adj[u][v] = false;
                    if (--in_degree[v] == 0) {
                        q.push(v);
                    }
                }
            }

            if (i == n - 1) {
                if (ambiguous) {
                    cout << "?\n";
                } else {
                    for (int j = 0; j < n; ++j) {
                        cout << result[j] << ' ';
                    }
                    cout << '\n';
                }
            }
        }
    }

    return 0;
}
