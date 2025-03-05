#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
string s;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    vector<string> v;


    // cin >> s >> n;
    cin >> t;
    a = 0;
    int dx[8]={-1, -1, -1, 0, 1, 0, 1, 1};
    int dy[8]={-1, 0, 1, -1, 1, 1, -1, 0};
    while(t-->0){
        a++;
        long long cnt=0;
        vector<vector<char>> board(10, vector<char>(10, 0));
        cin >> m;
        for(int i=0;i<m;i++){
            string s;
            cin >> s;
            board[int(s[0]-'A'+1)][int(s[1]-'1'+1)] = s[3];
        }
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                if(board[i][j]=='K'){
                    for(int k=0;k<8;k++){
                        if(board[i+dx[k]][j+dy[k]]>0)cnt++;
                    }
                }
                else if(board[i][j]=='P'){
                    if(board[i+1][j-1]>0)cnt++;
                    if(board[i+1][j+1]>0)cnt++;
                }
                else if(board[i][j]=='R'){
                    for(int k=1;k<8;k+=2){
                        int dd = 1;
                        while(1){
                            int nx = i + dx[k]*dd;
                            int ny = j + dy[k]*dd;
                            if(nx>0 && nx<=8 && ny>0 && ny<=8){
                                if(board[nx][ny]>0){
                                    cnt++;
                                    break;
                                }
                            }
                            else break;
                            dd++;
                        }
                    }
                }
                else if(board[i][j]=='Q'){
                    for(int k=0;k<8;k++){
                        int dd = 1;
                        while(1){
                            int nx = i + dx[k]*dd;
                            int ny = j + dy[k]*dd;
                            if(nx>0 && nx<=8 && ny>0 && ny<=8){
                                if(board[nx][ny]>0){
                                    cnt++;
                                    break;
                                }
                            }
                            else break;
                            dd++;
                        }
                    }
                }
                else if(board[i][j]=='B'){
                    for(int k=0;k<8;k+=2){
                        int dd = 1;
                        while(1){
                            int nx = i + dx[k]*dd;
                            int ny = j + dy[k]*dd;
                            if(nx>0 && nx<=8 && ny>0 && ny<=8){
                                if(board[nx][ny]>0){
                                    cnt++;
                                    break;
                                }
                            }
                            else break;
                            dd++;
                        }
                    }
                }
                else if(board[i][j]=='N'){
                    for(int k=0;k<8;k+=2){
                        int nx = i + dx[k]*2;
                        int ny = j + dy[k]*1;
                        if(nx>0 && nx<=8 && ny>0 && ny<=8){
                            if(board[nx][ny]>0){
                                cnt++;
                            }
                        }
                        nx = i + dx[k]*1;
                        ny = j + dy[k]*2;
                        if(nx>0 && nx<=8 && ny>0 && ny<=8){
                            if(board[nx][ny]>0){
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout << "Case #" << a << ": " << cnt << '\n';
    }
    
    return 0;
}