#include "CQueue.h"

// Default constructor
CQueue::CQueue()
{
    // Set all elements in queue (circular array) to 0
    for(int i = 0; i < MAX_SIZE; i++)
        data[i] = 0;
    count = 0;
}

// Copy constructor
CQueue::CQueue(const CQueue & cqueue)
{
    // Copy all elements from original queue
    for (int i = 0; i < MAX_SIZE; i++)
        data[i] = cqueue.data[i];
    count = cqueue.count;
}

// Destructor
CQueue::~CQueue()
{
    
}

// Method to insert letters into the array
void CQueue::Insert(const char letter)
{
    // Check for full queue
    if (IsFull())
    {
        cout << "I'm not hungry, I'm full\n";
        return;
    }
    // If data is not empty then move the end up one (automatically set to data[0] so for first one we don't ahve to move it)
    else if (!IsEmpty())
        end = (end + 1) % MAX_SIZE;
    // Set the end to the newly inserted letter
    data[end] = letter;
    count++;
}

// Method to remove letters from the array
void CQueue::Remove(char & letter)
{
    // Check for empty queue
    if (IsEmpty())
    {
        cout << "Nothing to remove dumbo\n";
        return;
    }
    // Set the pass by reference letter to front of stack
    letter = data[front];
    // Move front of stack to "remove" the letter that was infront of it
    front = (front + 1) % MAX_SIZE;
    // Decrease count by one
    count--;
}

// Method to check if queue is full
bool CQueue::IsFull()
{
    return (count == MAX_SIZE);
}
 
// Method to check if queue is empty
bool CQueue::IsEmpty()
{
    return (count == 0);
}

// Method to get length of queue
int CQueue::GetCount()
{
    return count;
}

// Method to get the front element of the queue
int CQueue::GetFront()
{
    return data[front];
}

// Method to print elements in the queue (written as bool incase size was too small for queue)
bool CQueue::Print()
{
    cout << "CQueue: ";
    // Possible tag values
    string tags = "abc#";
    // Int value I use to check if a value in the circular array is in there
    int in;
    // Walk through queue outputing front first then all the elements after it
    for (int i = 0; i < count; i++)
    {
        // Because of errors when the queue was too small, we first check that the data being output is valid, if not return an error
        in = tags.find(data[front + i % MAX_SIZE]);
        if(in == -1)
        {
           cout << "There was an invalid character in your array (you likely don't have a large enough MAX_SIZE)\n";
           return false;
        }
        cout << data[front + i % MAX_SIZE] << ' ';
    }
    cout << endl;
    return true;
}
