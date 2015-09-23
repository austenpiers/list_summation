#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int LSumN3(int[]);
int LSumN2(int[]);
int* LSumNLgN(int[], int, int);
int LSumN(int[]);
void test(int*);

int main(int argc, char *argv[])
{
  triple int f = {1,2,3};

  int k[] = {3,-5,4};//{5,-7,3,1,-9,6,-3,7,5,-7,2};
  int UsrInpt, result, *redicResult;
  cout << "Hello. the list of numbers are: 5,-7,3,1,-9,6,-3,7,5,-7,2" << endl<< "Which Complexity would you like to test?" << endl;
  cout << "(1) O(n^3)" << endl << "(2) O(n^2)" << endl << "(3) O(nlogn)" << endl << "(4) O(n)" << endl;
  cin >> UsrInpt;
    switch (UsrInpt){
    case 1:
      cout << "You have chosen complexity O(n^3)" << endl;
      result = LSumN3(k);
      cout << result << endl;
      break;
    case 2:
      cout << "You have chosen complexity O(n^2)" << endl;
      result = LSumN2(k);
      cout << result << endl;
      break;
    case 3:
      cout << "You have chosen complexity O(nlogn)" << endl;
      redicResult = LSumNLgN(k, 3, 0);
      cout << endl << redicResult[0] << " From indices: " << redicResult[1] << " to " << redicResult[2] << endl;
      break;
    case 4:
      cout << "You have chosen complexity O(n)" << endl;
      result = LSumN(k);
      cout << result << endl;
      break;
    default:
      cout << "Sorry, not a valid input.  Goodbye." << endl;
      return (0);
    }
}

int LSumN3(int a[])
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
 cout << "From indices: " << indices[0] << " to " << indices[1] << endl << " MaxSum = ";
 return maxSum;
}

int LSumN2(int a[])
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
 cout << "From indices: " << indices[0] << " to " << indices[1] << endl << " MaxSum = ";
 return maxSum;
}


int* LSumNLgN(int a[], int ln, int begn)
{
  int sum=0, arrt[3] = {0,0,0}, i;

  if(ln ==1)
    {
      if(0 > a[begn])
	  return arrt;
      arrt[0] = a[begn];
      return arrt;
    }

  if(ln == 2)
    {
      int endn = begn + 1;
      if(a[begn]<0 && a[endn]<0)
	return arrt;

      arrt[1] = begn; arrt[2] = endn;
      sum = a[begn] + a[endn];
      if(sum > a[begn] && sum > a[endn])
	{
	  arrt[0] = sum;
	  return arrt;
	}
      else if(a[begn]>a[endn])
	{
	  arrt[0] = a[begn]; arrt[2] = begn;
	  return arrt;
	}
      arrt[0] = a[endn]; arrt[1] = endn;
      return arrt;
    }

  //recusive calls, splitting list into two, and setting new length
  int *TL, *TR, newl = ln/2;
  TL = LSumNLgN(a, newl, begn);
  if(ln%2 == 0)
    TR = LSumNLgN(a,newl,newl);
  else
    TR = LSumNLgN(a,newl+1,newl);
  //if the end of the left sum is one away from the maxsum of the right, return the total sum
  if(TL[2]-TR[1] ==1)
    { 
      arrt[0] = TL[0]+TR[0];
      arrt[1] = TR[1];
      arrt[2] = TL[2] + ln -1;
      return arrt;
    }


  //different calculator
  int difference= TR[0] + TL[0], endDifference = ln - TR[1];
  for(i = TR[2]; i <= endDifference; i++)
    difference+=a[i];

  //Finding new maximum sum with total sum
  if(difference > TR[0] && difference > TL[0])
    {
      arrt[0] = TL[0] +TR[0];
      arrt[1] = TR[1];
      arrt[2] = TL[2];
      return arrt;
    }

  //max sum is right sum
  else if(TR[0] > TL[0])
    {    
      arrt[0] = TR[0];
      arrt[1] = TR[1];
      arrt[2] = TR[2];
      return arrt;
    }

  //max sum is lest sum
  arrt[0] = TL[0];
  arrt[1] = ln/2 + TL[1];
  arrt[2] = TL[2] + ln - 1;
  return arrt;
}


int LSumN(int a[])
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
 cout << "From indices: " << indices[0] << " to " << indices[1] << endl << " MaxSum = ";
 return maxSum;
}
/*
void test(int* arry)
{
  cout << "Current Max_Sum: " << arry[0] << " From indices: " << arry[1] << " to " << arry[2] << endl;
}
*/
