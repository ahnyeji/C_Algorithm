#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> insertionSort(vector<T> inp){
    int outer = inp.size();
    for(int i = 1; i < outer; i++){
        int now = inp[i];
        int j = i;
        for(; j > 0 && inp[j - 1] > now; j--){
            inp[j] = inp[j - 1];
        }
        inp[j] = now;
    }
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

    toSort = insertionSort(toSort);
    for(int i = 0; i < N; i++){
        cout << toSort[i] << " ";
    }
}