/*
#include <string>
#include <iostream>

using namespace std;
*/

//Predicate function implementation if empty.
/*
bool somePredicate(string s)
{
	return s.empty();
}
*/
int countFalse(const string a[], int n);
bool allTrue(const string a[], int n);
int firstFalse(const string a[], int n);
int indexOfLeast(const string a[], int size);
bool includes(const string a1[], int n1, const string a2[], int n2);

/*
int main()
{
	string a[4] = { "1","2","3","4"};//, "2", "3"};
	string b[3] = { "1","2","3" };
	//cout << somePredicate("");
	cout << includes(a, 4, b, 3);
	//cout << indexOfLeast(a, 1);
	cin.ignore(1000,'\n');
}
*/

//Return false if the somePredicate function returns false for at least one of the array elements; return true otherwise.
//array of strings
//number of strings to examine in array.
bool allTrue(const string a[], int n)
{
	//base case.  Exit condition
	if (n == 0)
	{
		//cout << "n=0" << endl;
		return true;
	}
	else if (somePredicate(a[n - 1])) //if empty, exit
	{
		//cout << "string is: " << a[n - 1] << endl;
		return false;
	}
	else //not empty, so continue
	{
		//cout << "Elsestring is: " << a[n - 1] << endl;
		return allTrue(a, n - 1);
	}
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int size)
{
	//there are no elements in array, so return -1.
	if (size == 0)
		return -1;
	int temp = countFalse(a, size - 1); //recursion only happens on smaller cases.  Infinite recursion avoided.
	
										//now analyze cases for this 'n' case.  make sure that the entire 'n' case performs correctly.

	if (temp != -1) //in this case, temp is storing amount of false cases.  So, check the 'n' case, and deal with that case properly.
	{
		if (somePredicate(a[size - 1])==false) //if 'n'th case is true, then add one to counter.
			return temp + 1;
		else //'n'th case isn't true, so return the 'n-1' case.
			return temp;
	}
	else //function hit the -1 case, so that means that size is zero, so in the zeroth case, the count of falses is of course 0.  This is how popping starts.
		return 0;
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int size)
{
	//1.  Determine for size 'n'
	//2.  If array is empty, the answer is obvious.  You didn't find such element, so return -1.  | End Array Base case
	if (size <= 0)
		return -1; //pops off here, so doesn't continue.
	//3.  If the array is not empty, recursively call function for 'n-1' case.	
	int temp = firstFalse(a, size - 1); //assume recursive call returns correct answer
	//4.  Asume recursive call returns the correct answer of size n-1.
	if (temp != -1)//if it returned something other than -1, then it was right, so you return same thing.
		return temp;
	else //If recursive call returned -1, it must mean that for the array of 'n-1', the predicate function returned true for all elements. (or it was empty).  Answer was obvious, call predicate function for element array 'n-1'.
	{
		if (somePredicate(a[size - 1]) == false)//if calling predicate function for element 'n-1' is false, then the last ement in array of size 'n' is the first such element that returned false.  So, return n-1 as the position.
			return size - 1;
		else //otherwise, the predicate function has yet to return false.  So, you return a -1 because you haven't found a false.
			return -1;
	}
}

// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the array has no elements to examine,
// return -1.
int indexOfLeast(const string a[], int size)
{
	//there are no elements to examine, so return -1.
	if (size <= 0)
		return -1;
	//there is only one element to examine, so return this position, which is simply 0th element (1st element).
	if (size == 1)
		return 0;

	int temp = indexOfLeast(a, size - 1); //Size will always hit 1 or zero.  Infinite recursion avoided.

	if (temp != -1) //that means that 'n-1' case found the index of the least string value.
	{
		//the index of the least is either that temp or the n case.
		if (a[size - 1] < a[temp])
		{
			return size - 1;
		}
		else if (a[size - 1] == a[temp])
			return temp;
		else
			return temp;
	}
	else //indexofleast is -1, so 
	{
		return -1;
	}



	////single element base case
	////else if (size == 1)
	//	//return size;
	////more than two elements.
	//else if (size == 1)
	//{

	//}
	//else if (a[0] <= a[1])//if current element is smaller than next one
	//{
	//	cout << "elem 0 is: " << a[0] << endl;
	//	cout << "elem 1 is: " << a[1] << endl;
	//	cin.ignore(1000, '\n');
	//	return 0;
	//}
	//else
	//	return 1+indexOfLeast(a+1,size-1);  // This is incorrect.
}

/*
If all n2 elements of a2 appear in the n1 element array a1, in
 the same order (though not necessarily consecutively), then
 return true; otherwise (i.e., if the array a1 does not include
 a2 as a not-necessarily-contiguous subsequence), return false.
 (Of course, if a2 is empty (i.e., n2 is 0), return true.)
 For example, if a1 is the 7 element array
    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
 then the function should return true if a2 is
    "kyle" "kenny" "butters"
 or
    "kyle" "cartman" "cartman"
 and it should return false if a2 is
    "kyle" "butters" "kenny"
 or
    "stan" "kenny" "kenny"
*/
bool includes(const string a1[], int size1, const string a2[], int size2)
{
	if (size1 <= 0)
		return false;
	if (size2 <= 0)
		return true;

	if (a1[size1 - 1] == a2[size2 - 1]) //if last elements match
		return includes(a1, size1 - 1, a2, size2 - 1);
	else
		return includes(a1, size1 - 1, a2, size2 - 1);
}