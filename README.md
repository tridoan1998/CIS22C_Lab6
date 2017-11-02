# 
De Anza College CIS

Search this site
Home
CIS36A
CIS22C
CIS22A
Lab 6 (100 pts)
Due Tuesday, October 7 at 11:20am on Canvas


Pair Programming Extra Credit Opportunity (5 pts)
If you and/or your partner has not done so already, watch the video and answer the questions on this worksheet (only one time per quarter).
Both partners fill in, sign and date the pair programming contract (once per assignment).
Upload the document(s) along with your Lab to Canvas.
Only ONE partner submits the lab assignment on Canvas. Please make sure both your names are on it.

Part 1: BST Header File
Copy and paste the following into a file named BST.h
#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <assert.h>

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

    void copyNode(Node* copy) const;
    //recursive helper function to the copy constructor

    void freeNode(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bool searchNode(Node* root, bstdata data);
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
#endif /* BST_H_ */



Also create a test file called BSTTest.cpp.
Note: The prototypes for the helper functions must be contained inside the class definition under private
However, the private helper functions must be implemented below the class definition, along with the rest of the functions.


Part 2: Implementing The Functions



Insert/InsertNode, Search/SearchNode, Minimum, Maximum, Remove/deleteNode

See the pseudocode provided in this weeks' lesson notes


Tree Traversals

Now, we are going to add what are called "Tree Traversals" to our BST data structure.
We are going to add them as printing functions to allow us to print out the data in our BST.
To help you understand these concepts, I recommend that you watch this video on tree traversals.


inOrderPrint

Our code so far is currently unsatisfactory because we are only able to print out the value at the root of the tree.
Let's write a print function for our BST.
Because a BST is not a linear structure, there are multiple approaches that we can take to printing out its contents.
Look at the example below and you will see that there are various printing options.


One of these is to do what we call "Printing In Order."
InOrderPrint will print the values from smallest to largest.
So, for the tree above, it would print the values as: 1 3 4 6 7 8 10 13 14
Again, this is a recursive process, which goes left root right
The pseudocode for inOrderPrintHelper is as follows:
Pseudocode for inOrderPrint(root)

1. If the root is not NULL

a. Call inOrderPrint recursively on the root leftchild.

b. Print the data at the root

c. Call inOrderPrint recursively on the root rightchild



Implement the above function in your code and then test it by adding some new data to your BST and then call preOrderPrint on your BST object.


preOrder and postOrder print

Once again, BSTs are not linear structures, so there are many "orderings" in which we could print out the data contained in the nodes.
We saw the recursive inOrderPrint above
You are now going to write preOrderPrint and postOrderPrint and their helper functions.
These functions are also recursive.
Below is the pseudocode for these two functions.
Note the similarities and differences between these functions and inOrderPrint.
When does the inOrder print call cout compared to preOrderPrint and postOrderPrint?

Pseudocode for preOrderPrint(root)
1. If the root is not NULL
    a. Print the data at the root
    b. Call preOrderPrint recursively on the root leftchild
    c. Call preOrderPrint recursively on the root rightchild


Pseudocode for postOrderPrint(root)
1. If the root is not NULL
    a. Call postOrderPrint recursively on the root leftchild
    b. Call postOrderPrint recursively on the root rightchild
    c. Print the data at the root

Note that the placement of the print statement inside these functions causes them to print the data in very different orderings.
Below is an example of preOrder, postOrder and inOrder print orderings on the same tree:


Just like with the inOrderPrint, you should implement these functions by calling helper functions, which do most of the recursive work.
Make sure to test these functions inside of your BSTTest.cpp




Copy Constructor, Destructor, getSize
Now that you are familiar with tree traversals, you can write the destructor and copy constructor.
The BST destructor must traverse the Tree, freeing the memory of each Node, one-by-one.
Hint: one tree traversal is particularly suited to the purposes of this function.
A different tree traversal should be adapted for the copy constructor
Any of the traversals can be adapted for getSize

getHeight
Hint: Make sure that you recognize the height of a NULL child is -1, not 0, or your getHeight function will not give the correct height.

What to Submit
Submit your BST.h and your BSTTest.cpp, including ALL of the tests you ran on your code to Canvas. 
 Note that you should be testing each function from your header file at least twice!
Each function is worth 6 points and your BSTTest.cpp is worth 10 points.

Sign in|Recent Site Activity|Report Abuse|Print Page|Powered By Google Sites
