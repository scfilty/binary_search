#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int w = 0;
  int a = 0;
  int i;
  for(i = 0; i < n; i++){
    if(m < A[i]) return 0;
    if( m >= w + A[i]) w += A[i];
    else{
        a += 1;
        w = A[i]; 
    }
  }
  return a < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 0;
  for (i = 0; i < n; i++){
    ub +=A[i];
  }
  while( ub - lb > 1){
      int m = (ub + lb) / 2;
      if(p(m)) ub = m;
      else lb = m;
  }
  printf("%d\n",ub);

  return 0;
}