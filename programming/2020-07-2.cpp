
#include <iostream>

class Interval {

private:

	int a;
	int k;
	int current;

public:

	Interval(int a, int k);
	
	int operator*();
	void operator++(int);
	void operator++();

	void reset();
	bool last();

};

Interval::Interval(int a, int k) {

	if (k < 0 || a < 0 || a > k) {
		this->a = 0;
		this->k = 0;
	}

	this->a = a;
	this->k = k;
	this->current = a;
}

int Interval::operator*() {
	return current;
}

void Interval::operator++(int) {
	if (!last()) {
		++current;
	}
}

void Interval::operator++() {
	if (!last()) {
		current++;
	}
}

void Interval::reset() {
	current = a;
}

bool Interval::last() {
	return current == k;
}

class SquaredInterval: public Interval {

public:

	SquaredInterval(int a, int k);

	int operator*();

};

SquaredInterval::SquaredInterval(int a, int k): Interval(a, k) {
}

int SquaredInterval::operator*() {
	return Interval::operator*() * Interval::operator*();
}

int getLast(SquaredInterval interval) {
	do {
		++interval;
	} while (!interval.last());

	return *interval;
} 

void sortIntervals(SquaredInterval intervals[], int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (getLast(intervals[j]) > getLast(intervals[j + 1])) {
				SquaredInterval tmp = intervals[j];
				intervals[j] = intervals[j + 1];
				intervals[j + 1] = tmp;
			}
		}
	}
	
}

//int main() {
//
//	SquaredInterval i1(0, 10);
//	SquaredInterval i2(0, 2);
//	SquaredInterval i3(0, 15);
//	SquaredInterval i4(0, 20);
//	SquaredInterval i5(0, 12);
//	SquaredInterval i6(0, 22);
//
//	SquaredInterval intervals[] = { i1, i2, i3, i4, i5, i6 };
//
//	sortIntervals(intervals, 6);
//
//	for (Interval i: intervals) {
//		std::cout << i.getK() << " ";
//	}
//
//	return 0;
//}