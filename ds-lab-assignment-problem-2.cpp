#include<iostream>
#include<cstdlib>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<int, int> freq;

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        // int temp;
        // cin >> temp; //for testing--!
        // arr[i] = temp;
        arr[i] = 1+(rand()%100);
    }
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    int maxFreq = -99999;
    for(auto t : freq){
      if(maxFreq<t.second)maxFreq=t.second; //maximum frequency
    }
    if(maxFreq==1){
        cout<<"--All values are unique--"<<endl;
        return 0;
    }
    int arr2[maxFreq],p=0;
    for(auto t:freq){
        if(maxFreq == t.second){ //access the highest freq first
            arr2[p]=t.first;
            p++;
        }
    }
    for(int i=0;i<p;i++)cout << arr2[i] << ",";
    cout << "Occurred " << maxFreq << " times" << endl;
}

