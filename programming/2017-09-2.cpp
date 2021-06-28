
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

struct ListNode {
	ListNode* nextList;
	Node* valueList;

	ListNode(ListNode* nextList, Node* valueList) {
		this->nextList = nextList;
		this->valueList = valueList;
	}
};

bool isSorted(Node* list) {

	while (list->next) {
		if (list->value > list->next->value) {
			return false;
		}
		list = list->next;
	}

	return true;
}

//void printList(Node* list) {
//	while (list) {
//		cout << list->value << " ";
//		list = list->next;
//	}
//	cout << "\n";
//}

Node* getSortedList(ListNode* listOfLists) {

	Node* sortedList = nullptr;

	while (listOfLists) {

		Node* list = listOfLists->valueList;

		if (isSorted(list)) {

			while (list) {
				if (!sortedList) {
					sortedList = new Node(list->value, nullptr);
				}
				else {
					Node* curr = sortedList;

					while (curr) {
						if (list->value >= curr->value && (!curr->next || list->value <= curr->next->value)) {
							Node* next = curr->next;
							curr->next = new Node(list->value, next);
							break;
						}
						curr = curr->next;
					}
				}
				list = list->next;
			}

		}

		listOfLists = listOfLists->nextList;
	}

	return sortedList;
}

//int main() {
//	
//	Node* arr1[] = {
//		new Node(432, nullptr),	// 0
//		new Node(35, arr1[0]),	// 1
//		new Node(23, arr1[1]),	// 2
//		new Node(21, arr1[2]),  // 3
//		new Node(10, arr1[3]),  // 4
//		new Node(9, arr1[4]),  // 5
//		new Node(-1, arr1[5]),  // 6
//		new Node(-15, arr1[6])	// 7
//	};
//
//	Node* list1 = arr1[7];
//
//	Node* arr2[] = {
//		new Node(7, nullptr),  // 0
//		new Node(1, arr2[0]),  // 1
//		new Node(17, arr2[1]), // 2
//		new Node(0, arr2[2]),  // 3
//		new Node(8, arr2[3]),  // 4
//		new Node(-3, arr2[4])  // 5
//	};
//
//	Node* list2 = arr2[5];
//
//	Node* arr3[] = {
//		new Node(29, nullptr), // 0
//		new Node(18, arr3[0]),  // 1
//		new Node(12, arr3[1]),  // 2
//		new Node(6, arr3[2]), // 3
//		new Node(1, arr3[3]), // 4
//		new Node(-1, arr3[4])  // 5
//	};
//
//	Node* list3 = arr3[5];
//
//	ListNode* listArr[] = {
//		new ListNode(nullptr, list3),    // 0
//		new ListNode(listArr[0], list2), // 1
//		new ListNode(listArr[1], list1), // 2
//	};
//
//	ListNode* listOfLists = listArr[2];
//
//	Node* sortedList = getSortedList(listOfLists);
//
//	printList(sortedList);
//
//	return 0;
//}
