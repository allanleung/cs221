#include <iostream>

using namespace std;

//PRE:  The capacity of the array pointed to by heap is at least size.
//POST: The first size elements of heap are printed to the screen.
void printList(std::vector<TreeNode*> heap, int size) {
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

// PRE:  subtrees rooted at leftChild and rightChild of i are heaps.
// POST: subtree rooted at i is a heap.
void swapDown(std::vector<TreeNode*> &heap, int i, int size) {
	std::cout << "in swapDown" << std::endl;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int min = i;
	std::cout << min << std::endl;
	std::cout << heap[min]->freq << std::endl;
    // find who holds smallest element of i and its two children
    if (leftChild < size && heap[leftChild]->freq < heap[min]->freq)
        min = leftChild;
    if (rightChild < size && heap[rightChild]->freq < heap[min]->freq)
        min = rightChild;
    // if a child holds smallest element, swap i's element to that child
    // and recurse.
    if (min != i) {
        swap(heap[i], heap[min]);
        swapDown(heap, min, size);
    }
}

//PRE:  The capacity of the array pointed to by heap is at least size.
//POST: The first size elements of heap are a heap.
void heapify(std::vector<TreeNode*> &heap, int size) {
	std::cout << "in heapify" << std::endl;
    for (int i = (size - 2) / 2; i >= 0; i--){
        swapDown(heap, i, size);
	}
}


