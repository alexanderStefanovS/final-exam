
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printMatrix(double matrix[11][11], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

}

bool contains(vector<pair<int, int>> arr, int i, int j) {
	for (int k = 0; k < arr.size(); k++) {
		if (arr[k].first == i && arr[k].second == j) {
			return true;
		}
	}

	return false;
}

vector<pair<int, int>> getSimetricElements(int n, int i, int j) {

	vector<pair<int, int>> group;
	
	group.push_back(pair<int, int>(i, j));

	if (!contains(group, n - i - 1, n - j - 1)) {
		group.push_back(pair<int, int>(n - i - 1, n - j - 1));
	}

	if (!contains(group, n - j - 1, n - i - 1)) {
		group.push_back(pair<int, int>(n - j - 1, n - i - 1));
	}

	if (!contains(group, j, i)) {
		group.push_back(pair<int, int>(j, i));
	}

	return group;
}

double findAverage(double matrix[11][11], vector<pair<int, int>> arr) {
	double sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += matrix[arr[i].first][arr[i].second];
	}

	return sum / arr.size();
}

void replaceWithAverage(double matrix[11][11], int n, int i, int j, double ave) {
	matrix[i][j] = ave;
	matrix[n - i - 1][ n - j - 1] = ave;
	matrix[j][i] = ave;
	matrix[n - j - 1][ n - i - 1] = ave;
}

void replaceWithAverage(double matrix[11][11], int n) {
	for (int i = 0; i < n / 2 + 1; i++) {
		for (int j = i; j < n - i; j++) {
			vector<pair<int, int>> simetricGroup = getSimetricElements(n, i, j);
			double ave = findAverage(matrix, simetricGroup);
			replaceWithAverage(matrix, n, i, j, ave);
		}
	}
}

int main() {

	double matrix[11][11] = {
		{1, 0, 0, 2},
		{1, 21, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	replaceWithAverage(matrix, 4);
	printMatrix(matrix, 4);

	return 0;
}
