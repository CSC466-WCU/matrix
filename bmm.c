#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mmul(double *A, double *B, double *C, long N) {
  int stride = 8;
  for (int k = 0; k < N; k+=stride)
    for (int i = 0; i < N; i+=stride)
      for (int j = 0; j < N; j+=stride){
        int k_stride = k + stride;
        int i_stride = i + stride;
        int j_stride = j + stride;
        for (int k_b = k; k_b < k_stride; k_b++)
          for (int i_b = i; i_b < i_stride; i_b++)
            for (int j_b = j; j_b < j_stride; j_b++)
              C[i_b * N + j_b] += A[i_b * N + k_b] * B[k_b * N + j_b];
      }
}

int main(int argc, char *argv[]) {
  double *a; double *b; double *c;
  clock_t start,end;

  long N = atol(argv[1]);
  long size = N * N;
  a = (double *) malloc(sizeof(double) * size);
  b = (double *) malloc(sizeof(double) * size);
  c = (double *) malloc(sizeof(double) * size);

  for (int i = 0; i < size; i++) {
    a[i] = 1.0; b[i] = 2.0; c[i] = 0.0;
  }

  start = clock();
  mmul(a, b, c, N);
  end = clock();
  printf("It takes %lf seconds\n", ((double)(end - start))/ CLOCKS_PER_SEC);
  return 0;
}
