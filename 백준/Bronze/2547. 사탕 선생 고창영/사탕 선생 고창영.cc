#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    long long student, candy;
    cin >> t;
    while(t-->0){
        cin >> student;
        long long sum = 0;
        for(int n = 0 ; n < student ; n++){
            cin >> candy;
            sum = (sum + candy) % student;
        }
        if(sum % student == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}