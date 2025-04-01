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
    long long mod = 1000;

    vector<vector<long long>> v(2, vector<long long>(2));
    vector<vector<long long>> ans(2, vector<long long>(2, 0));
    cin >> t;
    function <void(vector<vector<long long>>&, vector<vector<long long>>&)>
    matrix =[&](vector<vector<long long>>& v1, vector<vector<long long>>& v2){
        vector<vector<long long>> tmp(2, vector<long long>(2,0));

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    tmp[i][j] += v1[i][k]*v2[k][j];
                    tmp[i][j]%=1000;
                }
            }
        }
        v1 = tmp;
    };

    int ca=0;
    while(t-->0){
        ca++;
        v[0][0]=6;
        v[0][1]=-4;
        v[1][0]=1;
        v[1][1]=0;
    
        ans[0][0]=1;
        ans[0][1]=0;
        ans[1][0]=0;
        ans[1][1]=1;

        cin >> n;

        while(n>0){
            if(n%2==1){
                matrix(ans, v);
            }
            matrix(v,v);
            n/=2;
        }
        m = ans[0][0]+ans[1][1]-1;
        m%=1000;
        if(m==0)m=1000;
        if(m<0)m+=1000;

        if(m < 10) cout << "Case #" << ca << ": 00" << m << '\n';
        else if(m < 100) cout << "Case #" << ca << ": 0" << m << '\n';
        else cout << "Case #" << ca << ": " << m << '\n';
    }
    return 0;
}