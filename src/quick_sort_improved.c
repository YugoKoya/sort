#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
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
    int k = 1;
    while (k <= l) {
        if (k < l) {
            A[k-1] = A[k];
            k = k+1;
        }
        else {
            A[k-1] = A[k];
            A[k] = pivot;
            k = k+1;
        }
    }
    quick_sort(A,l);
    quick_sort(A+r,n-r);
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

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
