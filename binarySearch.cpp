//Binary Search algorithm: 
//Search for a word in an array of sorted strings

#include <iostream>
using namespace std;

int binarySearch(string* dictionary, int size, string target);
int binarySearch_recursive(string* dictionary, int size, string target);
int binarySearch_recursive(string* dictionary, int start, int end, string target);

int main()
{
    string dictionary[] = {"good", "life", "success", 
        "wonderful", "work"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
                //numbytes/numelement = length of array
    string target = "hello";
    int index = binarySearch_recursive(dictionary, size, target);
    cout << "index for " << target << " is " << index << endl;

    target = "good";
    index = binarySearch_recursive(dictionary, size, target);
    cout << "index for " << target << " is " << index << endl;

    return 0;
}

int binarySearch_recursive(string* dictionary, int size, 
    string target)
{
    return binarySearch_recursive(dictionary, 0, size-1, target);
}

//search for target in dictionary[start, end],
//where start and end are indices of the subarray where
//target is searched.
//Courtesey Syeda Nameera Tahseen, Janna, Conner,Sarika T Islam
int binarySearch_recursive(string* dictionary,
    int start, int end, string target)
{
    if (end < start) //after updating multiple times in else, the end will be > start. this is when the recursion of searching for string should end and conclude that no string found in the array
       return -1; //target is not found

    int mid = (start + end) / 2; //integer division

    if (dictionary[mid] == target)
       return mid; //goal is to acheieve this after calling functions recursively below at else.
    else
    {
        if (dictionary[mid] < target) //if index od target is more than mid index
                start = mid +1; // and then start the loop again to see if the target = mid, cont loop until target == mid.
        else  //dictionary[mid] > target
                end = mid -1; //and focus on lower half to find the target. answer is if target == mid.
        return binarySearch_recursive(dictionary, start, end, target); //this is to recursively call the functions in the case we don't find the target index.
    }
}
