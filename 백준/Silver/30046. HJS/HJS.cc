#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;

    cin >> n;
    
    vector<string> vs(3);

    for(int i=0;i<3;i++){
        cin >> vs[i];
    }

    //123
    string s1="", s2="", s3="";
    for(int i=0;i<n;i++){
        if(vs[0][i]=='H')s1.push_back('1');
        else if(vs[0][i]=='J')s1.push_back('2');
        else if(vs[0][i]=='S')s1.push_back('3');
    }
    for(int i=0;i<n;i++){
        if(vs[1][i]=='H')s2.push_back('1');
        else if(vs[1][i]=='J')s2.push_back('2');
        else if(vs[1][i]=='S')s2.push_back('3');
    }
    for(int i=0;i<n;i++){
        if(vs[2][i]=='H')s3.push_back('1');
        else if(vs[2][i]=='J')s3.push_back('2');
        else if(vs[2][i]=='S')s3.push_back('3');
    }
    if(s1<s2 && s2<s3)flag=1;

    //132
    s1="", s2="", s3="";
    for(int i=0;i<n;i++){
        if(vs[0][i]=='H')s1.push_back('1');
        else if(vs[0][i]=='J')s1.push_back('3');
        else if(vs[0][i]=='S')s1.push_back('2');
    }
    for(int i=0;i<n;i++){
        if(vs[1][i]=='H')s2.push_back('1');
        else if(vs[1][i]=='J')s2.push_back('3');
        else if(vs[1][i]=='S')s2.push_back('2');
    }
    for(int i=0;i<n;i++){
        if(vs[2][i]=='H')s3.push_back('1');
        else if(vs[2][i]=='J')s3.push_back('3');
        else if(vs[2][i]=='S')s3.push_back('2');
    }
    if(s1<s2 && s2<s3)flag=1;

    //213
    s1="", s2="", s3="";
    for(int i=0;i<n;i++){
        if(vs[0][i]=='H')s1.push_back('2');
        else if(vs[0][i]=='J')s1.push_back('1');
        else if(vs[0][i]=='S')s1.push_back('3');
    }
    for(int i=0;i<n;i++){
        if(vs[1][i]=='H')s2.push_back('2');
        else if(vs[1][i]=='J')s2.push_back('1');
        else if(vs[1][i]=='S')s2.push_back('3');
    }
    for(int i=0;i<n;i++){
        if(vs[2][i]=='H')s3.push_back('2');
        else if(vs[2][i]=='J')s3.push_back('1');
        else if(vs[2][i]=='S')s3.push_back('3');
    }
    if(s1<s2 && s2<s3)flag=1;

    //231
    s1="", s2="", s3="";
    for(int i=0;i<n;i++){
        if(vs[0][i]=='H')s1.push_back('2');
        else if(vs[0][i]=='J')s1.push_back('3');
        else if(vs[0][i]=='S')s1.push_back('1');
    }
    for(int i=0;i<n;i++){
        if(vs[1][i]=='H')s2.push_back('2');
        else if(vs[1][i]=='J')s2.push_back('3');
        else if(vs[1][i]=='S')s2.push_back('1');
    }
    for(int i=0;i<n;i++){
        if(vs[2][i]=='H')s3.push_back('2');
        else if(vs[2][i]=='J')s3.push_back('3');
        else if(vs[2][i]=='S')s3.push_back('1');
    }
    if(s1<s2 && s2<s3)flag=1;

    //312
    
    s1="", s2="", s3="";
    for(int i=0;i<n;i++){
        if(vs[0][i]=='H')s1.push_back('3');
        else if(vs[0][i]=='J')s1.push_back('1');
        else if(vs[0][i]=='S')s1.push_back('2');
    }
    for(int i=0;i<n;i++){
        if(vs[1][i]=='H')s2.push_back('3');
        else if(vs[1][i]=='J')s2.push_back('1');
        else if(vs[1][i]=='S')s2.push_back('2');
    }
    for(int i=0;i<n;i++){
        if(vs[2][i]=='H')s3.push_back('3');
        else if(vs[2][i]=='J')s3.push_back('1');
        else if(vs[2][i]=='S')s3.push_back('2');
    }
    if(s1<s2 && s2<s3)flag=1;

    //321
    
    s1="", s2="", s3="";
    for(int i=0;i<n;i++){
        if(vs[0][i]=='H')s1.push_back('3');
        else if(vs[0][i]=='J')s1.push_back('2');
        else if(vs[0][i]=='S')s1.push_back('1');
    }
    for(int i=0;i<n;i++){
        if(vs[1][i]=='H')s2.push_back('3');
        else if(vs[1][i]=='J')s2.push_back('2');
        else if(vs[1][i]=='S')s2.push_back('1');
    }
    for(int i=0;i<n;i++){
        if(vs[2][i]=='H')s3.push_back('3');
        else if(vs[2][i]=='J')s3.push_back('2');
        else if(vs[2][i]=='S')s3.push_back('1');
    }
    if(s1<s2 && s2<s3)flag=1;

    if(flag)cout<<"HJS! HJS! HJS!";
    else cout << "Hmm...";

    return 0;
}
