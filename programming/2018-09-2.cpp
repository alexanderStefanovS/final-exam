
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

struct Node {
	int value;
	Node* next;
	Node* kNext;
};

int getNumber(string str, int begin, int end) {
	int num = 0;
	int x = 0;
	for (int i = end; i >= begin; i--) {
		num += ((int)str[i] - 48) * (int)pow(10, x);
		x++;
	}
	return num;
}

 Node* readList(string path) {
	ifstream numbersFile(path);

	string numbersStr;
	getline(numbersFile, numbersStr);

	numbersFile.close();

	int size = 0;

	int begin = 0;
	for (int i = 0; i <= numbersStr.length(); i++) {
		if (numbersStr[i] == ' ' || i == numbersStr.length()) {
			size++;
			begin = i + 1;
		}
	}

	int j = 0;
	int* arr = new int(size);

	begin = 0;
	for (int i = 0; i <= numbersStr.length(); i++) {
		if (numbersStr[i] == ' ' || i == numbersStr.length()) {
			arr[j] = getNumber(numbersStr, begin, i - 1);
			j++;
			begin = i + 1;
		}
	}

	int k = ceil(sqrt(size));

	Node* prev = nullptr;
	Node* prevK = nullptr;
	Node* start = nullptr;

	for (int i = 0; i < size; i++) {

		Node* node = new Node({ arr[i], nullptr, nullptr });
		
		if (i == 0) {
			start = node;
		}
		
		if (i % k == 0) {
			if (prevK) {
				prevK->kNext = node;
			}
			prevK = node;
		}

		if (prev) {
			prev->next = node;
		}

		prev = node;
	}

	return start;
}

 bool member(Node* list, int num) {

	 Node* prevK = list;

	 while (prevK) {

		 if (prevK && prevK->value == num) {
			 return true;
		 }
		 else if (!prevK->kNext || prevK->kNext->value > num) {
			 Node* curr = prevK;
			 while (curr != prevK->kNext) {
				 if (curr->value == num) {
					 return true;
				 }
				 curr = curr->next;
			 }
			 return false;
		 }

		 prevK = prevK->kNext;
	 }

	 return false;
}

int main() {

	Node* list = readList("numbers.txt");

	/*while (list) {
		cout << list->value;

		if (list->kNext) {
			cout << " " << list->kNext->value;
		}

		cout << "\n";

		list = list->next;
	}*/

	cout  << member(list, 123);

	return 0;
}

