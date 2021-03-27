#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> bubbleSort(vector<T> inp){
    int outer = inp.size();
    for(int i = 0; i < outer; i++){
        int inner = outer - i;
        for(int j = 1; j < inner; j++){
            if(inp[j - 1] > inp[j]){
                T temp = inp[j];
                inp[j] = inp[j- 1];
                inp[j - 1] = temp;
            }
        }
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

    toSort = bubbleSort(toSort);
    for(int i = 0; i < N; i++){
        cout << toSort[i] << " ";
    }
}