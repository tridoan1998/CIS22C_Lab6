/*
 * List.h
 *
 *	Khang Vinh Tran, Tri Doan
 *  CIS 22C, Lab5
 */
#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;
template<typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* leftchild;
        Node* rightchild;

        Node(bstdata newdata){
            data = newdata;
            leftchild = NULL;
            rightchild = NULL;
        }
    };

    Node* root;

    /**Private helper functions*/
    	void insertNode(Node* root, bstdata data);
    //private helper function for insert
    //recursively inserts a value into the BST

    	void inOrderPrint(ostream& out, Node* root) const;
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    	void preOrderPrint(ostream& out, Node* root) const;
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    	void postOrderPrint(ostream& out, Node* root) const;
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyNode(Node* copy);
    //recursive helper function to the copy constructor

    	void freeNode(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    	bool searchNode(Node* root, bstdata data) const;
    //recursive helper function to search
    //returns whether the value is found in the tree

    	bstdata minimum(Node* root) const;
    //recursive helper function to minimum
    //returns the minimum value in the tree

    	bstdata maximum(Node* root) const;
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* deleteNode(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    	void getSize(Node* root, int& size) const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    	int getHeight(Node* root) const;
    //recursive helper function to the height function
    //returns the height of the tree

public:

    /**constructors and destructor*/

    	BST();
    //Instantiates a new BST

    BST(const BST &bst);
    //copy constructor

    	~BST();
    //deallocates the tree memory

    /**access functions*/

    	bstdata minimum() const;
    //returns the minimum value in the BST
    //pre: !empty()

    	bstdata maximum() const;
    //returns the maximum value in the BST
    //pre: !empty()

    	bool isEmpty() const;
    //determines whether the BST is empty

    	int getSize() const;
    //returns the size of the tree

    	bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    	int getHeight() const;
    //returns the height of the tree

    	bool search(bstdata data) const;
    //returns whether the data is found in the tree
    //pre: !isEmpty()

    /**manipulation procedures*/

    	void insert(bstdata data);
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    	void inOrderPrint(ostream& out) const;
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    	void preOrderPrint(ostream& out) const;
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    	void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};


/****************constructors and destructor*****************/

template <class bstdata>
BST<bstdata>::BST()
{
	root = NULL;
}

template <class bstdata>
BST<bstdata>::~BST()
{
    freeNode(root);
}

template <class bstdata>
void BST<bstdata>::freeNode(Node* root)
{
	if(root == NULL)
		return;
	else
	{
		freeNode(root->leftchild);
		freeNode(root->rightchild);
		delete root;
	}
}
/*
template <class bstdata>
BST<bstdata>::BST(const BST &bst)
{
   copyNode(root);
}

template <class bstdata>
void BST<bstdata>::copyNode(Node* copy)
{
	 root = copy->data;
	 copyNode(copy->data->leftchild);
	 copyNode(copy->data->rightchild);
}

*/


/***************manipulation procedures***************/

template <class bstdata>
void BST<bstdata>::insert(bstdata data)
{
    if (root == NULL)
    {
        root = new Node(data); //if the tree is empty insert the value at the root
    }
    else
    {
        insertNode(root, data); //otherwise call the helper function, passing it the root
    }
}

template <class bstdata>
void BST<bstdata>::insertNode(Node* root, bstdata data)
{
	if(root->data == data)	// base case
	{
		return;
	}
	else if(root->data > data)
	{
		if(root->leftchild == NULL)
		{
			root->leftchild = new Node(data);
		}
		else
		{
			return insertNode(root->leftchild, data);
		}
	}
	else
	{
		if(root->rightchild == NULL)
		{
			root->rightchild = new Node(data);
		}
		else
		{
			insertNode(root->rightchild, data);
		}

	}
}

template <class bstdata>
bool BST<bstdata>::search(bstdata data) const
{
	//Add code to check for the precondition here
	if(data == root->data)
		return true;
	else
		searchNode(root, data); //call helper function
}

template <class bstdata>
bool BST<bstdata>::searchNode(Node* root, bstdata data) const
{
	if(root->data == data)
		return true;
	else if(root->data < data)
		{
			if(root->leftchild == NULL)
				return false;
			else
				searchNode(root->leftchild, data);
		}
	else
		{
		if(root->rightchild == NULL)
			return false;
		else
			searchNode(root->rightchild, data);
		}
	return false;
}



/****************access functions********************/

template <class bstdata>
bool BST<bstdata>::isEmpty() const
{
	return (getSize() == 0);
}

template <class bstdata>
bstdata BST<bstdata>::getRoot() const
{
	assert(!isEmpty());
	return root->data;
}

template <class bstdata>
int BST<bstdata>::getSize() const
{
	int size = 0;
	getSize(root, size);
	return size;
}

template <class bstdata>
void BST<bstdata>::getSize(Node* root, int& size) const
{
	if(root == NULL)
		return;
	else
	{
		size++;
		getSize(root->leftchild, size);
		getSize(root->rightchild, size);
	}
}


/*
template <class bstdata>
void BST<bstdata>::remove(bstdata data)
{
	Node* BST<bstdata>::deleteNode(Node* root, bstdata data);
}

template <class bstdata>
typename BST<bstdata>::Node* BST<bstdata>::deleteNode(Node* root, bstdata data)
{
	if(root == NULL)
		return root;
	if(data < root->data)
		root->leftchild = deleteNode(root->leftchild, data);
}
*/



template <class bstdata>
int BST<bstdata>::getHeight() const
{
	return getHeight(root);
}

template <class bstdata>
int BST<bstdata>::getHeight(Node* root) const
{
	if(root == NULL)
		return -1;
	else
	{
		if(getHeight(root->leftchild) >= getHeight(root->rightchild))
			return 1+getHeight(root->leftchild);
		else
			return 1+getHeight(root->rightchild);
	}
}

template <class bstdata>
bstdata BST<bstdata>::minimum() const
{
	assert(!isEmpty());
	return minimum(root);
}

template <class bstdata>
bstdata BST<bstdata>::minimum(Node* root) const
{
	if(root->leftchild == NULL)
		return root->data;
	else
		return minimum(root->leftchild);
}

template <class bstdata>
bstdata BST<bstdata>::maximum() const
{
	assert(!isEmpty());
	maximum(root);
}

template <class bstdata>
bstdata BST<bstdata>::maximum(Node* root) const
{
	if(root->rightchild == NULL)
		return root->data;
	else
		return maximum(root->rightchild);
}


/************ additional functions ************/

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out) const
{
    inOrderPrint(out, root);
    cout << endl;
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream& out, Node* root) const
{
	if(root == NULL)
		return;
	else
	{
		inOrderPrint(out, root->leftchild);
		cout << root->data << " ";
		inOrderPrint(out, root->rightchild);
	}
}

template <typename bstdata>
void BST<bstdata>::preOrderPrint(ostream& out) const
{
	preOrderPrint(out, root);
	cout << endl;
}

template <typename bstdata>
void BST<bstdata>::preOrderPrint(ostream& out, Node* root) const
{
	if(root == NULL)
		return;
	else
	{
		cout << root->data << " ";
		preOrderprint(out, root->leftchild);
		preOrderprint(out, root->rightchild);
	}
}

template <typename bstdata>
void BST<bstdata>::postOrderPrint(ostream& out) const
{
	postOrderPrint(out, root);
	cout << endl;
}

template <typename bstdata>
void BST<bstdata>::postOrderPrint(ostream& out, Node* root) const
{
	if(root == NULL)
		return;
	else
	{
		postOrderPrint(out, root->leftchild);
		postOrderPrint(out, root->rightchild);
		cout << root->data << " ";
	}
}

#endif /* BST_H_ */
