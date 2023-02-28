#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mmul(double *A, double *B, double *C, long N) {
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        C[i * N + j] += A[i * N + k] * B[k * N + j];
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
