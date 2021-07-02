
#include <iostream>

using namespace std;

template<typename T> 
struct Node {

	T value;
	Node* next;

	Node(T value, Node* next) {
		this->value = value;
		this->next = next;
	}

};

template<typename T>
class Stack {

private:

	Node<T>* top;

public:

	Stack() {
		top = nullptr;
	}

	~Stack() {
		while (top) {
			Node<T>* toDelete = top;
			top = top->next;
			delete toDelete;
		}
	}

	void push(T symbol) {
		Node<T>* newTop = new Node<T>(symbol, top);
		top = newTop;
	}

	void pop() {
		if (!empty()) {
			Node<T>* front = top;
			top = top->next;
			delete front;
		}
	}

	T front() {
		return top->value;
	}

	bool empty() {
		return top == nullptr;
	}

};

template <typename T>
class Queue {

private:

	Node<T>* head;
	Node<T>* tail;

	int size;

public:

	Queue() {
		head = nullptr;
		tail = nullptr;

		size = 0;
	}

	~Queue() {
		while (head) {
			Node<T>* toDelete = head;
			head = head->next;
			delete toDelete;
		}
	}

	void push(T value) {
		Node<T>* newNode = new Node<T>(value, nullptr);
		if (empty()) {
			head = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
		
		size++;
	}

	void pop() {
		if (empty()) {
			return;
		}

		Node<T>* front = head;
		head = head->next;
		delete front;

		size--;
	}

	T front() {
		return head->value;
	}

	bool empty() {
		return head == nullptr;
	}

	int getSize() {
		return size;
	}

};

template <typename T>
struct BinaryTreeNode {

	T value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T value, BinaryTreeNode* left, BinaryTreeNode* right) {
		this->value = value;
		this->left = left;
		this->right = right;
	}

};

template <typename T>
void bfs(BinaryTreeNode<T>* root) {

	Queue<BinaryTreeNode<T>*> queue;
	queue.push(root);

	while (!queue.empty()) {
		int size = queue.getSize();
		while (size) {
			BinaryTreeNode<T>* front = queue.front();
			cout << front->value << " ";

			if (front->left) {
				queue.push(front->left);
			}

			if (front->right) {
				queue.push(front->right);
			}

			queue.pop();

			size--;
		}

		cout << "\n";
	}

}

template <typename T>
void dfs(BinaryTreeNode<T>* root) {

	if (!root) {
		return;
	}

	cout << root->value << " ";

	dfs(root->left);
	dfs(root->right);
}


//int main() {
//
//	BinaryTreeNode<char>* nodes[25] = {
//		new BinaryTreeNode<char>('!', nullptr, nullptr), // 0
//		new BinaryTreeNode<char>('s', nullptr, nullptr), // 1
//		new BinaryTreeNode<char>('m', nullptr, nullptr), // 2
//		new BinaryTreeNode<char>('e', nullptr, nullptr), // 3
//		new BinaryTreeNode<char>('l', nullptr, nullptr), // 4
//		new BinaryTreeNode<char>('b', nullptr, nullptr), // 5
//		new BinaryTreeNode<char>('o', nullptr, nullptr), // 6
//		new BinaryTreeNode<char>('r', nullptr, nullptr), // 7
//		new BinaryTreeNode<char>('p', nullptr, nullptr), // 8
//		new BinaryTreeNode<char>('g', nullptr, nodes[0]), // 9
//		new BinaryTreeNode<char>('n', nodes[1], nullptr), // 10
//		new BinaryTreeNode<char>('i', nullptr, nullptr), // 11
//		new BinaryTreeNode<char>('v', nullptr, nullptr), // 12
//		new BinaryTreeNode<char>('l', nodes[3], nodes[2]), // 13
//		new BinaryTreeNode<char>('o', nodes[5], nodes[4]), // 14
//		new BinaryTreeNode<char>('s', nodes[7], nodes[6]), // 15
//		new BinaryTreeNode<char>('t', nullptr, nodes[8]), // 16
//		new BinaryTreeNode<char>('a', nodes[10], nodes[9]), // 17
//		new BinaryTreeNode<char>('d', nodes[12], nodes[11]), // 18
//		new BinaryTreeNode<char>('o', nodes[14], nodes[13]), // 19
//		new BinaryTreeNode<char>('o', nullptr, nodes[15]), // 20
//		new BinaryTreeNode<char>('g', nodes[17], nodes[16]), // 21
//		new BinaryTreeNode<char>('m', nodes[19], nodes[18]), // 22
//		new BinaryTreeNode<char>('a', nodes[21], nodes[20]), // 23
//		new BinaryTreeNode<char>('I', nodes[23], nodes[22]), // 24
//	};
//
//	BinaryTreeNode<char>* root = nodes[24];
//
//	bfs<char>(root);
//	dfs<char>(root);
//
//	return 0;
//}
