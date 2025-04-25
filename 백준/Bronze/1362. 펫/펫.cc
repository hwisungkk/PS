#include <vector>
#include <iostream>
#include <string>
using namespace std;

//Q.1362
enum state{good=1,bad,die};
int ret_state(int o, int w) {
	if (w > o / 2 && w < o * 2) return good;
	else if (w <= 0) return die;
	else return bad;
}
int main() {
	int o, w,num,now_state;
	char behavior;
	vector<string> pet_state;
	
	while (1) {
		cin >> o >> w;
		now_state = good;
		if (o == 0 && w == 0) break;

		while (1) {
			cin >> behavior >> num;

			if (behavior == 'F') {
				if (now_state != die) w += num;
			}
			else if (behavior == 'E') {
				if (now_state != die) w -= num;
			}
			else if(behavior == '#'){
				if (now_state == good) pet_state.push_back(":-)");
				else if (now_state == bad) pet_state.push_back(":-(");
				else if (now_state == die) pet_state.push_back("RIP");
				break;
			}
			now_state = ret_state(o, w);
		}
	}

	for (int i = 0; i < pet_state.size(); i++) {
		cout << i + 1 << " " << pet_state[i] << endl;
	}

	return 0;
}