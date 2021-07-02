
#include <iostream>

using namespace std;

void printM(bool** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void getConnectedNodes(bool graph[1000][1000], bool** connected, bool* visited, int n, int current, int vertex) {

	visited[current] = true;

	for (int i = 0; i < n; i++) {
		if (graph[current][i] && !visited[i]) {
			connected[vertex][i] = true;
			connected[i][vertex] = true;

			getConnectedNodes(graph, connected, visited, n, i, vertex);
		}
	}
}

bool isConnected(bool graph[][1000], int n) {

	bool** connected = new bool*[n];
	for (int i = 0; i < n; i++) {
		connected[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			connected[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {

		bool* visited = new bool[n];
		for (int j = 0; j < n; j++) {
			visited[j] = false;
		}

		getConnectedNodes(graph, connected, visited, n, i, i);

		delete[] visited;
	}

	printM(connected, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (!connected[i][j]) {
					return false;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] connected[i];
	}
	delete[] connected;

	return true;

}


int main() {

	bool graph[1000][1000] = {
		{0, 0, 0},
		{1, 0, 0},
		{0, 1, 0}
	};

	cout << isConnected(graph, 3);

	return 0;
}