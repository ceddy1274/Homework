#include <iostream>

using namespace std;

class CStackNode
{
    public:
        char bracket;
        CStackNode *Next;
};

class CStack
{
    public:
        //constructors
        CStack();
        CStack(const CStack & cstack);
        ~CStack();
        
        //methods
        void Push(char bracket);
        char Pop();
        char Top();
        bool IsFull();
        bool IsEmpty();
        int getSize();
        void Print();
    
    private:
        CStackNode *Head;
        int size;
};