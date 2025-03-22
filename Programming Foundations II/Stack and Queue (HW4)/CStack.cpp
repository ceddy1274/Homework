#include "CStack.h"

// Default constructor
CStack::CStack() 
{
    Head = NULL;
}

// Copy constructor
CStack::CStack(const CStack & cstack) 
{
    // Create first node
    CStackNode *copy = new CStackNode();
    Head = copy;
    // Walk list to copy nodes
    CStackNode *ptr = cstack.Head;
    while (ptr != NULL)
    {
        copy->Next = new CStackNode();
        copy = copy->Next;
        copy->bracket = ptr->bracket;
        copy->Next = NULL;
        ptr = ptr->Next;
    }
    
    // Tidy first node
    copy = Head;
    Head = copy->Next;
    delete copy;
}

// Destructor
CStack::~CStack() 
{
    // Delete nodes from stack
    while (Head != NULL)
    {
        CStackNode *Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
}

// Push method
void CStack::Push(char bracket) 
{
    // Make space for new data
    CStackNode *Temp = new CStackNode();
    // Insert node at head of linked list
    Temp->bracket = bracket;
    Temp->Next = Head;
    Head = Temp;
    size++;
}

// Pop method
char CStack::Pop() 
{
    // Return blank character if empty
    if(IsEmpty())
        return ' ';
    char bracket = Head->bracket;
    // Pop item from linked list
    CStackNode *Temp = Head;
    Head = Head->Next;
    delete Temp;
    size--;
    return bracket;
}

// Top method
char CStack::Top() 
{
    // Return blank character if empty
    if (IsEmpty()) 
        return ' ';
    char bracket = Head->bracket;
    // Return top value
    return bracket;
}

// IsFull method
bool CStack::IsFull() 
{
    // Always false because its a linked list
    return false;
}

// IsEmpty method
bool CStack::IsEmpty() 
{
    // If the head is NULL then our list is empty
    return (Head == NULL);
}

// Size mthod
int CStack::getSize() 
{
    // Return size of linked list to user
    return size;
}

// Print method
void CStack::Print() 
{
    cout << "CStack: ";
    // Set tmp to heaad and walk stack until the end
    CStackNode *Temp = Head;
    while (Temp != NULL)
    {
        cout << Temp->bracket << " ";
        Temp = Temp->Next;
    }
    cout << endl;
}
