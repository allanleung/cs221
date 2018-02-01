// in codetree.h

#ifndef CODETREE_H
#define CODETREE_H

#include <iostream>
#include <vector>
struct TreeNode{
	int ch;
	unsigned freq;
	TreeNode *left, *right;
	
	TreeNode(int ch, unsigned freq){
		left = NULL;
		right = NULL;
		this->ch = ch;
		this->freq = freq;
	};
	
};

class CodeTree
{
	int *freq;
	
	public:
		CodeTree(int *array);
		std::vector<TreeNode*> makeHeap();
		void printCode(TreeNode * r, std::string pre);
		void printTree(TreeNode * r, std::string pre);
		void printChar(int ch);
		void HuffmanCode();
		
};

#endif
