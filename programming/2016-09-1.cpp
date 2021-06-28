
#include <iostream>

using namespace std;

int getLength(const char* str) {
	int length = 0;
	while (*str) {
		length++;
		str++;
	}
	return length;
}

int* findMaxDoubleDistance(const char* str) {
	
	int length = getLength(str);
	int best[2] = { 0, 0 };


	for (int i = 0; i < length; i++) {
		char* curr = (char*)(str + i);
		
		int tmp[2] = { 0, 0 };

		for (int j = length; j > i; j--) {
			if (str[i] == str[j]) {
				tmp[0] = i;
				tmp[1] = j;
				break;
			}
		}

		if (tmp[1] - tmp[0] > best[1] - best[0]) {
			best[0] = tmp[0];
			best[1] = tmp[1];
		}
	}

	return best;
	
}

//int main() {
//
//	int* best = findMaxDoubleDistance("this is just a simple example");
//
//	cout << best[0] << " " << best[1] << "\n";
//
//	return 0;
//}
