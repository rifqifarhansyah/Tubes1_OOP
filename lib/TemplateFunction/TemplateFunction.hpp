#ifndef TEMPLATEFUNCTION_HPP
#define TEMPLATEFUNCTION_HPP
#include <vector>
#include <map>
using namespace std;

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

template <class T, class P>
T getMaxMapKey(map<T,P>& map){
    T maxID = map.begin()->first;
    for (auto it = map.begin();it != map.end();it++){
        if (it->second > map[maxID]){
            maxID = it->first;
        }
    }
    return maxID;
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
#endif