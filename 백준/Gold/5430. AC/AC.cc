#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c=0, total=0;
    char ch;
    long long count=0;
    int ma = -1000;
    int n, m, z=1;
    int dp[1000]={0};
    string s1, s2, s3;
    cin >> n;
    for(int i=0;i<n;i++){
        count =0;
        z=1;
        deque <int> d;
        cin >> s1;
        cin >> m;
        cin >> s2;
        for(int j=1;j<s2.size();j++){
            if(s2.size()==2)break;
            if(s2[j]==',' || s2[j]==']'){
                d.push_back(stoi(s3));
                s3="";
            }
            else{
                s3.push_back(s2[j]);
            }
        }
        for(int k=0;k<s1.size();k++){
            if(s1[k]=='R'){
                z *= -1;
            }
            else if(s1[k]=='D'){
                if(d.size()==0){
                    cout<<"error";
                    count=1;
                    break;
                }
                if(z==1){
                    d.pop_front();
                }
                else if(z==-1){
                    d.pop_back();
                }
            }
        }
        if(count!=1)cout<<"[";
        while(d.size()!=0){
            if(z==1){
                if(d.size()==1)cout << d.front();
                else cout << d.front() << ",";
                d.pop_front();
            }
            else{
                if(d.size()==1)cout << d.back();
                else cout << d.back() << ",";
                d.pop_back();
            }
        }
        if(count!=1)cout<<"]";
        cout << '\n';
    }
    
    return 0;
}