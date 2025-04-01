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
        long long mod = 1000000007;

        vector<vector<long long>> v(2, vector<long long>(2));
        vector<vector<long long>> ans(2, vector<long long>(2, 0));

        v[0][0]=1;
        v[0][1]=1;
        v[1][0]=1;
        v[1][1]=0;

        ans[0][0]=1;
        ans[1][1]=1;

        cin >> n;
        
        while(n>0){
            if(n%2==1){
                vector<vector<long long>> tmp(2, vector<long long>(2, 0));
                for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++){
                        for(int k=0;k<2;k++){
                            tmp[i][j] += ans[i][k]*v[k][j];
                            tmp[i][j] %= mod;
                        }
                    }
                }
                ans = tmp;
            }
            vector<vector<long long>> tmp(2, vector<long long>(2, 0));
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<2;k++){
                        tmp[i][j] += v[i][k]*v[k][j];
                        tmp[i][j] %= mod;
                    }
                }
            }
            v = tmp;
            n/=2;
        }
        cout << ans[0][1];

        return 0;
    }