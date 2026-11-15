baris, kolom = map(int, input().split())
elemen = list(map(int, input().split()))

idx = 0
for i in range(baris):
    row = []
    for j in range(kolom):
        row.append(elemen[idx])
        idx += 1
    print(*(row))