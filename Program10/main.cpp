//  Program10LinkedList
//  Created by Minjing Liang on 10/31/20.
#include <iostream>
using namespace std;
class LinkedList{  // Declare a list class
private:
    struct ListNode{  // Declare a structure for the list
        double value;   // The value in this node
        struct ListNode *next; // To point to the next node
    };
    ListNode *head;  // List head pointer
public:
    LinkedList(){   //Default constructor
        head = nullptr;
        cout <<"Now the list is empty" <<endl;
    }
    LinkedList(const LinkedList& listObj); // Copy construction
    void add(double x);  // Add node to the front of the list
    bool isMember(double x); // Check element funtion
    void remove(double x); // Remove element function
    bool recursiveSearch(double x, ListNode *h = NULL); // Recursive search funciton
    void reverse(); // Reverse funciton
    void displayList()const;//Display function
    ~LinkedList(); //Destructor
};
int main() {
    LinkedList listA;  //Create a list object
    cout << "List A is pringting.";
    listA.displayList(); //Display the list
    listA.add(12.5); //Add a new node the front of the lis
    listA.add(7.9);
    listA.add(2.6);
    cout << "List A is pringting.";
    listA.displayList(); //Display listA
    listA.isMember(7.9); //Call check member function
    LinkedList listB(listA); //Create a new list object call copy constructor
    cout << "List B is pringting.";
    listB.displayList();  //Display ListB
    listB.isMember(2.6); //Call check member function
    cout <<"Call recursive search function.\n";
    listA.recursiveSearch(12.5); //Call recursive funcion with one default argument
    listA.reverse(); //Call reverse funciton
    cout << "List A is pringting.";
    listA.displayList();
    listA.remove(2.6); //Call remove funtion
    cout << "List A is pringting.";
    listA.displayList();
    return 0;
}
void LinkedList::add(double x){  //Add a new node to front of the list
    ListNode* newNode = new ListNode;  //Point to a new node and allocate
    newNode->value = x;                //Store num there
    newNode->next = head;              // New node to the front
    head = newNode;
}
bool LinkedList::isMember(double x){ //Check the value in the list
    cout << "IsMember function is called.\n";
    ListNode *p = head;        // To move through the list
    while (p != NULL){         // Traverse the list
        if (p->value == x){    // Search the value match to the x
            cout <<"The value " << x << " is found in the list\n";
            return true;
        }
        else
            p = p->next;  //Pot to the next node
    }
    cout <<"Value not found.\n";
    return false;     //Value not in the list
}
LinkedList::LinkedList(const LinkedList& listObj){   // Copy constructor
    if (listObj.head == NULL) {   //ListObj is empty
        head = NULL;
    }
    else{                        // ListObj not empty
        ListNode* newNode = new ListNode; //A new node
        head = newNode; //Point to the head
        newNode->value = listObj.head->value;//Copy value to the first node
        newNode->next = nullptr; //Initial point with null
        ListNode* copyPtr = listObj.head; //Point to the head of the old obj
        while(copyPtr->next != nullptr){ //Pointer to traverse the list
            newNode->next = new ListNode; //A new node
            newNode->next->value = copyPtr->next->value; //Copy value
            newNode->next->next = nullptr; //Initial pointer with null
            newNode = newNode->next; //Move to the next
            copyPtr = copyPtr->next; //Move to the next
        }
    }
}
bool LinkedList::recursiveSearch(double x, ListNode *h){ //Recursive funciton
    if(h == NULL) //First called in main function
        h = head; // Initial h with head
    if(h == NULL) // base case
        return false;
    if(h->value == x){ //Value found
        cout <<"The value " << x << " is found in the list\n";
        return true;
    }
    else{ //
        if (h->next == NULL){  // Traver the list and not found
            cout << "Value not found\n";
            return false;
        }
        else
            return recursiveSearch(x,h->next); // Recursive to next node
    }
}
void LinkedList::reverse(){ //Reverse order function
    ListNode *current = head; //Initial current node point to the head
    ListNode *prev = NULL, *next = NULL;
    while(current != NULL){
        next = current->next; //Store next
        current->next = prev; //Reverse current node's pointer
        prev = current; //Move pointers one positon ahead
        current = next;
    }
    head = prev;
    cout << "The reverse function is called." <<endl;
}
void LinkedList::remove(double x){  //Remove node function
    ListNode *nodePtr;            //To traverse the list
    ListNode *previousNode = NULL;//To point to the previouse node
    if(!head)        //List is empty, do nothing
        return;
    if (head->value == x){   //If x in the first node
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else{
        nodePtr = head; //Initial nodePtr to head of the list
        while(nodePtr!=nullptr && nodePtr->value != x){ //Skip node value is not x
            previousNode = nodePtr;
            nodePtr = nodePtr ->next;
        }
        if(nodePtr){ //Not at the end
            previousNode->next = nodePtr->next; //Link to next
            delete nodePtr; //Delete the node with value x
        }
    }
    cout << "The remove function is called,";
    cout << "value removed from the list is: " << x <<endl;
}
void LinkedList::displayList() const{
    ListNode *nodePtr; //To move through the list
    nodePtr = head; // Position nodeptr at the heat of the list
    cout<< "The values in the list are: \n";
    while(nodePtr){ //Traverse the list
        cout << nodePtr->value <<endl; //Display the node value
        nodePtr = nodePtr->next; //Move to the next node
    }
}
LinkedList::~LinkedList(){ //Destructor
    ListNode *nodePtr; //To traverse the list
    ListNode *nextNode; //To point to the next node
    nodePtr = head;   // Position the nodePtr at the head of the list
    while(nodePtr != nullptr){     //Not at the end
        nextNode = nodePtr->next; //Save a point to the next
        delete nodePtr;           // Delete the current node
        nodePtr = nextNode;       // Position nodePtr at the next node
    }
}
