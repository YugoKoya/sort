#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    if (n > 1) {
    int i,j,pivot;
    pivot = A[0];
    for (i = j = 1; i < n; i++) {
        if (A[i] <= pivot) {
            int z = A[j];
            A[j] = A[i];
            A[i] = z;
            j++;
        }
    }
    int k = 1;
    while (k < j) {
        if (k < j-1) {
            A[k-1] = A[k];
            k = k+1;
        }
        else {
            A[k-1] = A[k];
            A[k] = pivot;
            k = k+1;
        }
    }
        quick_sort(A,j-1);
        quick_sort(A+j,n-j);
    }
    return ;
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
      A[i] = (long long int) A[i-1] * A[1] % N;
  }

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
