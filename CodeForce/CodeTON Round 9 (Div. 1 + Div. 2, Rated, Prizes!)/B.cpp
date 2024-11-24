#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
vector <int> v(1000000);
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, k = -1;
    string s1, s2;
    int j;
    cin >> n;
    while(n--){
        cin >> s1;
        int check=0;
        for(int i=1;i<s1.size();i++){
            if(s1[i-1]==s1[i]){
                cout<<s1[i]<<s1[i];
                check=1;
                break;
            }
            if(i>=2){
                if(s1[i-2]!=s1[i-1]){
                    if(s1[i-1]!=s1[i] && s1[i-2]!=s1[i]){
                        cout<<s1[i-2]<<s1[i-1]<<s1[i];
                        check=1;
                        break;
                    }
                }
            }
        }
        if(!check){
            cout<<"-1";
        }
        cout<<'\n';
    }
    
    return 0;
}