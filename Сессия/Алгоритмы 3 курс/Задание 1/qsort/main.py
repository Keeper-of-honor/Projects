#Выполнил: Герасимов Дмитрий
#Группа: П1-18

import qsort

#Меню
def menu():
	print()
	print('-----------------------------------')
	print('		Menu		')
	print()
	print("0. Выход")
	print("1. Сортировка q-sort")
	print("2. Сортировка q-sort с пояснениями")
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
		
		#1. Сортировка q-sort
		if (n == 1):
			print(mas)
			arr = mas[:]
			qsort.QuickSort(arr, 0, len(arr)-1)
			print(arr)
			
		#2. Сортировка q-sort с пояснениями
		elif (n == 2):
			print(mas)
			arr = mas[:]
			qsort.Graf(arr, 0, len(arr))
			print()
			qsort.QuickSortD(arr, 0, len(arr)-1)
			#print(arr)
			qsort.Graf(arr, 0, len(arr))
			
		#3. Ввод массива
		elif (n == 3):
			print()
			mas = [int(i) for i in input("Введите массив\n>> ").split()]
			
		#4. Характеристика сортировки
		elif (n == 4):
			print()
			print("Характеристика сортировки")
			print()
			print('Один из известных и быстрых алгоритмов сортировки, разработанный в МГУ английским информатиком Чарльзом Хоаром. Его часто называет quicksort или просто qsort – по названию стандартной библиотеки языка C. Является существенно переработанной версией пузырьковой сортировки.')
			print()
			print('Time Complexity Best: Ω(n*log(n))')
			print('Time Complexity Average: Θ(n*log(n))')
			print('Time Complexity Worst: O(n^2)')
			print('Space Complexity Worst: O(log(n))')
			
	print()
	print("Бывай")
	print()


if __name__ == '__main__':
	main()
