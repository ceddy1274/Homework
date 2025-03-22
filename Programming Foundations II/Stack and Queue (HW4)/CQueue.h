#include <iostream>

using namespace std;

class CQueue
{
    public:
        //constructors
        CQueue();
        CQueue(const CQueue & cqueue);
        ~CQueue();
        
        //methods
        void Insert(const char letter);
        void Remove(char & letter);
        bool IsFull();
        bool IsEmpty();
        int GetCount();
        int GetFront();
        bool Print();
    
    private:
        static const int MAX_SIZE = 500;
        char data[MAX_SIZE];
        int end = 0;
        int front = 0;
        int count = 0;
};