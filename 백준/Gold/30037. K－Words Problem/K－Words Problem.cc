#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    int n, m, t;
    int total=0;

    cin >> n;
    vector<vector<string>> v(n);
    string s;
    for(int i=0;i<n;i++){
        while(1){
            cin >> s;
            v[i].push_back(s);
            if(s[s.size()-1]=='.')break;
        }
        for(int j=1;j<v[i].size()-1;j++){ //2단어 짜리니까
            if(v[i][j]=="of"){
                if(v[i][j+1] == "Korea" || v[i][j+1] == "Korea." || v[i][j+1] == "Korea?" || v[i][j+1] == "Korea!" || v[i][j+1] == "Korea,"){
                    int isalpha = 1;
                    for(int k=0;k<v[i][j-1].size();k++){
                        if(v[i][j-1][k]=='!' || v[i][j-1][k]=='?' || v[i][j-1][k]==','){ //알파벳인지 확인
                            isalpha=0;
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    if(!isalpha) continue;
                    else{
                        v[i][j-1][0] = toupper(v[i][j-1][0]);
                        v[i][j-1] = "K-" + v[i][j-1];
                        if(v[i][j+1][v[i][j+1].size()-1]=='!' || v[i][j+1][v[i][j+1].size()-1]=='?' || v[i][j+1][v[i][j+1].size()-1]==',' || v[i][j+1][v[i][j+1].size()-1]=='.'){
                            v[i][j-1] += v[i][j+1][v[i][j+1].size()-1];
                        }
                        v[i].erase(v[i].begin() + j+1);
                        v[i].erase(v[i].begin() + j);
                        j--;
                    }
                }
            }
        }
        for(int j=v[i].size()-2;j>=0;j--){ //2단어 짜리니까
            if(v[i][j]=="Korea"){
                v[i][j+1][0] = toupper(v[i][j+1][0]);
                v[i][j+1] = "K-" + v[i][j+1];
                v[i].erase(v[i].begin() + j);
                j++;
            }
        }
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << ' ';
        }cout << '\n';
    }

    return 0;
}