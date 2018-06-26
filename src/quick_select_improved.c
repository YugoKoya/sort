#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
    if (n > 1) {
    int i, pivot;
    int l = 0;
    int r = n;
    int c = 0;

// 先頭の要素をピボットとする
    pivot = A[0];
    for(i = 1; i < n; i++){
        if(A[i] < pivot){
            int z = A[l+c+1];
            A[l+c+1] = A[i];
            A[i] = z;
            l++;
        }
        else if(A[i] == pivot){
            int y = A[l+c+1];
            A[l+c+1] = A[i];
            A[i] = y;
            c++;
        }
        else {
            r--;
        }
    }
    if (l < k+1 && k < r) return pivot;
    else if (r <= k) return quick_select(A+r, n-r, k-r);
    else return quick_select(A+1, l, k);
    }
    else return A[0];
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
