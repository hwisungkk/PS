#include <iostream>

using namespace std;

int cal(int* _a, const int _b, const int _n, int& _result)
{

	if (*_a % _b == 0){
		return _result;
	}

	if (*_a > _b) { 
		*_a = *_a % _b;
	}

	for (int i = 0; i < _n; i++) {
		*_a = *_a * 10;
		_result = static_cast<int>(*_a / _b); 
		*_a = *_a % _b;
	}

	return _result;
}

int main()
{
	cin.tie(0); 
	cout.tie(0); 

	int a, b, n;
	int result = 0;

	cin >> a >> b >> n;

	cout<<cal(&a, b, n, result);
}