
#include <iostream>
#include <queue>
#include <utility>
#include <unordered_set>

using namespace std;

void printMatrix(bool** visited, int m, int n) {
	cout << "\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}

int getStageArea(char matrix[][6], int i, int j, int m, int n) {

	bool** visited = new bool*[m];
	for (int i = 0; i < m; i++) {
		visited[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	int area = 1;

	queue<pair<int, int>> q;
	q.push(pair<int, int>(i, j));
	visited[i][j] = true;

	while (!q.empty()) {

		pair<int, int> front = q.front();

		int i = front.first;
		int j = front.second;

		if (i + 1 < m && matrix[i + 1][j] == '4' && !visited[i + 1][j]) {
			q.push(pair<int, int>(i + 1, j));
			visited[i + 1][j] = true;
			area++;
		}

		if (i - 1 >= 0 && matrix[i - 1][j] == '4' && !visited[i - 1][j]) {
			q.push(pair<int, int>(i - 1, j));
			visited[i - 1][j] = true;
			area++;
		}

		if (j + 1 < n && matrix[i][j + 1] == '4' && !visited[i][j + 1]) {
			q.push(pair<int, int>(i, j + 1));
			visited[i][j + 1] = true;
			area++;
		}

		if (j - 1 >= 0 && matrix[i][j - 1] == '4' && !visited[i][j - 1]) {
			q.push(pair<int, int>(i, j - 1));
			visited[i][j - 1] = true;
			area++;
		}

		q.pop();

	}

	return area;
}

int findArea(char matrix[][6], int m, int n) {
	int max = 0;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++){
			if (matrix[i][j] == '4') {
				int area = getStageArea(matrix, i, j, m, n);
				if (max < area) {
					max = area;
				}
			}
		}
	}

	return max;
}

//int main() {
//
//	char matrix[4][6] = {
//		'R', 'R', '1', 'R', '4', '4',
//		'1', '1', '1', '1', '1', '4',
//		'R', '1', '1', '1', 'R', '1',
//		'R', 'R', 'S', '1', 'R', 'R'
//	};
//
//	bool** visited = new bool* [4];
//	for (int i = 0; i < 4; i++) {
//		visited[i] = new bool[6];
//		for (int j = 0; j < 6; j++) {
//			visited[i][j] = false;
//		}
//	}
//
//	cout << findArea(matrix, 4, 6);
//
//	return 0;
//}