#include <iostream>
using namespace std;

struct node   //node structure 
{
	int data;
	struct node* next;    //next node
	struct node* prev;		//previous node
};

class LinkedList   //class linked list..
{
private:
	node* start;   //starting node..
	node* end;		//ending node..

public:
	void insertEnd(int y);   //inserting elements... 
	void printList();		//printing elements....
	node* getStart();		//get the starting node....
	void listValue();		//assign NULL to start when list is empty...
	int checkListDublicates(int t);  //checking dublicate values ...
	static void commonValues(node* list1, node* list2, LinkedList list3, int& co);   //checking common values...

};

void LinkedList::listValue()  //set start and end pointers to NULL
{
	start = NULL;
	end = NULL;
}

void LinkedList::insertEnd(int y)  //insert a node at the end..
{
	struct node* newNode; //define a new node...
	newNode = new node; //allocate memory...
	newNode->data = y;
	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		end = newNode;
	}

	else
	{
		newNode->prev = end;
		end->next = newNode;
		newNode->next = NULL;
		end = newNode;

	}

}

void LinkedList::printList()   //print the current list...
{
	node* temp;
	temp = start;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int LinkedList::checkListDublicates(int t)   //checking dublicates fuction....
{
	node* temp;
	node* compare;  //comparing node..
	compare = start;
	temp = start->next;
	while (compare != end)
	{
		while (temp != NULL)
		{
			if (compare->data == temp->data)
			{
				t = 1;
				return t;
			}
			temp = temp->next;
		}
		compare = compare->next;
		temp = compare->next;
	}

}

node* LinkedList::getStart()  //get the starting pointer...
{
	return start;
}

void LinkedList::commonValues(node* list1, node* list2, LinkedList list3, int& co)  //checking common values fuction...
{
	if (list1 != NULL && list2 != NULL)  //if 2 lists not NULL....
	{
		node* temp;
		node* compare;
		compare = list1;  //in here get a list1 value and compare with list2 values..then if similar value found then it store to list3
		temp = list2;
		while (compare != NULL)
		{
			while (temp != NULL)
			{
				if (compare->data == temp->data)
				{
					list3.insertEnd(compare->data);  //store value to list3
					co = 1;
				}
				temp = temp->next;
			}
			compare = compare->next;
			temp = list2;
		}
		cout << "Common Values : ";
		list3.printList();  //print common values....

	}
	else //cannot found similar values when one or both list are empty....
	{
		cout << "One or both linked list(s) Empty";
	}
}


int main()
{
	LinkedList list1, list2, list3;  //linkedlist 3 lists objects...
	list1.listValue();   //assign as empty list
	list2.listValue();	 //assign as empty list
	list3.listValue();	 //assign as empty list
	int listData1, NoOfNodes1, listData2, NoOfNodes2;
	cout << "Enter Number of Nodes in List 1 : ";
	cin >> NoOfNodes1;
	if (NoOfNodes1 == 0)  //if enter a empty list(0 elements)...
	{
		cout << "Error!!!!Linked List 1 is Empty!!!" << endl;
		return 0;
	}
	cout << "Enter List 1 Data : " << endl;
	for (int i = 0; i < NoOfNodes1; i++)  //input list 1 data..
	{
		cin >> listData1;
		list1.insertEnd(listData1);
	}

	cout << "Enter Number of Nodes in List 2 : ";
	cin >> NoOfNodes2;
	if (NoOfNodes2 == 0)    //if enter a empty list(0 elements)...
	{
		cout << "Error!!!!Linked List 2 is Empty!!!" << endl;
		return 0;
	}
	cout << "Enter List 2 Data : " << endl;
	for (int i = 0; i < NoOfNodes2; i++)  //input list 2 data..
	{
		cin >> listData2;
		list2.insertEnd(listData2);
	}

	if (list1.checkListDublicates(0) == 1)   //if dublicate values found in list 1...
	{
		cout << "Error!!! Dublicate value in the list 1" << endl;
			if (list2.checkListDublicates(0) == 1)		 //if dublicate values found in list 2...
			{
				cout << "Error!!! Dublicate value in the list 2" << endl;
				return 0;
			}
		
		return 0;
	}
	if (list2.checkListDublicates(0) == 1)		 //if dublicate values found in list 2...
	{
		cout << "Error!!! Dublicate value in the list 2" << endl;
		return 0;
	}

	//////////////////////////common values....

	int co = 0;
	LinkedList::commonValues(list1.getStart(), list2.getStart(), list3, co);  //fuction call for get common values....

	if (co != 1)  //if common values not found....
	{
		cout << "There are No Common Values!!!!" << endl;

	}


}
