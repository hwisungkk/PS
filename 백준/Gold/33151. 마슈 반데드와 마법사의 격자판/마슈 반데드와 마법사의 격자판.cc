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
    char ch;
    bool flag=0;
    
    cin >> n >> m;
    if(m<n*n/2){
        cout << "-1";
        return 0;
    }
    a = m%(n*n);
    b = m/(n*n);
    if(a<n*n/2){
        a+=n*n;
        b-=1;
    }
    vector<vector<int>> board(n, vector<int>(n, b));

    if(n%2==1){
        if(a%2==0){
            a-=(n*n/2);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==1){
                        board[i][j]++;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==0){
                        if(a==0)break;
                        board[i][j]+=2;
                        a-=2;
                    }
                }
                if(a==0)break;
            }
        }
        else if(a%2==1){
            a-=(n*n/2);
            a-=1;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==0){
                        board[i][j]++;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==1){
                        if(a==0)break;
                        board[i][j]+=2;
                        a-=2;
                    }
                }
                if(a==0)break;
            }
        }
    }
    if(n%2==0){
        if(a%2==1){
            cout << "-1";
            return 0;
        }
        else{
            a-=(n*n/2);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==0){
                        board[i][j]++;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==1){
                        if(a==0)break;
                        board[i][j]+=2;
                        a-=2;
                    }
                }
                if(a==0)break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<n-1)
                cout << board[i][j] << ' ';
            else cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}
