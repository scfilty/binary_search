#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int a = 0;
  int i;
  for(i = 0; i < n; i++){
    a = a + A[i]/m;
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
  ub = 100000000001;

  while (ub - lb > 1){
    int m = (ub + lb)/2;
    if (p(m)) ub =m;
    else lb = m;
  }
  printf("%d\n", lb);
  return 0;
}
