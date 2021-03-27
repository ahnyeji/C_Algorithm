#include <iostream>

using namespace std;

int arr[10] = {2, 3, 5, 8, 10, 11, 16, 16, 20, 25};
int len = 10;

int lowerBound(int toFind)
{
    int lo = 0;
    int hi = len - 1;
    int mid;
    while(lo < hi)
    {
        mid = (lo + hi) / 2;
        if(arr[mid] < toFind)
        {
            lo = mid + 1;
        }
        else // lower bound : find greater or equal toFind -> include equal
        {
            hi = mid;
        }
    }
    return hi;
}

int main(){
    int idx = lowerBound(16);
    cout << "lower bound is at arr[" << idx << "] : " << arr[idx] << "\n";
}