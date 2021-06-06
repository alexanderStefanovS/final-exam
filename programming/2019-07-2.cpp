
#include <iostream>
#include <vector>

using namespace std;

class Vertex {
private:

	char a;
	int b;

	vector<Vertex> children;

public:

	Vertex(char a, int b, vector<Vertex> children) {
		this->a = a;
		this->b = b;
		this->children = children;
	}

	vector<Vertex> getChildren() {
		return this->children;
	}

	void addChild(Vertex v) {
		this->children.push_back(v);
	}

	char sym() {
		return a;
	}

	int val() {
		return b;
	}

};

void findBranches(vector<pair<int, string>> branches, Vertex root, string word, int sum) {

	vector<Vertex> vertexes = root.getChildren();

	for (int i = 0; i < vertexes.size(); i++) {
		int newSum = vertexes[i].val();
		string newWord = word + vertexes[i].sym();

		branches.push_back(pair<int, string>(newSum, newWord));

		findBranches(branches, vertexes[i], newWord, newSum);
	}

}

int sumVal(Vertex u, Vertex v) {

	vector<pair<int, string>> branchesU;
	findBranches(branchesU, u, "", 0);

	vector<pair<int, string>> branchesV;
	findBranches(branchesV, v, "", 0);

	int sum = 0;

	for (size_t i = 0; i < branchesU.size(); i++) {
		for (size_t j = 0; j < branchesV.size(); j++) {
			if (branchesU[i].second == branchesV[j].second) {
				sum += branchesU[i].first + branchesV[j].first;
			}
		}
	}
}

//int main() {
//
//	Vertex v6('f', 1, vector<Vertex>());
//	Vertex v3('d', 2, vector<Vertex>());
//	v3.addChild(v6);
//	
//
//	return 0;
//}
