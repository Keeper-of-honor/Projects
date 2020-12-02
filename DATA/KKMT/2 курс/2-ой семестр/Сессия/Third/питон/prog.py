data = []
with open("text.txt") as f:
    for line in f:
        data.append([float(x) for x in line.split()])

print(*data)

imin = data[0].index(min(min(data)))
imax = data[0].index(max(max(data)))
data[0][imin], data[0][imax] = data[0][imax], data[0][imin]

print(*data)
