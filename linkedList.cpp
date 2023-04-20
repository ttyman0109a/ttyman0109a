#include <iostream>

using namespace std;

class linkedList {

public:
	class Node { 
		
	public: //must be public for the reverselist to work
		double value;
		Node *next;
	};

	Node *head; //define head node
	linkedList() {  //constructor
		head = NULL;
	}
	
	void append(double num);
	void insert(double num);
	void deleteNode(double num);
	void prepend(double num);
	void reverseList();
	int displayList();
	void reverseDisplay(Node *head);

	~linkedList (); // destructor
}; 
	void linkedList::append(double num){
        Node *newNode;

		//build new node
		newNode = new Node;
		newNode->value = num;
		newNode->next = NULL;

		// head is NULL, list empty, insert node
		if (head == NULL){
			head = newNode;
		}
		else {
			Node *current;
			current = head; // start at head
			while (current->next) { // while (current->next) is not NULL
				current = current->next; // goto next node i++
			}
			current->next = newNode; // else put new node there
		} 
	}
	void linkedList::insert(double num) {
		Node *newNode;
		Node *current; // ptr to traverse list (cursor)
		Node *prev; // ptr to prev

		//allocate new node
		newNode = new Node;
		newNode->value = num;

		current = head; // start from head
		while (current != NULL && current->value < num){ // if p is not null and value < num 
			 prev = current;  //save prev
			 current = current->next; //advance
		}

		if (current == head){ //insert before first
			head = newNode;
			newNode->next = current;
		}
		else {
			prev->next = newNode; //insert after prev
			newNode->next = current;
		}
	}
	void linkedList::deleteNode(double num){
		Node *current = head; //ptr to traverse list
		Node *prev; //ptr to prev 

		//save previous
		while(current != NULL && current->value != num){  // !NULL and number not found, skip nodes
			prev = current; // save to prev
			current = current->next; // advance
		}
		// p is not NULL (p) and value is found
		// set links and delete
		if (current != NULL) {
			if (current == head) {// p points to first elem, one node
				head = current->next; // point head to next
				delete current;
			}
			else{
				prev->next = current->next; //point next element to prev
				delete current;
			}
		}
	}

	int linkedList::displayList(){
		Node *current;
		int count = 0;
		current = head; // start at beginning
        if (current == NULL){
        	cout << "List is empty" << endl;
        	count = 0;
        	return count;
        }
        else {
			while (current != NULL){ //(p) same as !=NULL
				cout << current->value << " ";
				current = current->next;
				count++;
			}
			cout << endl;
			return count;
		}
	}

	void linkedList::prepend(double num){
		Node *newNode;
		Node *prev;
		//build new node
		newNode = new Node;
		newNode->value = num;

		Node *current;
		current = head; // start at head

		if (current == NULL){ //empty list, insert
			head->next = newNode;
			newNode->next = NULL;
		}
		else {
			prev = head; //save
			head  = newNode;  
			head->next = prev;
		}
	}

    void linkedList::reverseList(){ // from geeksforgeeks
    	Node *current;
    	Node *prev = NULL;
    	Node *next = NULL;
    

    	current = head;
    	while (current != NULL){
    		next = current->next;  // store next
    		current->next = prev;  // reverse current node's pointer
    		prev = current; // Move pointers one position ahead
    		current = next;
    	}
    	head = prev;

    }

    void linkedList::reverseDisplay(Node *head){
    	
    	if (head == NULL){ // exit condition
    		return;
    	}

    	// print list afterwards
    	reverseDisplay(head->next);

    	// print head after everything else is printed
    	cout << head->value << " ";

    }
linkedList::~linkedList (){ // destrictor
		Node *current;
		Node *next; 

		cout << "Destructor: Delete "; 
		current = head;
		while (current != NULL){
			next = current->next; // save next
			cout << current->value << " ";
			delete current; // delete curr
			current = next; // advance
		}
		cout << endl;
}
int main(int argc, char *argv[]){
	int c = 0; // Node count
	//linkedList::Node *head = NULL;
	linkedList ll;
	
	ll.displayList();
	cout << "Insert 0-20: "; 
	for (int i = 0; i <= 20; i++){
		ll.insert(i);
	}
	c = ll.displayList();
	cout << "Node Count: " << c << endl << endl;
	
	cout << "Delete 0, 5, 13, 14, 16: ";
	ll.deleteNode(0);
	ll.deleteNode(5);
	ll.deleteNode(13);
	ll.deleteNode(14);
	ll.deleteNode(16);
	c = ll.displayList();
	cout << "Node Count: " << c << endl << endl;
	
	cout << "Append 21, 22: ";
	ll.append(21);
	ll.append(22);
	c = ll.displayList();
	cout << "Node Count: " << c << endl << endl;

	cout << "Reverse Display:  ";
	ll.reverseDisplay(ll.head); // must use ll.head to ref head inside instance
	cout << endl << endl;

	cout << "Insert 0, 5, 13, 14, 16: ";
	ll.insert(0);
	ll.insert(5);
	ll.insert(13);
	ll.insert(14);
	ll.insert(16);
	c = ll.displayList();

	cout << "Prepend 5, 9, 6: ";
	ll.prepend(5);
	ll.prepend(9);
	ll.prepend(6);
	c = ll.displayList();
	cout << "Node Count: " << c << endl << endl;

	cout << "Append 23-30: "; 
	for (int i = 23; i <= 30; i++){
		ll.append(i);
	}
	c = ll.displayList();
	cout << "Reverse List: ";
	ll.reverseList();
	c = ll.displayList();
	cout << "Node Count: " << c << endl << endl;
	
	return 0;
}
