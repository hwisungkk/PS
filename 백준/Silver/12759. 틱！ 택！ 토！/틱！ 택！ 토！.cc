#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<map>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c=0, total=0;
    char ch;
    long long count=0;
    int ma = -1000;
    int n, m, z=1;
    int dp[10000]={0};
    int ar[3][3]={0};
    vector <int> v1;
    vector <int> v2;
    string s;
    cin >> n;
    for(int i=0;i<9;i++){
        cin >> a >> b;
        if(i%2==0)ar[a-1][b-1]=1;
        else ar[a-1][b-1]=2;
        if((ar[0][0]!=0&&(ar[0][0]==ar[0][1]&&ar[0][0]==ar[0][2])) || (ar[1][0]!=0&&(ar[1][0]==ar[1][1]&&ar[1][0]==ar[1][2]))
        || (ar[2][0]!=0&&(ar[2][0]==ar[2][1]&&ar[2][0]==ar[2][2])) || (ar[0][0]!=0&&(ar[1][0]==ar[2][0]&&ar[1][0]==ar[0][0]))
        || (ar[0][1]!=0&&(ar[0][1]==ar[1][1]&&ar[0][1]==ar[2][1])) || (ar[0][2]!=0&&(ar[0][2]==ar[1][2]&&ar[0][2]==ar[2][2]))
        || (ar[0][0]!=0&&(ar[0][0]==ar[1][1]&&ar[0][0]==ar[2][2])) || (ar[0][2]!=0&&(ar[0][2]==ar[1][1]&&ar[0][2]==ar[2][0]))){
            if(n==1) {
                cout << ar[a-1][b-1];
            }
            else {
                if(ar[a-1][b-1]==1)cout << 2;
                else cout << 1;
            }  
            return 0;
        }
        
        if(i==8){
            cout<<0;
            return 0;
        }
    }
    return 0;
}