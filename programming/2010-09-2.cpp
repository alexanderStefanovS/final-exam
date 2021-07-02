
#include <iostream>

using namespace std;

struct Node {

	char value;
	Node* next;

	Node(char value, Node* next) {
		this->value = value;
		this->next = next;
	}

};

class Stack {

private:
	
	Node* top;

public:
	
	Stack() {
		top = nullptr;
	}

 	void push(char symbol) {
		Node* newTop = new Node(symbol, top);
		top = newTop;
	}

	void pop() {
		if (!empty()) {
			Node* front = top;
			top = top->next;
			delete front;
		}
	}

	char front() {
		return top->value;
	}

	bool empty() {
		return top == nullptr;
	}

};

bool isCorrect(char* str) {
	Stack stack;

	while (*str) {

		if (*str == '(') {
			stack.push(*str);
		}

		if (*str == ')') {
			if (stack.empty()) {
				return false;
			}
			stack.pop();
		}

		str++;
	}

	return stack.empty();
}

//int main() {
//
//	char* str = (char*)"aa((a)sda(sd))";
//
//	cout << isCorrect(str);
//
//	return 0;
//}
