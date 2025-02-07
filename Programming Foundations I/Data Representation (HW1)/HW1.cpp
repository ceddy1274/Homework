/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int
main ()
{
  // Cameron Eddy, 1/31/2024
  // welcome message
  cout << "Welcome to JG's trucking company\n" << endl;
  
  // set up variables for the box
  int box_height = 0;
  int box_width = 0;
  int box_length = 0;
  
  // set up variables for the truck
  int truck_height = 0;
  int truck_width = 0;
  int truck_length = 0;
  
  // get input from user for box
  
  cout << "Enter box height in inches: ";
  cin >> box_height;
  
  cout << "Enter box width in inches: ";
  cin >> box_width;
  
  cout << "Enter box length in inches: ";
  cin >> box_length;
  
  // get input from user for truck
  
  cout << "Enter truck height in feet: ";
  cin >> truck_height;
  
  cout << "Enter truck width in feet: ";
  cin >> truck_width;
  
  cout << "Enter truck length in feet: ";
  cin >> truck_length;

  // convert feet of truck into inches
  truck_height = truck_height*12;
  
  truck_width = truck_width*12;
  
  truck_length = truck_length*12;
  
  // find the max humber of boxes that can fit in each dimension
  int boxes_high = truck_height/box_height;
  
  int boxes_wide = truck_width/box_width;
  
  int boxes_long = truck_length/box_length;
  
  // find remaining dimensions of air in the truck
  int air_high = truck_height - boxes_high*box_height;
  
  int air_wide = truck_width - boxes_wide*box_width;
  
  int air_long = truck_length - boxes_long*box_length;
  
  // caculate box count
  int box_count = boxes_high*boxes_wide*boxes_long;
  
  // volume of boxes
  int vol_boxes = box_height*box_width*box_length;
  
  // volume of truck
  int vol_truck = truck_height*truck_width*truck_length;
  
  // output answer
  cout << "Box Count = " << box_count << endl;
  cout << "Empty Space Height = " << air_high << " inches" << endl;
  cout << "Empty Space Width = " << air_wide << " inches" << endl;
  cout << "Empty Space Length = " << air_long << " inches" << endl;
  cout << "Volume of Boxes = " << vol_boxes << " cubic inches" << endl;
  cout << "Truck Volume = " << vol_truck <<  " cubic inches" << endl;
  
  return 0;
}



