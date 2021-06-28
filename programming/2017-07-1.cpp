
#include <iostream>

using namespace std;

void printMatrix(char matrix[][6], int m, int n) {
	cout << "\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}

bool hasTreeValueOf4(char** matrix, int m, int n, int i, int j) {

	int count = 0;

	if (i + 1 < m && matrix[i + 1][j] == '4') {
		count++;
	}

	if (i - 1 >= 0 && matrix[i - 1][j] == '4') {
		count++;
	}

	if (j + 1 < n && matrix[i][j + 1] == '4') {
		count++;
	}

	if (j - 1 >= 0 && matrix[i][j - 1] == '4') {
		count++;
	}

	if (i + 1 < m && j + 1 < n && matrix[i + 1][j + 1] == '4') {
		count++;
	}

	if (i - 1 >= 0 && j + 1 < n && matrix[i - 1][j + 1] == '4') {
		count++;
	}

	if (i + 1 < m && j - 1 >= 0 && matrix[i + 1][j - 1] == '4') {
		count++;
	}

	if (i - 1 >= 0 && j - 1 >= 0 && matrix[i - 1][j - 1] == '4') {
		count++;
	}

	return count >= 3;
}

void transformTerrain(char matrix[][6], int m, int n) {

	char** copyTerrain = new char*[m];
	for (int i = 0; i < n; i++) {
		copyTerrain[i] = new char[n];
		for (int j = 0; j < n; j++) {
			copyTerrain[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (copyTerrain[i][j] == '1') {
				matrix[i][j] = '2';
			}

			if (copyTerrain[i][j] == '2') {
				matrix[i][j] = '3';
			}

			if (copyTerrain[i][j] == '3') {
				matrix[i][j] = '4';
			}

			if (copyTerrain[i][j] == '4') {
				if (hasTreeValueOf4(copyTerrain, m, n, i, j)) {
					matrix[i][j] = '3';
				}
			}
		} 
	}


}

//int main() {
//
//	char matrix[][6] = {
//		'R', 'R', '1', '1', '2', '2',
//		'1', 'R', 'R', 'R', '1', '2' ,
//		'4', '4', 'R', 'R', '2', '3',
//		'4', '4', '4', 'S', 'R', 'R'
//	};
//
//	transformTerrain(matrix, 4, 6);
//
//	printMatrix(matrix, 4, 6);
//
//	return 0;
//}
