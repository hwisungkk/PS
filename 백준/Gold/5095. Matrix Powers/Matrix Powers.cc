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
        bool flag=1;

        while(1){
            cin >> n >> m >> t;
            if(!n && !m && !t)break;

            vector<vector<long long>> a(n, vector<long long>(n));
            vector<vector<long long>> ans(n, vector<long long>(n, 0));

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cin >> a[i][j];
                }
                ans[i][i]=1;
            }

            function<void(vector<vector<long long>>&, vector<vector<long long>>&)> matrix =
            [&](vector<vector<long long>>& m1, vector<vector<long long>>& m2) {
                vector<vector<long long>> temp(n, vector<long long>(n, 0));
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                            temp[i][j] += m1[i][k] * m2[k][j];
                            temp[i][j]%=m;
                        }
                    }
                }
                m1 = temp;
            };

            while(t>0){
                if(t%2==1){
                    matrix(ans,a);
                }
                matrix(a,a);
                t/=2;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << ans[i][j] << ' ';
                }cout << '\n';
            }
            cout << '\n';
        }

        return 0;
    }