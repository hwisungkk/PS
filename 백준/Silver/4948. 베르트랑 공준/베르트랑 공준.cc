#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
long long gcb(long long a, long long b){
    long long k;
    if(a<b){
        k=a;
        a=b;
        b=k;
    } 
    k = a%b;
    if(a%b==0){
        return b;
    }
    return gcb(b,k);
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n, m, r_count=0, count=0;
    long long a, b, c, d, e, min = 9999999999;
    stack <int> s;
    vector <long long> prime;
    long long ar[100000];
    long long arr[100000];
    prime.push_back(2);
    for(long long i=3;i<=300000; i+=2){
        count = 0;
        for(long long j=0;prime[j]*prime[j]<=i&&j<prime.size();j++){
            if(i%prime[j]==0){
                count++;
                break;
            }
        }
        if(count == 0){
            prime.push_back(i);
        }
    }
    while(1){
        cin >> b;
        if(b==0)break;
        count = 0;
        for(int i=0;i<prime.size();i++){
            if(prime[i]>b && prime[i]<=2*b){
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}