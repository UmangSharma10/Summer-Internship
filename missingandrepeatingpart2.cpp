#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int arr[] = {1,7,6,8,8,4,2};
    int n = 7;
    
    unordered_map<int, bool> numbermap;
    
    for(int i : arr){
        if(numbermap.find(i)==numbermap.end()){
            numbermap[i] == true;
        }
        
        else
        {
            cout << "Repeating = " << i;
        }
    }
    cout << endl;
      
    for(int i = 1; i <= n; i++)
    {
        if (numberMap.find(i) == 
            numberMap.end()) 
        {
            cout << "Missing = " << i;
        }
    }
    return 0;
    }
    
    
}
