
#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int value, Node* next) {
		this->value = value;
		this->next = next;
	}
};

int getListLength(Node* list) {
	int length = 0;
	while (list) {
		length++;
		list = list->next;
	}
	return length;
}

Node* getNodeAt(Node* list, int index) {
	int count = 0;

	while (list) {
		if (count == index) {
			return list;
		}
		list = list->next;
		count++;
	}

	return nullptr;
}

void printList(Node* list) {
	while (list) {
		cout << list->value << " ";
		list = list->next;
	}
	cout << "\n";
}

void bubbleSortList(Node* list) {

	int length = getListLength(list);

	for (int i = 0; i < length - 1; i++){
		for (int j = 0; j < length - i - 1; j++) {
			
			Node* curr = getNodeAt(list, j);
			Node* next = getNodeAt(list, j + 1);

			if (curr->value > next->value) {
				Node* prev = getNodeAt(list, j - 1);
				if (prev) {
					curr->next = next->next;
					prev->next = next;
					next->next = curr;
				}
				else {
					curr->next = next->next;
					next->next = curr;
				}
			}
		}
	}

}

//int main() {
//
//	Node* arr[] = {
//		new Node(7, nullptr),  // 0
//		new Node(1, arr[0]),  // 1
//		new Node(17, arr[1]), // 2
//		new Node(0, arr[2]),  // 3
//		new Node(8, arr[3]),  // 4
//		new Node(-3, arr[4])  // 5
//	};
//
//	Node* list = arr[5];
//
//	bubbleSortList(list);
//	printList(list);
//
//	return 0;
//}
