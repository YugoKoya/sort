#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/

int mid_n(int A[], int n, int k){
    int j, pivot;
    int l = 0;
    int r = n;
    int c = 0;
    pivot = A[0];
    for(j = 1; j < r; j++){
        if(A[j] < pivot){
            int z = A[l+1];
            A[l+1] = A[j];
            A[j] = z;
            l = l+1;
        }
        else if(A[j] > pivot){
            int y = A[r-1];
            A[r-1] = A[j];
            A[j] = y;
            r = r-1;
            j = j-1;
        }
        else {
            c = c+1;
        }
    }
    if (l < k+1 && k < r) return pivot;
    else if (r <= k) return quick_select(A+r, n-r, k-r);
    else return quick_select(A+1, l, k);
}

int quick_select(int A[], int n, int k){
  int i, j, pivot;

// 先頭の要素をピボットとする
  pivot = A[0];
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      int z = A[j];
      A[j] = A[i];
      A[i] = z;
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
