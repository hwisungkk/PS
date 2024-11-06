#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m=0;
    int k, a, b, t;
    int arr[2000];
    string s;
    char ch;
    int max = -1000000000;
    int min = 1000000000;
    char car[3030][3030] = {};
    int ar[3030][3030] = {0};
    int nu[3035][3030] = {0};
    int nu2[3030][3030] = {0};
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> car[i][j];
            if((i+j)%2==0){
                if(car[i][j]=='B'){
                    ar[i][j] = 1;
                }
                else{
                    ar[i][j] = 0;
                }
            }
            else{
                if(car[i][j]=='W'){
                    ar[i][j] = 1;
                }
                else{
                    ar[i][j] = 0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            nu[i][j] = nu[i][j-1] + ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            nu2[i][j] = nu2[i-1][j] + nu[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //        cout << nu2[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    k--;
    for(int i=1;i<=n-k;i++){
        for(int j=1;j<=m-k;j++){
            t = nu2[i+k][j+k] - nu2[i-1][j+k] - nu2[i+k][j-1] + nu2[i-1][j-1];
            //cout << "t: " << t << '\n';
            if(max < t){
                max = t;
            }
            if(min > t){
                min = t;
            }
        }
    }
    k++;
    if(min < k*k-max){
        cout << min;
    }
    else{
        cout << k*k-max;
    }
    return 0;
}