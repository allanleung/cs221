#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps = 0;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

int qc(int n){
	if (n<=1){
		return 0;
	}

	int pivot = randint(0, n-1);
	int count = n - 1;
	return count + qc(pivot) + qc(n - pivot -1); 
}

void quicksort(int a, int b) {

	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]); 
	// this is the f up part, this swap makes it unstable because 
	// there is a chance it will swap the element with the same value to go first 
	// so it makes it not stable 
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 10

int main(int argc, char *argv[]) {
	srand(time(0));
	comps = 0;

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	for (int i = 0; i<10; i++) {
		quicksort(0, NN-1);
		std::cout << comps << std::endl;

		for (int i=0; i<NN; ++i) {
			//std::cout << x[i] << " ";
		}
	}
	std::cout <<  comps <<std::endl;
	std::cout << qc(10) <<std::endl;

	delete[] x;
	return 0;
}

