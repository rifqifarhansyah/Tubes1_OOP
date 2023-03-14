#include "TemplateFunction.hpp"
#include <random>


template <class T>
T& getMaxArr(T arr[], int n){
    T& min = arr[0];
    for (int i = 1;i < n;i++){
        if (arr[i] > min){
            min = arr[i];
        }
    }
    return min;
}

template <class T>
void ShuffleArr(T arr[], int n){
    for (int i = 0;i < n-1;i++){
        int randIdx = rand()%(n-i)+i;
        swap(arr[i],arr[randIdx]);
    }
}

template <class T>
void ShuffleVec(vector<T>& vec){
    for (int i = 0;i < vec.size()-1;i++){
        int randIdx = rand()%(vec.size()-i)+i;
        swap(vec[i],vec[randIdx]);
    }
}
