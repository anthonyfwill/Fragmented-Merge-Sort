#include <iostream>
using namespace std;

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int FindMin(int arr[], int n, int start) {
    int min = start;
    for (int i = min + 1; i < n; ++i) {
        if (arr[min] >= arr[i]) {
            min = i;
        }
    }
    cout << "\n      new start: " << start << " new min: " << min << "\n";
    cout << "      num start: " << arr[start] << " num min: " << arr[min] << "\n";
    swap(arr[start], arr[min]);
    cout << "      swap num start: " << arr[start] << " swap num min: " << arr[min] << "\n";
    return start;
}

// Merge two subarrays L and M into arr
void merge2(int arr[], int arr2[], int p, int q, int r, int n, int m) {
  cout << "Merge- m : " << m + m + n << " m = " << m << " n = " << n << '\n';
  for (int i = 0; i < n; ++i){
        cout << arr2[i] << " ";
    }
  cout << "\n\n";
  
  int n1 = m;
  int n2 = m;
  int n3 = n;

  int L[n1], M[n2];

  std::cout << "  **p = " << p << " q = " << q << " r = " << r <<"\n";
  std::cout << "    start n1 = " << p << " end n1 = " << n1+p << " start n2 = " << (r-m+1) << " n2 = " << n2+ (r-m+1) <<"\n";
  cout <<"    L: ";
  // Create L ← A[p..p+n1] and M ← A[r-m+1..r-m+1+n2]
  for (int i = 0; i < n1; i++){
    L[i] = arr[p + i];
    cout << L[i] << " ";
  }
  cout <<"\n    M: ";
  for (int j = 0; j < n2; j++){
    M[j] = arr[(r-m+1) + j];
    cout << M[j] << " ";
  }
    
  // Maintain current index of sub-arrays and main array
  int i, j, k, v;
  i = 0;
  j = 0;
  k = p;
  v = 0;
  
  /*std::cout << "\n        Before Merge: ";
  for (int i = 0; i < 32; ++i){
        cout << arr[i] << " ";
        //std::cout << "p = " << p << " r = " << r << " i = " << p+m << " (r-m) = " << r-m << "\n";
    }*/
  std::cout << "\n\n";
  
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2 && v < n3) {
    int vMin = FindMin(arr2, n3, v); 
    cout << "           iMin: " << L[i] << " jMin: " << M[j] << " vMin: " << arr2[vMin] <<"\n";
    if (L[i] <= M[j]) {
        if(arr2[vMin] <= L[i]){
            arr[k] = arr2[vMin];
            v++;
        } else {
            arr[k] = L[i];
            i++;
        }
    } else {
        if(arr2[vMin] <= M[j]){
            arr[k] = arr2[vMin];
            v++;
        }else{
            arr[k] = M[j];
            j++;
        }
    }
    k++;
  }

  // When we run out of elements in either Arr2 and M, Arr2 and L, L and M 
  // pick up the remaining elements and put in A[p..r]
  if (i == n1){
    while (v < n3 && j < n2) {
        int vMin = FindMin(arr2, n3, v); 
        if (arr2[vMin] <= M[j]) {
            arr[k] = arr2[vMin];
            v++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    
    while (v < n3) {
        int vMin = FindMin(arr2, n3, v); 
        arr[k] = arr2[vMin];
        v++;
        k++;
    }
      
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
  }
  
  if (j == n2){
    while (i < n1 && v < n3) {
        int vMin = FindMin(arr2, n3, v);
        if (arr2[vMin] <= L[i]) {
            arr[k] = arr2[vMin];
            v++;
        } else {
            arr[k] = L[i];
            i++;
        }
        k++;
    }
    
    while (v < n3) {
        int vMin = FindMin(arr2, n3, v);
        arr[k] = arr2[vMin];
        v++;
        k++;
    }
      
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  }
  
  if (v == n3){
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
      
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
  }
  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
  
  while (v < n3) {
    int vMin = FindMin(arr2, n3, v);
    arr[k] = arr2[vMin];
    v++;
    k++;
  }
  
  /*std::cout << "\n        After Merge: ";
  for (int i = 0; i < 32; ++i){
        cout << arr[i] << " ";
        //std::cout << "p = " << p << " r = " << r << " i = " << p+m << " (r-m) = " << r-m << "\n";
    }*/
  std::cout << "\n\n";
}

void SparseMerge(int arr[], int p, int r){
    float test = (r-p+1)/8.0;
    int m = (r-p+1)/33;
    
    if (test < 1 && test > 0 && r-p > 0){
       m = 1;
    }
    
    if (p > r || m < 1){
        return;
    }
    
    std::cout << "\n\ntest: " << test << " m = " << m << "\n";
    //std::cout << "p = " << p << " r = " << r << " i = " << p+m << " (r-m) = " << r-m << "\n";
    int c = m;
    int B[(r-p)+1];
    
    int n3 = (r-m) - (p+m) + 1;
    
    cout << p+m << " " << n3 << " " << c << "\n Unsorted List: ";
    
    for (int i = 0; i < n3; ++i){
        B[i] = arr[i + (p+m)];
        cout << B[i] << " ";
        //std::cout << "p = " << p << " r = " << r << " i = " << p+m << " (r-m) = " << r-m << "\n";
    }
    cout << "\n\n";
    std::cout << " p = " << p << " r = " << p+m-1 << "\n";
    std::cout << " p = " << r-m+1 << " r = " << r << "\n";
    SparseMerge(arr, p, p+m-1);
    SparseMerge(arr, r-m+1, r);

    //B is the unsorted List
    merge2(arr, B, p, p+m-1, r, n3, m);
}   

// Driver program
int main() {
  int arr[] = {3, 2, 1, 13, 10, 6, 5, 16, 3, 2, 1, 13, 10, 6, 5, 16, 9, 7, 11, 15, 4, 14, 12, 8, 9, 7, 11, 15, 4, 14, 12, 8};
  cout << "Unsorted array: \n";
  printArray(arr, size);  
  SparseMerge(arr, 0, 31);

  cout << "\n\nSorted array: \n";
  printArray(arr, size);
  return 0;
}
