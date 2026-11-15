#include <stdio.h>
#include <string.h>

void bacaMatriks(int n, int matriks[n][n]) {
    char buffer[100];
    int count = 0;
    while (count < n) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
            if (strstr(buffer, "Matriks") != NULL) {
                continue;
            }
            int temp[n];
            int matched = 0;
            if (n == 2) {
                matched = sscanf(buffer, "%d %d", &temp[0], &temp[1]);
            } else if (n == 3) {
                matched = sscanf(buffer, "%d %d %d", &temp[0], &temp[1], &temp[2]);
            } else {
                char *ptr = buffer;
                for(int i=0; i<n; i++) {
                    int val, offset;
                    if(sscanf(ptr, "%d%n", &val, &offset) == 1) {
                        temp[i] = val;
                        ptr += offset;
                        matched++;
                    }
                }
            }
            
            if (matched == n) {
                for (int j = 0; j < n; j++) {
                    matriks[count][j] = temp[j];
                }
                count++;
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    char dummy[100];
    fgets(dummy, sizeof(dummy), stdin);
    
    int A[n][n], B[n][n], C[n][n];
    
    bacaMatriks(n, A);
    bacaMatriks(n, B);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    printf("Matriks AXB\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", C[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}