#Выполнил: Герасимов Дмитрий
#Группа: П1-18


import random


#---------------------------------------------------------

#Быстрая сортировка
def QuickSort(mas, start, end):
    if (start >= end):
        return
    else:
        q = random.choice(mas[start:end + 1])
        i = start
        j = end
        while i <= j:
            # i < q > j :True True
            while mas[i] < q:
                i += 1
            while mas[j] > q:
                j -= 1
            if (i <= j):
                mas[i], mas[j] = mas[j], mas[i]
                i += 1
                j -= 1
                QuickSort(mas, start, j)
                QuickSort(mas, i, end)

#---------------------------------------------------------


#Графическое представление массива
def Graf(mas, start, end):
	arr = mas[start:end]
	len_arr = len(arr)
	maxx = 0
	if (len_arr != 0):
		maxx = max(arr)
	print("Активная часть")
	print(arr)
	space = []
	for i in range(maxx):
		for j in range(len_arr):
			if (i == 0):
				space.append(' '*len(str(arr[j])))
				
			if (arr[j] > 0):
				print(' |', end=space[j])
				arr[j] -= 1
			else:
				print('  ', end=space[j])
		print()
	print()


#Быстрая сортировка С ВЫВОДОМ ПРОМЕЖУТОЧНЫХ ЭТАПОВ НА ЭКРАН
#Передается массив, индекс 1-го элемента и индекс последнего элемента
def QuickSortD(mas, start, end):
	print(f"Массив: {mas}")
	if (start >= end):
		print("return")
		return
	else:
		q = random.choice(mas[start:end + 1])
		print('q =', q)
		i = start
		j = end
		print(f"Before: i = {i}; j = {j}")
		while i <= j:
			# mas[i] < q < mas[j] :True True
			print(f"i.mas[{i}] = {mas[i]}")
			while mas[i] < q:
				i += 1
				print(f"i.mas[{i}] = {mas[i]}")
			print(f"j.mas[{j}] = {mas[j]}")
			while q < mas[j]:
				j -= 1
				print(f"j.mas[{j}] = {mas[j]}")
			print(f"After: i = {i}; j = {j}")
			if (i <= j):
				print(f"Swap: {mas[i]} and {mas[j]}")
				mas[i], mas[j] = mas[j], mas[i]
				i += 1
				j -= 1
				print(f"After x2: i = {i}; j = {j}")
				
				print("От start до j")
				Graf(mas, start, j)
				QuickSortD(mas, start, j)
				
				print("От i до end")
				Graf(mas, i, end)
				QuickSortD(mas, i, end)

