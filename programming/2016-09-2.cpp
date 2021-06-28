
#include <iostream>
#include <queue>

using namespace std;

struct Node {

	int value;
	vector<Node*> childs;

	Node(int value, vector<Node*> childs) {
		this->value = value;
		this->childs = childs;
	}

};

void bfs(Node* root) {

	queue<Node*> q;

	q.push(root);

	cout << root->value << "\n";

	while (!q.empty()) {

		int size = q.size();

		while (size) {

			Node* front = q.front();

			for (int i = 0; i < front->childs.size(); i++) {
				cout << front->childs[i]->value << " ";
				q.push(front->childs[i]);
			}

			q.pop();

			size--;
		}
		cout << "\n";
	}
}

int getHeight(Node* root) {

	if (!root) {
		return 0;
	}

	int max = 0;
	for (int i = 0; i < root->childs.size(); i++) {
		int nodeHeight = getHeight(root->childs[i]);
		if (max < nodeHeight) {
			max = nodeHeight;
		}
	}

	return max + 1;
}

Node* buildTree(int* arr, int n, int k) {

	int i = 1;
	queue<Node*> q;

	Node* root = new Node(arr[0], vector<Node*>());
	q.push(root);

	while (!q.empty()) {

		Node* front = q.front();
		
		int start = i;
		while (i != n && i < start + k) {
			Node* newNode = new Node(arr[i], vector<Node*>());
			q.push(newNode);
			front->childs.push_back(newNode);
			i++;
		}

		q.pop();

	}

	bfs(root);
	cout << "\n" << getHeight(root) << "\n";

	return root;
}

//int main() {
//
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//
//	Node* root = buildTree(arr, 14, 3);
//
//	return 0;
//}
