#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int maximum = root;
   int left = 2*root + 1;
   int right = 2*root + 2;

   //check left child node is greater than maximum node
   if(left<n && arr[left]>arr[maximum]){
        maximum = left;
    }
    //check right child node is greater than maximum node
    if(right<n && arr[right]>arr[maximum]){
        maximum = right;
    }
    //check any of the child nodes is greater than the current maximum node
    if(maximum != root){
        swap(arr[root], arr[maximum]);
        heapify(arr,n,maximum);
    }


}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int root = (n/2 - 1); root >= 0 && root <n; root--){
        swap(arr[0], arr[root]);
        heapify(arr,n,root);
   }
   // extracting elements from heap one by one
   for(int i=n-1; i>=0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
   }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
    //get the size of the array from the user
    cout<<"input the array length: ";
    int len;
    int num;
    cin>>len;
    cout<<endl;
   int heap_arr[len];

   //get the array and store heap_arr
    cout<<"input the array length: ";
    for(int i=0; i<len; i++){
        cin>>num;
        heap_arr[i] = num;
    }
    cout<<endl;

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
