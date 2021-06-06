
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Edge {
	unsigned int to;
	char label;
	unsigned int value;
};

using LabeledTree = vector<vector<Edge>>;

void findPaths(vector<pair<string, long long>> &paths, LabeledTree tree, int start, string path, long long sum) {

	vector<Edge> edges = tree[start];

	for (int i = 0; i < edges.size(); i++) {
		string newPath = path + edges[i].label;
		long long newSum = sum + edges[i].value;

		pair<string, long long> p(newPath, newSum);
		paths.push_back(p);
		
		findPaths(paths, tree, edges[i].to, newPath, newSum);
	}
}

void commonBranches(LabeledTree T, int u, int v, int k) {

	vector<pair<string, long long>> firstPaths;
	findPaths(firstPaths, T, u, "", 0);

	vector<pair<string, long long>> secondPaths;
	findPaths(secondPaths, T, v, "", 0);

	for (size_t i = 0; i < firstPaths.size(); i++) {
		for (size_t j = 0; j < secondPaths.size(); j++) {
			if (firstPaths[i].first == secondPaths[j].first && firstPaths[i].second + secondPaths[j].second == k) {
				cout << firstPaths[i].first << "\n";
			}
		}
	}
}

//int main() {
//
//	LabeledTree tree(11);
//
//	tree[0].push_back({ 1, 'a', 1 });
//	tree[0].push_back({ 5, 'a', 1 });
//
//	tree[1].push_back({ 2, 'c', 1 });
//	tree[2].push_back({ 3, 'a', 2 });
//	tree[2].push_back({ 9, 'n', 5 });
//	tree[3].push_back({ 4, 'r', 3 });
//
//	tree[5].push_back({ 6, 'c', 3 });
//	tree[6].push_back({ 7, 'a', 2 });
//	tree[6].push_back({ 10, 'n', 3 });
//	tree[7].push_back({ 8, 'r', 1 });
//
//	commonBranches(tree, 1, 5, 12);
// 
//	return 0;
//}

