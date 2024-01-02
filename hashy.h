#ifndef HASHY_H
#define HASHY_H
#include <iostream>
using namespace std;

class hashi{
    public:
        hashi(){

        }
        void linearProbe(int table[], int x, int tbSize){
            int index = 0;
            for(int i = 0; i < tbSize; i++){
                index = ((x % tbSize)+ i) % tbSize;
                if(table[index]==-1){
                    table[index] = x;
                    break;
                }
            }
        }

        void quadProbe(int table[], int x, int tbSize){
            int index = 0;
            int c1 = 3;
            int c2 = 5;
            for(int i = 0; i < tbSize; i++){
                index = ((x % tbSize) + c1 * i + c2 * i * i) % tbSize;
                    if(table[index]==-1){
                    table[index] = x;
                    break;
                    }
            }
        }

        void heapify(int arr[], int size, int i){
            int min = i;
            int left = 2 * i + 1; //for i = 0, left = 1
            int right = 2 * i + 2;//for i = 0, right = 2
            //cout << "this is the min: " << arr[i] << endl;
            //if(left < size)
            //cout << "this is the left: " << arr[left] << endl;
            //if(right < size)
            //cout << "this is the right: " << arr[right] << endl;

            if(left < size && arr[left] < arr[min]){
                min = left;
            }
            if(right < size && arr[right] < arr[min]){
                min = right;
            }
            if(min != i){
                swap(arr[i],arr[min]);
                heapify(arr, size, min);
            }
        }
};

#endif