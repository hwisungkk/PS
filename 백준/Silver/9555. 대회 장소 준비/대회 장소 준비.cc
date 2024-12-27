#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    int a, b, c;

    int t = 0;
    cin >> t;
    while(t-->0){
        cin >> a >> b;
        int count =0;
        vector <vector <int>> ar(a+2, vector<int>(b+2, 0));
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                cin >> ar[i][j];
            }
        }
        vector<int> check(101, 0);
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(ar[i][j]>0 && check[ar[i][j]]==0){
                    if(ar[i][j]==ar[i-1][j] || ar[i][j]==ar[i+1][j] || ar[i][j]==ar[i-1][j-1] || ar[i][j]==ar[i-1][j+1] || ar[i][j]==ar[i][j-1] || ar[i][j]==ar[i][j+1] || ar[i][j]==ar[i+1][j-1] || ar[i][j]==ar[i+1][j+1]){
                        check[ar[i][j]]=1;
                    }
                }
            }
        }
        for(int i=1;i<=100;i++){
            if(check[i]==1)count++;
        }
        cout << count << '\n';
    }
    return 0;
}