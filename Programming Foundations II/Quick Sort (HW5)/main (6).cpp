/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void create_random_data(int data[], int count, int range)
{
   //Put specified count of random numbers into data array
   for (int index = 0; index < count; index++)
      data[index] = rand() % range;
}

void partition(int data[], int low, int high, int &mid)
{
   //Select pivot value
   int pivot = data[high];
   int left = low;
   int right = high;

   //Partition array into two parts
   while (left < right)
   {
      //Scan left to right
      while ((left < right) && (data[left] < pivot)) 
         left++;

      //Scan right to left
      while ((left < right) && (data[right] >= pivot)) 
         right--;

      //Swap data values
      int temp = data[left];
      data[left] = data[right];
      data[right] = temp;
   }

   //Swap pivot to mid
   mid = left;
   data[high] = data[mid];
   data[mid] = pivot;
}

void quick_sort(int data[], int low, int high)
{
   //Check terminating condition
   if (low < high)
   {
      
      //Partition data into two parts
      int mid = 0;
      partition(data, low, high, mid);

      //Recursive calls to sort array
      quick_sort(data, low, mid - 1);
      quick_sort(data, mid + 1, high);
   }
}

void dual_quick_sort(int data[], int low, int high)
{
    //Base case
    if(low >= high)
        return;
        
    //Intalize variables used 
    int tmp;
    int lt = low + 1;
    int gt = high - 1;
    int i = lt;
    
    //Switch indexes
    if (data[low] > data[high])
    {
        tmp = data[low];
        data[low] = data[high];
        data[high] = tmp;
    }
    
    // Partitioning
    while(i <= gt)
    {
        //Making lower section
        if (data[i] < data[low])
        {
            tmp = data[i];
            data[i] = data[lt];
            data[lt] = tmp;
            lt++;
            i++;
        }
        //Making higher section
        else if(data[i] > data[high])
        {
            tmp = data[i];
            data[i] = data[gt];
            data[gt] = tmp;
            gt--;
        }
        //Middle section
        else
            i++;
    }
    
    //Switch low with lt-1
    tmp = data[lt-1];
    data[lt-1] = data[low];
    data[low] = tmp;
    
    //Switch hi with gt+1
    tmp = data[gt+1];
    data[gt+1] = data[high];
    data[high] = tmp;
    
    //Recursive calls
    if(gt >= lt)
    {
        dual_quick_sort(data, low, lt-1);
        dual_quick_sort(data, lt, gt);
        dual_quick_sort(data, gt+1, high);
    }
}

int main()
{
    //DONE: Dual-Pivot Quicksort
    //DONE: User Interface
    //DONE: Peformance Comparison
    
    //Intalize variables
    int sort_input;
    int range;
    int count;
    ofstream outFile;
    
    //User Interface with do while loops for correct input error checking
    cout << "Hello, would you like to test the runtime for dual-pivot quicksort or regular quicksort?\n";
    cout << "1) Regular Quicksort\n";
    cout << "2) Dual-Pivot Quicksort\n";
    do {
        cout << "Type 1 or 2: ";
        cin >> sort_input;
    } while(sort_input != 1 && sort_input != 2);
    do {
        cout << "What range do you want for your data (ex: 100 would be numbers between 1-100): ";
        cin >> range;
    } while(range <= 0);
    do {
        cout << "How many values do you want to sort?: ";
        cin >> count;
    } while(count <= 0);
    
    //Intalize data array to size specified by user and create random data for the array
    int data[count];
    create_random_data(data, count, range);
    //Unsorted array into file
    outFile.open("unsort.txt");
    for(int i = 0; i < count; i++)
        outFile << data[i] << endl;
    outFile.close();
    //Start clock to track runtimes
    clock_t time1=clock();
    
    cout << endl;
    //If user choose 1 for input type do a regular quick sort
    if(sort_input == 1)
        quick_sort(data, 0, count-1);
    //If user choose 2 for input type do a dual-pivot quick sort_input
    else
        dual_quick_sort(data, 0, count-1);
    
    //Get runtime and print it
    clock_t time2=clock();
    double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
    cout << "Run time: " << run_time << " seconds\n";
    //Sorted array into another file
    outFile.open("sort.txt");
    for(int i = 0; i < count; i++)
        outFile << data[i] << endl;
    outFile.close();
    cout << "IM DONE";
    return 0;
}