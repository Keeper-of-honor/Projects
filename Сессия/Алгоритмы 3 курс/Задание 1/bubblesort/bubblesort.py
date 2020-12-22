#Выполнил: Герасимов Дмитрий
#Группа: П1-18


import random


#---------------------------------------------------------

#Быстрая сортировка
def BubbleSort(mas):
	len_n = len(mas)
	for i in range(len_n):
		for j in range(i+1, len_n):
			if (mas[i] > mas[j]):
				mas[i], mas[j] = mas[j], mas[i]

#---------------------------------------------------------


#Графическое представление массива
def Graf(mas):
	arr = mas[:]
	len_arr = len(arr)
	maxx = 0
	if (len_arr != 0):
		maxx = max(arr)
	space = []
	print(arr)
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


#Сортировка обменом С ВЫВОДОМ ПРОМЕЖУТОЧНЫХ ЭТАПОВ НА ЭКРАН
def BubbleSortD(mas):
	len_n = len(mas)
	for i in range(len_n):
		for j in range(i+1, len_n):
			if (mas[i] > mas[j]):
				mas[i], mas[j] = mas[j], mas[i]
		Graf(mas)


#Меню
def menu():
	print()
	print('-----------------------------------')
	print('		Menu		')
	print()
	print("0. Выход")
	print("1. Сортировка обменом")
	print("2. Сортировка обменом с пояснениями")
	print("3. Ввод массива")
	print("4. Характеристика сортировки")
	print()
	print('-----------------------------------')
	print()


#	{-- MAIN --}
def main():
	print()
	mas = [int(i) for i in input("Введите массив\n>> ").split()]
	n = -1
	while n:
		menu()
		n = int(input(">> "))
		
		#1. Сортировка обменом
		if (n == 1):
			print(mas)
			arr = mas[:]
			BubbleSort(arr)
			print(arr)
		
		#2. Сортировка обменом с пояснениями
		elif (n == 2):
			arr = mas[:]
			print(arr)
			Graf(arr)
			print()
			BubbleSortD(arr)
			Graf(arr)
		
		#3. Ввод массива	
		elif (n == 3):
			print()
			mas = [int(i) for i in input("Введите массив\n>> ").split()]
		
		#4. Характеристика сортировки
		elif (n == 4):
			print()
			print("Характеристика сортировки")
			print()
			print("Один из самых известных алгоритмов сортировки, реализовать который часто просят на технических собеседованиях. В этом алгоритме массив перебирается раз за разом, и каждое следующее значение сравнивается с предыдущим. После первого прохода по массиву самое большое число окажется в конце, а когда первый элемент будет не с чем сравнить, массив будет отсортирован по возрастанию.")
			print()
			print('Time Complexity Best: Ω(n)')
			print('Time Complexity Average: Θ(n^2)')
			print('Time Complexity Worst: O(n^2)')
			print('Space Complexity Worst: O(1)')
	print()
	print("Бывай")
	print()


if __name__ == '__main__':
	main()
