n = int(input())

def baca_matriks(n):
    matriks = []
    while len(matriks) < n:
        line = input().strip()

        if not line or "Matriks" in line:
            continue
        matriks.append(list(map(int, line.split())))
    return matriks

A = baca_matriks(n)
B = baca_matriks(n)
C = [[0] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        for k in range(n):
            C[i][j] += A[i][k] * B[k][j]

print("Matriks AXB")
for row in C:
    print(*(row))