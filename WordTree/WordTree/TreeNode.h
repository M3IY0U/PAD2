// Fig. 18.16: Treenode.h
// Template TreeNode class definition.

#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
template< typename NODETYPE > class Tree;

// TreeNode class-template definition
template< typename NODETYPE >
class TreeNode
{
	friend class Tree< NODETYPE >;
public:
	// constructor
	TreeNode(const NODETYPE &d) : leftPtr(nullptr), data(d), rightPtr(nullptr),frequency(1) {}
	NODETYPE getData() const { return data; }
	int getFreq() const { return frequency; }
private:
	TreeNode* leftPtr;
	int frequency;
	//int dataLength;
	NODETYPE data;
	TreeNode* rightPtr;
};
#endif