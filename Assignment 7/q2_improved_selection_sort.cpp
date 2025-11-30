#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n){
    int left = 0, right = n-1;
    while(left < right){
        int minIdx = left, maxIdx = left;
        for(int i=left;i<=right;i++){
            if(arr[i] < arr[minIdx]) minIdx = i;
            if(arr[i] > arr[maxIdx]) maxIdx = i;
        }
        swap(arr[left], arr[minIdx]);
        // if max was at left, its index moved to minIdx
        if(maxIdx == left) maxIdx = minIdx;
        swap(arr[right], arr[maxIdx]);
        left++; right--;
    }
}

int main(){
    int arr[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original: "; for(int x:arr) cout<<x<<" "; cout<<"\n";
    improvedSelectionSort(arr,n);
    cout<<"After Improved Selection Sort: "; for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"\n";
    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
}
