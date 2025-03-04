#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int ssang(int n){
    if(n==0)return 5;
    if(n==5)return 0;
    if(n==1)return 3;
    if(n==3)return 1;
    if(n==2)return 4;
    if(n==4)return 2;
    return 0;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(6));

    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin >> v[i][j];
        }
    }

    int ma = -1;
    for(int k=1;k<=6;k++){
        int total = 0;
        int ceil = 0; //천장
        int floor = 0; // 바닥
        for(int j=0;j<6;j++){ //바닥 index 찾기
            if(v[0][j]== k){
                floor = j;
                ceil = ssang(j);
                if(v[0][floor] == 6 || v[0][ceil] == 6){
                    if((v[0][floor] == 5 && v[0][ceil] == 6) || (v[0][floor] == 6 && v[0][ceil] == 5)){
                        total += 4;
                    }
                    else total += 5;
                }
                else{
                    total+=6;
                }
                break;
            }
        }
        int aa = v[0][ceil];
        for(int i=1;i<n;i++){
            for(int j=0;j<6;j++){ //바닥 index 찾기
                if(v[i][j]== aa){
                    floor = j;
                    ceil = ssang(j);
                    if(v[i][floor] == 6 || v[i][ceil] == 6){
                        if((v[i][floor] == 5 && v[i][ceil] == 6) || (v[i][floor] == 6 && v[i][ceil] == 5)){
                            total += 4;
                        }
                        else total += 5;
                    }
                    else{
                        total+=6;
                    }
                    break;
                }
            }
            aa = v[i][ceil];

        }
        ma = max(ma, total);
    }
    cout << ma;
    
    return 0;
}