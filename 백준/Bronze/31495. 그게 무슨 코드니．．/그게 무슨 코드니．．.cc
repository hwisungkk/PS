#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    int n, m, t;
    int total=0;
    string s;
    getline(cin, s);
    int chk = 0;
    if(s.size()>=3){
        if(s[0]=='"' && s[s.size()-1]=='"'){
            chk = 1;
        }
    }

    if(chk){
        for(int i=1;i<s.size()-1;i++){
            cout << s[i];
        }
    }
    else{
        cout << "CE";
    }


    return 0;
}