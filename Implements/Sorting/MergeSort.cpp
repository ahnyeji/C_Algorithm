#include <iostream>
#include <vector>
using namespace std;

template<typename T>
// Combine
vector<T> merge(vector<T> left, vector<T> right){
    int llen = left.size(); int l = 0;
    int rlen = right.size(); int r = 0;
    
    vector<T> merged;

    while(l < llen && r < rlen){
        if(left[l] <= right[r]){
            merged.push_back(left[l]);
            l++;
        }
        else{
            merged.push_back(right[r]);
            r++;
        }
    }
    
    while(l < llen){
        merged.push_back(left[l++]);
    }
    while(r < rlen){
        merged.push_back(right[r++]);
    }
    return merged;
}
template<typename T>
vector<T> mergeSort(vector<T> inp){
    int len = inp.size();
    if(len < 2) return inp; // len 0 or 1 : cannot divide -> return
    
    // Divide
    int mid = len / 2;
    vector<T> left;
    vector<T> right;
    for(int i = 0; i < mid; i++){
        left.push_back(inp[i]);
    }
    for(int i = mid; i < len; i++){
        right.push_back(inp[i]);
    }
    
    // Conquer & Combine
    inp = merge(mergeSort(left), mergeSort(right));

    return inp;
}

int main(){
    int N;
    cin >> N;
    vector<int> toSort;
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        toSort.push_back(c);
    }

    toSort = mergeSort(toSort);
    for(int i = 0; i < N; i++){
        cout << toSort[i] << " ";
    }
}