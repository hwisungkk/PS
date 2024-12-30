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
long long maxi=0;
int n;
void back(vector <vector <int>> board, int k){
    // cout << "K: " << k << '\n';
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << board[i][j] << ' ';        
    //     }cout << '\n';
    // }cout << "----------------\n";
    if(k==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(maxi < board[i][j])maxi=board[i][j];
            }
        }
        return;
    }
    vector <vector <int>> temp_board(n, vector<int>(n)); //복사 배열 선언

    copy(board.begin(), board.end(), temp_board.begin());
    int bp;
    for(int j=0;j<n;j++){ //위로 이동
        bp=-1;
        for(int i=1;i<n;i++){
            for(int x=i;x>=1;x--){
                if(x-1==bp)break;
                if(temp_board[x-1][j]==0){
                    swap(temp_board[x-1][j], temp_board[x][j]);
                }
                else{
                    if(temp_board[x-1][j]==temp_board[x][j]){
                        temp_board[x-1][j]=2*temp_board[x-1][j];
                        temp_board[x][j]=0;
                        bp=x-1;
                    }
                    break;
                }
            }
        }
    }
    back(temp_board, k+1);

    copy(board.begin(), board.end(), temp_board.begin());
    for(int j=0;j<n;j++){ //아래로 이동
        bp = n;
        for(int i=n-2;i>=0;i--){
            for(int x=i;x<=n-2;x++){
                if(x+1==bp)break;
                if(temp_board[x+1][j]==0){
                    swap(temp_board[x+1][j], temp_board[x][j]);
                }
                else{
                    if(temp_board[x+1][j]==temp_board[x][j]){
                        temp_board[x+1][j]=2*temp_board[x+1][j];
                        temp_board[x][j]=0;
                        bp=x+1;
                    }
                    break;
                }
            }
        }
    }
    back(temp_board, k+1);

    copy(board.begin(), board.end(), temp_board.begin());
    for(int i=0;i<n;i++){ //오른쪽로 이동
        bp=n;
        for(int j=n-2;j>=0;j--){
            for(int x=j;x<=n-2;x++){
                if(x+1==bp)break;
                if(temp_board[i][x+1]==0){
                    swap(temp_board[i][x+1], temp_board[i][x]);
                }
                else{
                    if(temp_board[i][x+1]==temp_board[i][x]){
                        temp_board[i][x+1]=2*temp_board[i][x+1];
                        temp_board[i][x]=0;
                        bp=x+1;
                    }
                    break;
                }
            }
        }
    }
    back(temp_board, k+1);
    
    copy(board.begin(), board.end(), temp_board.begin());
    for(int i=0;i<n;i++){ //왼쪽으로 이동
        bp=-1;
        for(int j=1;j<n;j++){
            for(int x=j;x>=1;x--){
                if(x-1==bp)break;
                if(temp_board[i][x-1]==0){
                    swap(temp_board[i][x-1], temp_board[i][x]);
                }
                else{
                    if(temp_board[i][x-1]==temp_board[i][x]){
                        temp_board[i][x-1]=2*temp_board[i][x-1];
                        temp_board[i][x]=0;
                        bp=x-1;
                    }
                    break;
                }
            }
        }
    }
    back(temp_board, k+1);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, m, k;
    int t;

    cin >> n;
    vector <vector <int>> board(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    back(board, 0);
    
    cout << maxi;
    return 0;
}
