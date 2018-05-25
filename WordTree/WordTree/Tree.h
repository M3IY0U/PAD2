// Fig. 18.17: Tree.h
// Template Tree class definition.

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <new>

#include "TreeNode.h"

// Tree class-template definition
template< typename NODETYPE > class Tree
{
public:
	Tree(); // constructor
	~Tree(); // destructor
	Tree(const Tree&) = delete; // no copies of Tree-objects allowed               
	const Tree& operator=(const Tree&) = delete; // no assignment allowed               
	void insertNode(const NODETYPE &);
	std::string preOrderTraversal() const;
	std::string inOrderTraversal() const;
	std::string postOrderTraversal() const;
	TreeNode< NODETYPE > * binaryTreeSearch(const NODETYPE &) const;
	std::string toString() const;
	void deleteNode(const NODETYPE &);
	unsigned getNodeCount() const { return nodeCount; }

private:
	TreeNode< NODETYPE > * rootPtr;
	unsigned nodeCount = 0;
	// utility functions
	void insertNodeHelper(TreeNode< NODETYPE > *&, const NODETYPE &);
	void preOrderHelper(TreeNode< NODETYPE > *, std::stringstream &) const;
	void inOrderHelper(TreeNode< NODETYPE > *, std::stringstream &) const;
	void postOrderHelper(TreeNode< NODETYPE > *, std::stringstream &) const;
	TreeNode< NODETYPE > * binarySearchHelper(TreeNode< NODETYPE > *,
		const NODETYPE &) const;
	void toStringHelper(TreeNode< NODETYPE > *, int, std::stringstream &) const;
	bool deleteNodeHelper(TreeNode< NODETYPE > *&, const NODETYPE &);
	void replaceNodeHelper(TreeNode< NODETYPE > *&, TreeNode< NODETYPE > *&);
	void destructorHelper(TreeNode< NODETYPE > *&);
}; // end class Tree

   // constructor
template< typename NODETYPE >
Tree< NODETYPE >::Tree()
{
	rootPtr = nullptr; // indicate tree is initially empty 
} // end Tree constructor

  // destructor
template< typename NODETYPE >
Tree< NODETYPE >::~Tree()
{
	std::cerr << "Destroying nodes ...\n";
	destructorHelper(rootPtr);
	std::cerr << "\nAll nodes destroyed\n\n";
} // end Tree destructor

  // insert node in Tree
template< typename NODETYPE >
void Tree< NODETYPE >::insertNode(const NODETYPE &value)
{
	insertNodeHelper(rootPtr, value);
} // end function insertNode

  // utility function called by insertNode; receives a reference to a
  // pointer so that the function can modify the pointer arguments's value
template< typename NODETYPE >
void Tree< NODETYPE >::insertNodeHelper(TreeNode< NODETYPE > *& ptr, const NODETYPE &value)
{
	// subtree is empty; create new TreeNode containing value
	if (ptr == nullptr) {
		ptr = new TreeNode< NODETYPE >(value);
		nodeCount++;
	} // end if
	else { // subtree is not empty
		   // data to insert is less than data in current node
		if (value < ptr->data) {
			insertNodeHelper(ptr->leftPtr, value);
		} // end if
		else {
			// data to insert is greater than data in current node
			if (ptr->data < value)
				insertNodeHelper(ptr->rightPtr, value);
			else { // duplicate data value; increment frequency
				++ptr->frequency;
			}
		} // end else
	} // end else
} // end function insertNodeHelper

  // begin preorder traversal of Tree
template< typename NODETYPE >
std::string Tree< NODETYPE >::preOrderTraversal() const
{
	std::stringstream outStream;
	preOrderHelper(rootPtr, outStream);
	return outStream.str();
} // end function preOrderTraversal

  // utility function to perform preorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::preOrderHelper(TreeNode< NODETYPE > * ptr, std::stringstream& outStream) const
{
	if (ptr != nullptr) {
		outStream << ptr->data << ' '; // process node          
		preOrderHelper(ptr->leftPtr, outStream); // traverse left subtree 
		preOrderHelper(ptr->rightPtr, outStream); // traverse right subtree
	} // end if
} // end function preOrderHelper

  // begin inorder traversal of Tree
template< typename NODETYPE >
std::string Tree< NODETYPE >::inOrderTraversal() const
{
	std::stringstream outStream;
	inOrderHelper(rootPtr, outStream);
	return outStream.str();
} // end function inOrderTraversal

  // utility function to perform inorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::inOrderHelper(TreeNode< NODETYPE > *ptr, std::stringstream& outStream) const
{
	if (ptr != nullptr) {
		inOrderHelper(ptr->leftPtr, outStream); // traverse left subtree  
		outStream << std::left <<ptr->data << std::setw(20) << std::setfill('.') << std::right << ptr->frequency << "\n"; // process node
		inOrderHelper(ptr->rightPtr, outStream); // traverse right subtree
	} // end if
} // end function inOrderHelper

  // begin postorder traversal of Tree
template< typename NODETYPE >
std::string Tree< NODETYPE >::postOrderTraversal() const
{
	std::stringstream outStream;
	postOrderHelper(rootPtr, outStream);
	return outStream.str();
} // end function postOrderTraversal

  // utility function to perform postorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::postOrderHelper(TreeNode< NODETYPE > *ptr, std::stringstream& outStream) const
{
	if (ptr != nullptr) {
		postOrderHelper(ptr->leftPtr, outStream); // traverse left subtree  
		postOrderHelper(ptr->rightPtr, outStream); // traverse right subtree
		outStream << ptr->data << ' '; // process node                  
	} // end if
} // end function postOrderHelper

  // begin binary search
template< typename NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binaryTreeSearch
(const NODETYPE & val) const
{
	return binarySearchHelper(rootPtr, val);
} // end function binaryTreeSearch

  // do a binary search on the Tree; NODETYPE::operator< required
template< typename NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binarySearchHelper(
	TreeNode< NODETYPE > *ptr, const NODETYPE & value) const
{
	// if value is not found
	if (ptr == nullptr)
		return nullptr;
	std::cerr << "Comparing " << value << " to " << ptr->getData();
	if (value < ptr->getData()) { // search value less than current data
		std::cerr << "; smaller, walk left\n";
		return binarySearchHelper(ptr->leftPtr, value);
	} // end if
	else if (ptr->getData() < value) { // value greater than current data
		std::cerr << "; larger, walk right\n";
		return binarySearchHelper(ptr->rightPtr, value);
	} // end else if
	else { // match
		std::cerr << "; search complete\n";
		return ptr;
	} // end else
} // end function binarySearchHelper

  // return the tree as a string
template< typename NODETYPE >
std::string Tree< NODETYPE >::toString() const
{
	std::stringstream outStream;
	toStringHelper(rootPtr, 2, outStream);
	return outStream.str();
} // end function toString

  // utility function to return the tree as a string
template< typename NODETYPE >
void Tree< NODETYPE >::toStringHelper(TreeNode< NODETYPE > * ptr, int totalSpaces, std::stringstream& outStream) const
{
	if (ptr != nullptr) {
		toStringHelper(ptr->rightPtr, totalSpaces + 5, outStream);
		outStream << setw(totalSpaces) << ptr->data << '\n';
		toStringHelper(ptr->leftPtr, totalSpaces + 5, outStream);
	} // end if
} // end function toStringHelper

  // delete node in Tree 
template< class NODETYPE >
void Tree< NODETYPE >::deleteNode(const NODETYPE &value)
{
	std::cerr << "deleteNode called for: " << value;
	if (deleteNodeHelper(rootPtr, value))
		std::cerr << " <- node deleted!" << endl;
	else
		std::cerr << " <- node not found!" << endl;
} // end function deleteNode

  // utility function called by deleteNode; receives a reference to a
  // pointer so that the function can modify pointer argument's value
template< class NODETYPE >
bool Tree< NODETYPE >::deleteNodeHelper(
	TreeNode< NODETYPE > *&ptr, const NODETYPE &value)
{
	TreeNode< NODETYPE > *tempPtr;
	if (ptr == nullptr) // data not found in tree; no deletion possible
		return false;
	else
		// data to delete is less than data in current node; move to left child
		if (value < ptr->data)
			return deleteNodeHelper(ptr->leftPtr, value);
		else
			// data to delete greater than data in current node; move to right child
			if (ptr->data < value)
				return deleteNodeHelper(ptr->rightPtr, value);
			else {
				tempPtr = ptr; // node to be deleted
							   // one (or zero) left child: 
							   // child node takes place of node that will be deleted
				if (tempPtr->rightPtr == nullptr)
					ptr = tempPtr->leftPtr;
				else
					// one right child: 
					// child node takes place of node that will be deleted
					if (tempPtr->leftPtr == nullptr)
						ptr = tempPtr->rightPtr;
					else
						// two children: replace value to be deleted
						replaceNodeHelper(tempPtr, tempPtr->rightPtr);
				delete tempPtr;
				return true;
			}
} // end function deleteNodeHelper

  // utility function called by deleteNodeHelper for deletion of node with two childen
template< class NODETYPE >
void Tree< NODETYPE >::replaceNodeHelper(
	TreeNode< NODETYPE > *& tempPtr, TreeNode< NODETYPE > *& right)
{
	if (right->leftPtr != nullptr)
		// look for smallest value in right subtree
		replaceNodeHelper(tempPtr, right->leftPtr);
	else {
		// replace value to be deleted with smallest value in right subtree
		tempPtr->data = right->data;
		tempPtr = right; // now this node has to be deleted
		right = right->rightPtr; // unlink the node that will be deleted
	}
} // end function replaceNodeHelper

  // utility function called by destructor for 
  // deletion of subtrees using postorder traversal
template< class NODETYPE >
void Tree< NODETYPE >::destructorHelper(TreeNode< NODETYPE > *& ptr)
{
	if (ptr != nullptr) {
		destructorHelper(ptr->leftPtr); // delete left subtree
		destructorHelper(ptr->rightPtr); // delete right subtree
		//std::cerr << ptr->getData() << ' ';
		delete ptr; // delete root
		ptr = nullptr; // empty tree: rootPtr == nullptr
	}
}

#endif