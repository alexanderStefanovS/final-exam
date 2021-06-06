
#include <iostream>

void printWord(const char* start) {
	
	if ((int)*(start) <= 32) {
		return;
	}
	
	std::cout << *start;

	printWord(start + 1);
}

void print_backwards(const char* begin, const char* end) {
	
	if ((int)*(end - 1) >= 32 && (int)*(end - 2) <= 32) {
		printWord(end - 1);

		if (end - 1 != begin) {
			std::cout << " ";
		}
	}

	if (end - 1 == begin) {
		return;
	}

	print_backwards(begin, end - 1);
}

void print_backwards(const char* string) {

	const char* begin = string;
	
	char* end = (char*)string;
	while (*end) {
		end++;
	}

	print_backwards(begin, end);
}

//int main() {
//
//	const char* str = "i\tneed a break!";
//	print_backwards(str);
//
//	return 0;
//}

