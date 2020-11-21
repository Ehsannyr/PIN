#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h> 
using namespace std;

int main() {
  int size;
  here:
  cout << "\ndefine your pin size : " << endl;
  
  cin >> size;
  int arr[size];
  if (size < 4 || size > 6){
  	cout << "your pin must be 4 to 6 digits";
  	goto here;
  }else{
  for (int i = 0 ; i < size ; i++){
    cout << "define your index " << i+1 << ":" <<endl;
    here2:
    cin >> arr[i];
    if (arr[i] >= 10 || arr[i] <0){
    	cout << "only between 0-9"<< endl;
		goto here2;
	}
  } 
  if (size == 0){
  	cout << "your array has 0 size" ;
  }else{
  cout << "here is your pin : " << "{";
    for (int i = 0 ; i < size - 1 ; i++){
    	cout << arr[i] << ",";
    }
    for (int i = size - 1 ; i < size ; i++){
    	cout << arr[i] ;
    }
  cout << "}" << endl;
  }
   here1:
  cout << "do you confirm your pin?" << endl;
  cout << "if yes push 1 , if No push 0" << endl;
  }
  int confirm;
  cin >> confirm;
  if (confirm == 1){
  	cout << "<<pin set>>" << endl;
  }
  else if (confirm == 0){
  	goto here;
  }else {
  	cout << "error" <<endl;
  	goto here1;
  }
   // Create and open a text file
  ofstream MyFile("pin.txt");

  // Write to the file
  MyFile << "your new password is : " ;
  for (int i = 0 ; i < size ; i++ ){
  MyFile <<  arr[i];
  }
  MyFile << "\ndate and time (GMT) : ";

  time_t rawtime;

  time (&rawtime);
  printf ("The current local time is: %s", ctime (&rawtime));
  MyFile << ctime (&rawtime) ;

  // Close the file
  MyFile.close();
  
  
 return 0; 
}
