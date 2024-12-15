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
int k, n;
bool compare(pair<string, string> a, pair<string, string> b){
    if(a.first==b.first){
        return a.second > b.second;
    }
    return a.first < b.first;

}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> m;
    char ar[12][12]={0};
    char ar2[12][12]={0};
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }
    int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
    int check = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin >> ar2[i][j];
            if(ar2[i][j]=='x'){
                int count = 0;
                for(int k=0;k<8;k++){
                    if(ar[i+dx[k]][j+dy[k]]=='*')count++;
                    if(ar[i][j]=='*')check=1;
                }
                ar2[i][j] = count+48;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(check==1){
                if(ar[i][j]=='*')cout<<'*';
                else cout << ar2[i][j];
            }
            else
                cout << ar2[i][j];
        }cout << '\n';
    }
    return 0;
}
//8 2 9 1 4 6 7 10
