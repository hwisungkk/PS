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
int n;
int a, b, c;
int red, green, blue;
int mi=1e9;
int ar[30][3]={0};
int check[30]={0};
void back(int k, int st){
    if(k==8)return;
    if(k>=2){
        mi = min(mi, abs(red/k-a)+abs(green/k-b)+abs(blue/k-c));
    }
    if(k==n)return;
    for(int i=st+1;i<n;i++){
        if(check[i]==0){
            red+=ar[i][0];
            green+=ar[i][1];
            blue+=ar[i][2];
            check[i]=1;
            back(k+1, i);
            red-=ar[i][0];
            green-=ar[i][1];
            blue-=ar[i][2];
            check[i]=0;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int t;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> ar[i][j]; 
        }
    }
    cin >> a >> b >> c;
    back(0, -1);
    cout << mi;
    return 0;
}
