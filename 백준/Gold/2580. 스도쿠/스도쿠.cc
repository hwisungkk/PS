#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
vector <vector <int>> sudo(9, vector<int>(9, 0));
int complete = 0;
void back(int x, int y){
    if(x==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << sudo[i][j] << ' ';
            }cout << '\n';
        }
        complete = 1;
        return;
    }
    if(sudo[x][y]==0){
        for(int i=1;i<=9;i++){
            int check=0;
            for(int j=0;j<9;j++){
                if(sudo[x][j]==i){
                    check=1;
                    break;
                }
                if(sudo[j][y]==i){
                    check=1;
                    break;
                }
            }
            for(int bx=x/3*3;bx<x/3*3+3;bx++){
                for(int by=y/3*3;by<y/3*3+3;by++){
                    if(sudo[bx][by]==i)check=1;
                }
            }
            if(check==0){
                sudo[x][y]=i;
                if(y==8) back(x+1, 0);
                else back(x,y+1);
            }
            if(complete==1)return;
            sudo[x][y]=0;
        }
    }
    else{
        if(y==8) back(x+1, 0);
        else back(x,y+1);
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, k;
    int mi = 1e9;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> sudo[i][j];
        }
    }
    back(0, 0);

    return 0;
}