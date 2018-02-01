// in codetree.cpp
#include "codetree.h"
#include "binaryHeap.cpp"
#include <algorithm>
using namespace std;
CodeTree::CodeTree(int *array)
{
	freq = array;
}
	
void CodeTree::printChar(int ch) 
{

	if( ch < 16 ) {
		std::cout << "x0" << std::hex << ch;
		}
	else if ( ch < 32 || ch > 126) {
		std::cout << "x" << std::hex << ch;
		}
	else {
		std::cout << "\"" << (char)ch << "\"";
		}
}


void CodeTree::printTree( TreeNode * r, std::string pre )
{
	if( r == NULL ) return;
	
	if( r->right == NULL ) {
		printChar(r->ch); 
		std::cout << std::endl; 
		} 
		 else {
			std::cout << "." << std::endl;
			std::cout << pre << "|'1-";
			printTree(r->right, pre + "|  ");
			std::cout << pre << "'-0-";
			printTree(r->left, pre + "   ");
		}		
}	

void CodeTree::printCode(TreeNode * r, std::string pre)
{
	if(!r) return;
	if (r->ch != '$'){
		printChar(r->ch); // prints letter
		std::cout << ": " << pre << std::endl; // prints code
	}
	printCode(r->left, pre + "0");
	printCode(r->right, pre + "1");
}


std::vector<TreeNode*> CodeTree::makeHeap(){
	
	std::vector<TreeNode*> heap;
	
	
	//if frequency of ASCII value is not 0, create a new TreeNode and push it to 'heap'
	for ( int i = 0; i < 256; i++){ 
		if (freq[i] !=0){
			heap.push_back(new TreeNode(i, freq[i]));
		}
	}
	
	heapify(heap, heap.size()); //Takes vector 'heap' and turns it into a heap
	std::reverse(heap.begin(), heap.end()); //reversed because heap.pop_front() does not exists, only heap.pop_back() exists
	
	//for( std::vector<TreeNode*>::iterator it = heap.begin(); it != heap.end(); it++){
	//	printChar((*it)->ch);
	//	std::cout << " " << (*it)->freq << std::endl;
	//}
	
	return heap;
}

void CodeTree::HuffmanCode(){
	
	std::vector<TreeNode*> heap = makeHeap();
	
	while ( heap.size() != 1 ){ 
		TreeNode* left = heap.back(); // takes last element (but sinced heap is reversed its actually first element)
		heap.pop_back(); // removes last element 
		TreeNode* right = heap.back(); // repeat for right element
		heap.pop_back();
		
		TreeNode* temp = new TreeNode('$', left->freq + right->freq); //Create new node with value '$' for easy distinction
		temp->left = left; //assign children
		temp->right = right;
		
		heap.push_back(temp); //push new node to heap
		heapify(heap, heap.size()); //re-heapify array
		std::reverse(heap.begin(), heap.end()); //reverse again
		
		//I realise this is somewhat expensive since we must constantly re-heapify on every iteration, but it works
	}
	
	std::cout << heap.size() << std::endl;
	std::cout << heap[0]->freq << std::endl;
	
	printTree(heap[0], " ");
	printCode(heap[0], "");

	
}

	





