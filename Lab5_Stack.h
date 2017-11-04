#ifndef Stack_H_
#define Stack_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template <class stackdata>
class Stack
{
    public:
        /**constructors and destructors**/

        Stack();

        //initializes an empty stack
        //postcondition: an empty stack

        Stack(const Stack& S);
        //initializes this stack to have same elements as S
        //postcondition: a copy of stack


        ~Stack();
        //frees memory allocated to the stack
        //postcondition: memory for stack has been freed

        /**manipulation procedures**/

        void pop();
        //removes an element from the top of the stack
        //precondition: size != 0
        //postcondition: an element has been removed from the top of the stack

        void push(stackdata data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors**/


       bool operator==(const Stack &S);
       //returns whether this stack is equal to another stack S

       stackdata peek() const;
       //returns the element at the top of the stack
       //precondition: size != 0

       int getSize() const;
       //returns the size of the stack

       bool empty() const;
       //returns whether the stack is empty


       /**additional operations**/

       void print() const;
       //prints the elements in the stack each element separate by a blank space to stdout

        void reversePrint() const;
    private:
       struct Node {
           stackdata data;
           Node* link;

           Node(stackdata ndata) {

data = ndata;
link = NULL;
            }

        };

       Node* top;
       int size;

    void revesePrint() const;
};

template<class stackdata>
Stack<stackdata>::Stack()
{
    size = 0;
    top = NULL;
}




template<class stackdata>
Stack<stackdata>::~Stack()
{
    Node* a = NULL;
    Node* b = top;
    while(b != NULL)
    {
        b->link = a;
        delete b;
        b = a;
    }
}



template<class stackdata>
Stack<stackdata>::Stack(const Stack& S)
{
    size = S.size;
    top = new Node(S.top->data);
    Node* temp = S.top;
    Node* stemp = top;
    while(temp !=NULL)
    {
        temp = temp->link;
        stemp->link = new Node(temp->data);
        stemp = stemp->link;
    }
}


template<class stackdata>
Stack<stackdata>::pop()     //removeStart
{
    assert(size !=0);
    if(size == 1)
    {
        delete top;
        top = NULL;
    }
    else
    {
        Node* temp = top;
        top = top->link;
        delete temp;
    }
    size--;
}


tempplate<class stackdata>
Stack<stackdata>::push(stackdata data)     //insertStart
{
    Node* N = new Node(data);
    if(size == 0)
    {
        top = N;
    }
    else
    {
        N->link = top;
        top = N;
    }
    size++;
}


template <class stackdata>
bool Stack<stackdata>::operator==(const Stack &S)
{
	if(size != S.size)
		return false;
	Node* temp1 = top;
	Node*temp2 = S.top;
	while(temp1 !=NULL)
	{
		if(temp1 != temp2)
			return false;
		temp1 = temp1->link;
		temp2 = temp2->link;
	}
	return true;
}




template<class stackdata>
stackdata Stack<stackdata>::peek() const	//getFront
{
    asset(!empty());
    return top->data;
}


template <class stackdata>
int Stack<stackdata>::getSize() const
{
    return size;
}
{
    
}

template <class stackdata>
bool Stack<stackdata>::empty() const
{
    return size == 0;
}

template<class stackdata>
void Stack<stackdata>::print() const
{
    Node* temp = top;
    while(temp !=NULL)
    {
        cout << temp->data << " ";
        temp = temp->data;
    }
    cout << endl;
}

void reversePrint() const;
{
    assert(!empty());
    
}
#endif /* QUEUE_H_ */