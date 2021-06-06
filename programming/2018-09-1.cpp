
#include <iostream>

using namespace std;

bool compare(const char* a, const char* b) {
	
	while (*a && *b) {
		if (*a > *b) {
			return true;
		}
		else if (*a < *b) {
			return false;
		}
		a++;
		b++;
	}

	if (*a) {
		return true;
	}

	return false;
}

bool isSorted(const char* arr[30], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (compare(arr[i], arr[i + 1])) {
			return false;
		}
	}
	return true;
}

void printPass(char* str) {
	int counter = 0;

	while (*str) {
		if (*str == ' ') {
			cout << counter << " ";
			counter = 0;
		}
		else {
			counter++;
		}
		str++;
	}

	cout << counter << " ";
}

void revealPassword(const char* a[20][30], int m, int n) {
	
	for (int i = 0; i < m; i++) {
		if (!isSorted(a[i], n)) {
			continue;
		}

		printPass((char*)a[i][n / 2]);	
	}

}

//int main() {
//
//	const char* books[3][30] = {
//		{"algebra", "analiti4na geometriq", "matematika"},
//		{"tert", "sdf", "safasg"},
//		{"bazi ot danni", "izkustven intelekt", "zzz"}
//	};
//
//	revealPassword(books, 3, 3);
//
//	return 0;
//}
