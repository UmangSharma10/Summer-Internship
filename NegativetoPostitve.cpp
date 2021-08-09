#include <iostream>
#include <algorithm>
using namespace std;

int allNegandPos(int arr[], int i, int j){
    while(i<=j){
        if(arr[i] <0 && arr[i] < 0){
            i++;
            
        }
        else if(arr[i] > 0 && arr[j] < 0) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if(arr[i] > 0 && arr[j] > 0){
            j--;
        }
        else{
            i++;
            j--;
        }
    }
}

void display(int arr[], int right){
   
  
  for (int i=0;i<=right;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}



int main() {
	int arr[] = {-12, 11, -13, -5,
               6, -7, 5, -3, 11};
  int arr_size = sizeof(arr) /
                sizeof(arr[0]);
   
  // Function Call
  allNegandPos(arr,0,arr_size-1);
  display(arr,arr_size-1);
  return 0;
}
