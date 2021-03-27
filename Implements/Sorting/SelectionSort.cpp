#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> selectionSort(vector<T> inp){
    int outer = inp.size();
    for(int i = 0; i < outer; i++){
        int minI = i;
        for(int j = i + 1; j < outer; j++){
            if(inp[minI] > inp[j]){
                minI = j;
            }
        }
        T temp = inp[i];
        inp[i] = inp[minI];
        inp[minI] = temp;
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

    toSort = selectionSort(toSort);
    for(int i = 0; i < N; i++){
        cout << toSort[i] << " ";
    }
}