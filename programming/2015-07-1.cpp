
#include <iostream>

using namespace std;

float findAve(float img[10][10], int m, int n, int i, int j) {

	float sum = 0;
	int count = 0;

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (i * 2 <= y && y <= i * 2 + 1 && j * 2 <= x && x <= j * 2 + 1) {
				sum += img[y][x];
				count++;
			}
		}
	}

	return sum / count;
}

void subsample(float img[10][10], int m, int n) {

	int newM = (m + 1) / 2;
	int newN = (n + 1) / 2;

	float** s = new float*[newM];
	for (int i = 0; i < newM; i++) {
		s[i] = new float[newN];
		for (int j = 0; j < newN; j++) {
			s[i][j] = findAve(img, m, n, i, j);
		}
	}

	for (int i = 0; i < newM; i++) {
		for (int j = 0; j < newN; j++) {
			cout << s[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < newM; i++) {
		delete[] s[i];
	}

	delete[] s;
}

//int main() {
//
//	float img[10][10] = {
//		{1.0, 2.0, 3.0},
//		{4.5, 6.5, 7.5}
//	};
//
//	subsample(img, 2, 3);
//
//	return 0;
//}
