    #include <iostream>
    #include <vector>
    #include <string>
    #include <queue>
    #include <stack>
    #include <set>
    #include <functional>
    #include <algorithm>
    #include <math.h>
    #include <map>
    using namespace std;
    int main()
    {
        ios_base ::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int a, b, c, d;
        int n, m, t;
        
        cin >> n; // tree로 생각을 함. prim 알고리즘 이용
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<vector<int>> graph(n);
        vector<bool> visit(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i].push_back(v[i]^v[j]);
            }
        }
        int visited=0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        long long ans=0;
        while(visited<n){
            int dis = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if(visit[cur])continue;
            else{
                visit[cur]=1;
                visited++;
                ans += dis;
                for(int i=0;i<n;i++){
                    if(!visit[i])
                        pq.push({graph[cur][i], i});
                }
            }
        }
        cout << ans;

        return 0;
    }