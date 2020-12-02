'''
Дата 20.11.2020
Выполнил: Герасимов Дмитрий П1-18

Задача 1.
    Вводится некоторое количество целых чисел. 
    Нужно распечатать их в обратном порядке. Используем стек.
    Пример
    Ввод 1 2 3 4 5
    Вывод 5 4 3 2 1

'''

stek = []
stek_memory = []
len_stek = 0
for i in input().split():
    stek_memory.append(int(i))
    len_stek += 1

for i in range(len_stek):
    stek.append( stek_memory.pop() )

print(*stek)
