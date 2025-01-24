#include <stdio.h>
#define MAX 101

struct sparse {
    int row;
    int col;
    int value;
};

struct sparse smat[MAX],stmat[MAX] ;

void scan_mat(int mat[][10], int m, int n);
void print_mat(int mat[][10], int m, int n);
void sparse_gen(int mat[][10], int m, int n, struct sparse smat[]);
void print_sparse(struct sparse smat[]);
void sparse_transpose(struct sparse a[], struct sparse b[]);

int main() {
    int m, n, mat[10][10];

    printf("Enter row & col:\n");
    scanf("%d%d", &m, &n);

    scan_mat(mat, m, n);
    printf("Input matrix:\n");
    print_mat(mat, m, n);

    sparse_gen(mat, m, n, smat);
    print_sparse(smat);

    sparse_transpose(smat, stmat);
    printf("Transposed sparse matrix:\n");
    print_sparse(stmat);

    return 0;
}

void scan_mat(int mat[][10], int m, int n) {
    printf("Enter matrix elements (%dX%d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void print_mat(int mat[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void sparse_gen(int mat[][10], int m, int n, struct sparse smat[]) {
    int k = 1;
    smat[0].row = m;
    smat[0].col = n;
   

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                smat[k].row = i;
                smat[k].col = j;
                smat[k].value = mat[i][j];
                k++;
            } 
        }
    }
     smat[0].value = k - 1; //it shold be there it here .if you write into the upper it will prijnt just value
}

void print_sparse(struct sparse smat[]) {
    printf("The generated sparse matrix is:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= smat[0].value; i++) {
        printf("%d\t%d\t%d\n", smat[i].row, smat[i].col, smat[i].value);
    }
}
 
void sparse_transpose(struct sparse a[], struct sparse b[]) {
    int n;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

if (n>0){
    int k=1;
    for (int i=0;i<a[0].col;i++){
        for(int j=1;j<=n;j++){
            if(a[j].col==i){
                b[k].row=a[j].col;
                b[k].col=a[j].row;
                b[k].value=a[j].value;
                k++;
            }
        }
            }
        }
    }
