#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m=0;
    int k=1, a, b;
    int check = 0;
    int arr[2000];
    string s;
    char ch;
    int max = -1000000000;
    vector <int> v;
    vector <vector<int>> nu;
    cin >> s;
    cin >> n;
    for(int j=97;j<=122;j++){
        nu.push_back({});
        for(int i=0;i<s.size();i++){
            if(s[i] == j){
                check++;
            }
            nu[j-97].push_back(check);
        }
    }
    for(int i=0;i<n;i++){
        cin >> ch >> a >> b;
        k = nu[ch-97][b] - nu[ch-97][a];
        if(s[a] == ch){
            k++;
        }
        cout << k << '\n';
    }
    return 0;
}