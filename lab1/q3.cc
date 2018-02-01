#include <iostream> 

void fill_array(int array[10]);
void fill_array2(int array[], int first_value, int increment);

int main(void) {
	int array[10];
	fill_array(array);
	fill_array2(array, 4, 3);

}

	void fill_array(int array[10]) {
		for( int i = 0; i < 10 ; ++i) {
			array[i] = i + 1;
			std::cout << array[i] << std::endl;
		}
   }

	void fill_array2(int array[10], int first_value, int increment) {
		for( int m = 0; m < 10 ; ++m) {
			array[m] = first_value;
			first_value = first_value + increment;
			std::cout << array[m] << std::endl;
		}
   }









