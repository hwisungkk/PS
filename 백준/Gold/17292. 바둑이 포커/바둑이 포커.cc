#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
vector<pair<string, string>> one_dif;
vector<pair<string, string>> equ;
vector<pair<string, string>> other;
bool compare(pair<string, string> a, pair<string, string> b){
    if(a.first[1]==a.second[1] && b.first[1]!=b.second[1]) return true;
    else if(a.first[1]!=a.second[1] && b.first[1]==b.second[1])return false;
    else{
        if(max(a.first[0], a.second[0]) > max(b.first[0], b.second[0])) return true;
        else if(max(a.first[0], a.second[0]) < max(b.first[0], b.second[0])) return false;
        else{
            if(min(a.first[0], a.second[0]) > min(b.first[0], b.second[0])) return true;
            else if(min(a.first[0], a.second[0]) < min(b.first[0], b.second[0])) return false;
            else{
                char c;
                c = (a.first[0]>a.second[0])?a.first[1]:a.second[1];
                char c2;
                c2 = (b.first[0]>b.second[0])?b.first[1]:b.second[1];

                if(c=='b') return true;
                else return false;
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    long long ans;
    long long cnt = 0;
    int n, m, t;
    
    string s;
    cin >> s;
    vector<string> vs;
    vector <pair<string, string>> fok;

    for(int i=0;i<s.size();i+=3){
        string tmp = "";
        tmp+=s[i];
        tmp+=s[i+1];
        vs.push_back(tmp);
    }
    for(int i=0;i<vs.size()-1;i++){
        for(int j=i+1;j<vs.size();j++){
            if(i!=j){
                fok.push_back({vs[i], vs[j]});
            }
        }
    }
    for(int i=0;i<fok.size();i++){
        if(fok[i].first[0] + 1 == fok[i].second[0] || fok[i].first[0] - 1 == fok[i].second[0]
        || (fok[i].first[0]=='1' && fok[i].second[0]=='f') || (fok[i].first[0]=='9' && fok[i].second[0]=='a')
        || (fok[i].first[0]=='f' && fok[i].second[0]=='1') || (fok[i].first[0]=='a' && fok[i].second[0]=='9')){
            one_dif.push_back(fok[i]);
        }
        else if(fok[i].first[0] == fok[i].second[0]){
            equ.push_back(fok[i]);
        }
        else{
            other.push_back(fok[i]);
        }
    }
    sort(one_dif.begin(), one_dif.end(), compare);
    sort(equ.begin(), equ.end(), compare);
    sort(other.begin(), other.end(), compare);
    for(int i=0;i<one_dif.size();i++){
        cout << one_dif[i].first << one_dif[i].second << '\n';
    }
    for(int i=0;i<equ.size();i++){
        cout << equ[i].first << equ[i].second << '\n';
    }
    for(int i=0;i<other.size();i++){
        cout << other[i].first << other[i].second << '\n';
    }
    return 0;
}