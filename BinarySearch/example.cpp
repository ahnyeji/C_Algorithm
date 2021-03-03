/*
    TC #1
    input   :   8
    output  :   8 exist at index 1

    TC #2
    input   :   60
    output  :   60 not exist

*/
#include <iostream>

using namespace std;

int size = 10;
int numbers[10] = {3, 8, 9, 15, 24, 39, 52, 70, 99, 100};

int binarySearch(int toSearch)
{
    int lo = 0;
    int hi = size - 1;
    int mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(numbers[mid] == toSearch)
        {
            return mid; // exist at index mid
        }
        else if(numbers[mid] > toSearch) // left half
        {
            hi = mid - 1;
        }
        else // right half
        {
            lo = mid + 1;
        }
    }
    return -1; // not exist
}

int main()
{
    int toSearch;
    cin >> toSearch;
    int ans = binarySearch(toSearch);
    if(ans == -1)
    {
        cout << toSearch << " not exist\n";
    }
    else
    {
        cout << toSearch << " exist at index " << ans << "\n";
    }
}