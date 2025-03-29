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
        long long n, m, t;
        bool flag=1; 

        cin >> n >> m;

        vector<vector<long long>> v(n, vector<long long>(n));
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }ans[i][i]=1;
        }

        function<void(vector<vector<long long>>&, vector<vector<long long>>&)>
        matrix = [&](vector<vector<long long>> &v1, vector<vector<long long>> &v2){
            vector<vector<long long>> tmp(n, vector<long long>(n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        tmp[i][j] += v1[i][k]*v2[k][j];
                        tmp[i][j]%=1000;
                    }
                }
            }
            v1 = tmp;
        };

        while(m>0){
            if(m%2==1){
                matrix(ans, v);
            }
            matrix(v,v);
            m/=2;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==n-1)cout << ans[i][j];
                else cout << ans[i][j] << ' ';
            }cout << '\n';
        }

        return 0;
    }