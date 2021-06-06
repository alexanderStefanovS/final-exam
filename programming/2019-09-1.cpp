
#include <iostream>

bool find(int value, int* arr, size_t size) {

	if (size == 0) {
		return false;
	}

	size_t mid = size / 2; 

	if (value == arr[mid]) {
		return true;
	}

	if (value < arr[mid]) {
		return find(value, arr, mid);
	}
	else {
		return find(value, arr + mid, size);
	}

}

template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil) { 
	
	ReturnType result = nil;
	
	for (size_t i = 0; i < size; ++i) {
		result = op(arr[i], result);
	}
	
	return result; 
}

int op(char Digit, int Result) { 
	return (Result * 10) + (Digit - '0'); 
}

int str_to_int(const char* str) { 
	return (str == nullptr) ? 0 : fold_left<int, const char, int(char, int)>(str, strlen(str), op, 0);
}

//int main() {
//
//	int arr[] = { 1, 2, 3, 4, 5, 6 , 7 };
//	int size = sizeof(arr) / sizeof(int);
//
//	// std::cout << find(7, arr, size);
//
//	const char* str = "123";
//
//	std::cout << str_to_int(str);
//
//	return 0;
//}

