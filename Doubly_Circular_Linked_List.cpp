///////////////////////////////////////////////////////////////////////////
//  DOUBLY CIRCULAR LINKED LIST
///////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;


class Doubly_CLL
{
	private :
		PNODE head, tail;
		
	public :
		Doubly_CLL();
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no, int iPos);		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);
		void Display();
		void DisplayRev();
		int Count();	
};

Doubly_CLL::Doubly_CLL()
{
	head = NULL;
	tail = NULL;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input : Integer
//  Output: void
//  Description : Inserts node in DOUBLY CIRCULAR LINKED LIST at 1st position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::InsertFirst(int no)
{
	PNODE newn = NULL;
			
	newn = new NODE;
			
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
			
	if(head == NULL && tail == NULL)
	{
		head = newn;          //3
		tail = newn;            //4
		newn -> next = head;  //1
		newn -> prev = tail;  //2
	}
	else
	{
		head -> prev = newn;   //4
		newn -> next = head;   //1
		newn -> prev = tail;   //2
		head = newn;           //3
		tail -> next = head;   //5
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input : Integer
//  Output: void
//  Description : Inserts node in DOUBLY CIRCULAR LINKED LIST at LAST position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::InsertLast(int no)
{
	PNODE newn = NULL;
			
	newn = new NODE;
			
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
			
	if(head == NULL && tail == NULL)
	{
		head = newn;          //3
		tail = newn;            //4
		newn -> next = head;  //1
		newn -> prev = tail;  //2
	}
	else
	{
		tail -> next = newn;      //1
		newn -> prev = tail;      //2
		newn -> next = head;      //3
		head -> prev = newn;      //4
		tail = newn;              //5
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input : Integer , Integer
//  Output: void
//  Description : Accepts first parameter as data in no and second as position in iPos
//				  Inserts node in DOUBLY CIRCULAR LINKED LIST at iPos position
//
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::InsertAtPos(int no, int iPos)
{	
	if((iPos < 0) ||(iPos > (Count() + 1)))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == (Count() + 1))
	{
		InsertLast(no);
	}
	else
	{
		PNODE temp = head, newn = NULL;
		
		newn = new NODE;
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		newn -> prev = temp;
		temp -> next = newn;
		newn -> next -> prev = newn;
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Output: void
//  Description : Deletes node in DOUBLY CIRCULAR LINKED LIST at 1st position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::DeleteFirst()
{
	if(head == NULL && tail == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head -> next;
		delete (head -> prev);
		tail -> next = head;
		head -> prev = tail;
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Output: void
//  Description : Deletes node in DOUBLY CIRCULAR LINKED LIST at last position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::DeleteLast()
{
	if(head == NULL && tail == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail -> prev;
		delete tail -> next;
		tail -> next = head;
		head -> prev = tail;
		
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input : Integer 
//  Output: void
//  Description : Accepts first parameter as position in iPos
//				  Deletes node in DOUBLY CIRCULAR LINKED LIST at iPos position
//
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::DeleteAtPos(int iPos)
{
	if((iPos < 0) ||(iPos > Count()))
	{
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == Count())
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = head;
		
		for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Output: void
//  Description : Displays all node in DOUBLY CIRCULAR LINKED LIST 
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::Display()
{
	PNODE temp = NULL;
			
	temp = head;
	cout<<"TAIL<=>";
	do
	{
		cout<<"| "<< temp -> data<<" |<=>";
		temp = temp -> next;
	}
	while(temp != tail -> next);
	cout<<"HEAD"<<endl;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayRev
//  Output: void
//  Description : Displays all node in DOUBLY CIRCULAR LINKED LIST in reveresed Manner
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Doubly_CLL::DisplayRev()
{
	PNODE temp = NULL;
			
	temp = tail;
	cout<<"TAIL<=>";
	do
	{
		cout<<"| "<< temp -> data<<" |<=>";
		temp = temp -> prev;
	}
	while(temp != tail);
	cout<<"HEAD"<<endl;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayRev
//  Output: Integer
//  Description : Counts no of nodes in DOUBLY CIRCULAR LINKED LIST
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

int Doubly_CLL::Count()
{
	PNODE temp = NULL;
			
	int iCnt = 0;
	
	temp = head;
	do
	{
		iCnt++;
		temp = temp -> next;
	}
	while(temp != tail -> next);
	
	return iCnt;
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : main
//  Output: Integer
//  Description : Can create and manipulate DOUBLY CIRCULAR LINKED LIST
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

int main()
{
	Doubly_CLL obj;
	
	int iRet = 0;
	
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertFirst(1);
	
	
	obj.InsertLast(151);
	obj.InsertLast(201);
	obj.InsertLast(251);
	
	obj.DeleteFirst();
	obj.DeleteLast();
	
	obj.InsertAtPos(0,1);
	obj.InsertAtPos(501,10);
	obj.InsertAtPos(75,5);
	
	obj.Display();
	iRet = obj.Count();
	
	cout<<"No of nodes are : "<<iRet<<endl;
	
	obj.DeleteAtPos(1);
	obj.DeleteAtPos(10);
	obj.DeleteAtPos(4);
	
	obj.Display();
	obj.DisplayRev();
	
	iRet = obj.Count();
	
	cout<<"No of nodes are : "<<iRet<<endl;
	
	return 0;
}