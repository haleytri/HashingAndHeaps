#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "hashy.h"
using namespace std;

int main(int argc, char *argv[]){
    ArgumentManager am(argc,argv);
    string input = am.get("input");
    string output = am.get("output");

    //string input = "input3.txt";
    //string output = "output1.txt";
    ifstream ifs(input);
    ofstream ofs(output);
    string tbSize = "";
    string probe = "";
    string nums = "";
    hashi hash;

    getline(ifs, tbSize);
    tbSize.erase(remove(tbSize.begin(), tbSize.end(), '\n'), tbSize.end());
    tbSize.erase(remove(tbSize.begin(), tbSize.end(), '\r'), tbSize.end());
    int tableSize = (stoi(tbSize));
    

    getline(ifs, probe);
    probe.erase(remove(probe.begin(), probe.end(), '\n'), probe.end());
    probe.erase(remove(probe.begin(), probe.end(), '\r'), probe.end());
    
    int *arr = new int[tableSize];

    for(int i = 0; i < tableSize; i++){
        arr[i] = -1;
    }

    while(getline(ifs, nums, ',')){
    nums.erase(remove(nums.begin(), nums.end(), '\n'), nums.end());
    nums.erase(remove(nums.begin(), nums.end(), '\r'), nums.end());
        int num = stoi(nums);
        if(probe == "Linear probing"){
            hash.linearProbe(arr, num, tableSize);
        }
        else if(probe == "Quadratic probing"){
            hash.quadProbe(arr, num, tableSize);
        }
    }
    //print contents of hash
    string hashstr;
    for(int i = 0; i < tableSize; i++){
        if(arr[i] != -1){
            hashstr += to_string(arr[i]) + ',';
        }
    }
    hashstr.erase(hashstr.length()-1, 1); //erase last comma
    ofs << hashstr << endl;
    //cout << hashstr;
    //cout << endl;

    //now create a min heap
    int *minheap = new int[tableSize];
    for(int i = 0; i < tableSize; i++){
        minheap[i] = arr[i];
        //cout << minheap[i] << endl;
    }

    int siz = tableSize-1;
    for (int i = siz; i >= 0; i--)
    {
        hash.heapify(minheap, siz, i);
    }

    //cout << "now it is: " ;
    //for(int i = 0; i < tableSize; i++){
    //    cout << minheap[i] << " ";
    //}
    //cout << endl << endl;

    for(int i = tableSize/2-1; i>= 0; i--){
        hash.heapify(minheap, tableSize, i);
    }
    

    //cout << "now it is: " ;
    //for(int i = 0; i < tableSize; i++){
    //    cout << minheap[i] << " ";
    //}
    //cout << endl;
    string heap;
    for(int i = 0; i < tableSize; i++){
        if(minheap[i]!= -1){
        heap += to_string(minheap[i]) + ',';
        }
    }
    heap.erase(heap.length()-1, 1);
    //cout << "this is final: " << heap;
    ofs << heap;
}