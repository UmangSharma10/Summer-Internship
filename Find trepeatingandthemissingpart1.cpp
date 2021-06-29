#include <iostream>
using namespace std;

void PrinttwoElement(int arr[], int size){
    
    cout << " The repeating element is ";
    for(int i=0; i <size; i++){
        if(arr[abs(arr[i])- 1]> 0)
        arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
        cout<<abs(arr[i])<<"\n";
    }
    
    cout<<"and missing element is ";
    for(int i = 0; i < size; i++){
        if(arr[i] > 0)
        cout<<(i + 1);
    }
}

int main() {
    int arr[] = {7,3,4,5,5,6,2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    PrinttwoElement(arr, n);
	return 0;
}
