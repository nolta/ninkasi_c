#include <stdio.h>


void clapack_dsyrk(char uplo, char trans, int n, int k, double alpha, double *a, int lda, double beta, double *c, int ldc);
void clapack_ssyrk(char uplo, char trans, int n, int k, float alpha, float *a, int lda, float beta, float *c, int ldc);

void sgesv_(int *n, int *nrhs, float *a, int *lda, int *ipiv, float *b, int *ldb, int *info);
void clapack_sgesv(int n, int nrhs, float *a, int lda, int *ipiv, float *b, int ldb, int *info);

void dgesv_(int *n, int *nrhs, double *a, int *lda, int *ipiv, double *b, int *ldb, int *info);
void clapack_dgesv(int n, int nrhs, double *a, int lda, int *ipiv, double *b, int ldb, int *info);

void spotri_( char *uplo, int *n, float *a, int *lda, int *info);
void clapack_spotri(char uplo, int n, float *a, int lda, int *info);

void spotrf_( char *uplo, int *n, float *a, int *lda, int *info);
void clapack_spotrf(char uplo, int n, float *a, int lda, int *info);

#ifdef _SKIP_MKL
void ssyev_(char *jobz, char *uplo, int *n, float *a, int *lda, float *w, float *work, int *lwork, int *info, int jobzlen,int uplolen);
#endif
void clapack_ssyev(char jobz, char uplo, int n, float *a, int lda, float *w, float *work, int lwork, int *info);

void clapack_ssyevd(char jobz, char uplo, int n, float *a, int lda, float *w, float *work, int lwork,int *iwork, int liwork, int *info);
#ifdef _SKIP_MKL
void ssyevd_(char *jobz, char *uplo, int *n, float *a, int *lda, float *w, float *work, int *lwork,int *iwork, int *liwork, int *info, int jobzlen, int uplolen);
#endif






void dpotri_( char *uplo, int *n, double *a, int *lda, int *info);
void clapack_dpotri(char uplo, int n, double *a, int lda, int *info);

void dpotrf_( char *uplo, int *n, double *a, int *lda, int *info);
void clapack_dpotrf(char uplo, int n, double *a, int lda, int *info);



/*routines I have written with mallocs included so they're easier to use*/
void clapack_ssyevd_simple(char jobz, char uplo, int n, float *a, int lda, float *w, int *info);
void clapack_ssyev_simple(char jobz, char uplo, int n, float *a, int lda, float *w, int *info);



