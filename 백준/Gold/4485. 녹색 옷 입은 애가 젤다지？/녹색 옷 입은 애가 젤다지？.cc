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
        string s;
        a=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(1){
            int ans=0;
            a++;
            cin >> n;
            if(n==0)break;
            vector<vector<int>> v(n, vector<int>(n, 1e9));
            vector<vector<int>> djk(n, vector<int>(n, 1e9));
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    cin >> v[j][k];
                }
            }
            pair<int, int> p;
            djk[0][0]=v[0][0];
            priority_queue<pair<int, pair<int, int>>> pq;
            pq.push({-v[0][0], {0, 0}}); 

            while(!pq.empty()){
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                int cur = -pq.top().first;
                pq.pop();
                for(int j=0;j<4;j++){
                    if(x+dx[j]>=0 && x+dx[j]<=n-1 && y+dy[j]>=0 && y+dy[j]<=n-1){
                        if(djk[x+dx[j]][y+dy[j]] > cur+v[x+dx[j]][y+dy[j]]){
                            djk[x+dx[j]][y+dy[j]] = cur+v[x+dx[j]][y+dy[j]];
                            pq.push({-djk[x+dx[j]][y+dy[j]], {x+dx[j], y+dy[j]}});
                        }
                    }
                }
            }

            cout << "Problem " << a << ": " << djk[n-1][n-1] << '\n';
        }
        return 0;
    }