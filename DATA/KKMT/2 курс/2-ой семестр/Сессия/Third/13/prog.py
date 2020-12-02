# 13. Дан файл вещественных чисел. Найти его первый локальный минимум (локальным минимумом называется элемент, который меньше своих соседей). Python

data = []
with open("text.txt") as f:
    for line in f:
        data.append([float(x) for x in line.split()])
print(min(min(data)))
