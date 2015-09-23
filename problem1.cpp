#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int* LSumN3(int[]);
int* LSumN2(int[]);
int* LSumNLgN(int[], int, int);
int* LSumN(int[]);

int main(int argc, char *argv[])
{
  int k[] = {5,-7,3,1,-9,6,-3,7,5,-7,2};
  int lngthK = 11;
  int UsrInpt, *result;

  cout << endl << "Hello. the list of numbers are: ";
  for(int i = 0; i<lngthK; i++)
    cout << k[i] << ",";
  cout << endl << "Which Complexity would you like to test?" << endl;
  cout << "(1) O(n^3)" << endl << "(2) O(n^2)" << endl << "(3) O(nlogn)" << endl << "(4) O(n)" << endl;
  cin >> UsrInpt;

    switch (UsrInpt){

    case 1:
      cout << endl << "You have chosen complexity O(n^3)" << endl << endl;
      result = LSumN3(k);
      cout << "From indices: " << result[1] << " to " << result[2] << endl << " MaxSum = " << result[0] << endl << endl;
      break;

    case 2:
      cout << endl << "You have chosen complexity O(n^2)" << endl << endl;
      result = LSumN2(k);
      cout << "From indices: " << result[1] << " to " << result[2] << endl << " MaxSum = " << result[0] << endl << endl;
      break;

    case 3:
      cout << endl << "You have chosen complexity O(nlogn)" << endl << endl;
      result = LSumNLgN(k, 11, 0);
      cout << "From indices: " << result[1] << " to " << result[2] << endl << " MaxSum = " << result[0] << endl << endl;
      break;

    case 4:
      cout << endl << "You have chosen complexity O(n)" << endl << endl;
      result = LSumN(k);
      cout << "From indices: " << result[1] << " to " << result[2] << endl << " MaxSum = " << result[0] << endl << endl;
      break;

    default:
      cout << "Sorry, not a valid input.  Goodbye." << endl;
      return (0);
    }
}

int* LSumN3(int a[])
{
 int maxSum = 0;
 int indices[] = {0,0};
 for( int i = 0; i < 11; i++ ) {
   for( int j = i; j < 11; j++ ) 
     { 
       int thisSum = 0; 
       for( int k = i; k <= j; k++ )
	   thisSum += a[k];
       if(thisSum > maxSum)
	 {
	   maxSum = thisSum;
	   indices[0] = i;
	   indices[1] = j;
	 }
     }
 } 
 int solution[3] = {maxSum, indices[0], indices[1]};
 return solution;
}

int* LSumN2(int a[])
{
 int maxSum = 0; 
 int indices[] = {0,0};
 
 for(int i=0; i<11; i++) {
   int thisSum = 0; 
   for(int j =i; j<11;j++ ) 
     { 
       thisSum += a[j]; 
       if(thisSum > maxSum ) 
	 {
	   maxSum = thisSum; 
	   indices[0] = i;
	   indices[1] = j;
	 }
     }
 } 
 int solution[3] = {maxSum, indices[0], indices[1]};
 return solution;
}


int* LSumNLgN(int a[], int length, int begin)
{
  int Maxim[3] = {0,begin, begin};

  //base case
  if(length ==1) { if(a[begin] > 0) Maxim[0] = a[begin]; return Maxim;}

  //prep recursion
  int NewLength = length/2, *TMPside, LeftMax[3], RightMax[3];

  //recursive call
  TMPside = LSumNLgN(a,NewLength,begin);
  LeftMax[0] = TMPside[0]; LeftMax[1] = TMPside[1]; LeftMax[2] = TMPside[2];
  if((length%2) == 1)
    TMPside = LSumNLgN(a, NewLength+1, NewLength+begin);
  else
    TMPside = LSumNLgN(a, NewLength, NewLength+begin);
  RightMax[0] = TMPside[0]; RightMax[1] = TMPside[1]; RightMax[2] = TMPside[2];

  //Finding sum between beginning indice of LeftMax and ending indice of RightMax
  int i;
  Maxim[0] = LeftMax[0]+RightMax[0];
  for(i = (LeftMax[2])+1; i != RightMax[1]; i++)
      Maxim[0] += a[i];

  //setting temporary Maxim 
  Maxim[2] = RightMax[2];

  //returning actual max
  if(Maxim[0] > LeftMax[0] && Maxim[0] > RightMax[0])
     return Maxim;
  else if(LeftMax[0] > RightMax[0])
     return LeftMax;
  return RightMax;
}


int* LSumN(int a[])
{
 int maxSum = 0, thisSum = 0, sz = 11;
 int indices[] = {0,0};

 for(int j=0; j<sz; j++) 
 { 
   thisSum += a[j]; 
 
   if (thisSum>maxSum)
     {
       maxSum = thisSum;
       indices[1] = j;
     } 
   else if (thisSum<0)
     {
       thisSum = 0;
       indices[0] = j+1;
     }
 }
 int solution[3] = {maxSum, indices[0], indices[1]};
 return solution;
}
