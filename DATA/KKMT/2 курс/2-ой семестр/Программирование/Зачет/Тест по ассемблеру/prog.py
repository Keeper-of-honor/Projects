'''Тест по ассемблеру. Разработали: Митюшин Пётр, Груздев Роман, Герасимов Дмитрий'''
print("\nAssembler test")
print("Данный тест содержит 7 вопросов")
score = 0;
answer = '0';

while (answer != '1'):
	print("\nДавай сыграем в игру?")
	print("1. Принять")
	print("0. Отказаться")
	answer = input()

print("\nВведите свой никнейм:")
name = input()
print("\n")

print("1. Выберите вариант с правильными наименованиями переменных:")
print("a) a, B, .a, ax")
print("b) c, b, bx")
print("c) a, b, a., ax")
answer = input()
if (answer == 'a'):
	print("Молодца!")
	score += 10
else:
	print("Error. Правильный ответ a")
print("Score: ", score, "\n")

print("2. Выберите вариант в котором флаг ZF = 0 и SF = 1:")
print("a) 255 - 200 = 200")
print("b) 30 - 30 = 0")
print("c) 56 - 89 = -33")
answer = input()
if (answer == 'c'):
	print("Неплохо!")
	score += 10
else:
	print("Error. Правильный ответ с")
print("Score: ", score, "\n")

print("3. Выберите вариант который вызывает функцию:")
print("a) int 21h")
print("b) int 16h")
print("c) int 10h")
answer = input()
if (answer == 'a'):
	print("А ты хорош!")
	score += 10
else:
	print("Error. Правильный ответ a")
print("Score: ", score, "\n")

print("4. Выберите вариант который производит деление целых без знака:")
print("a) mod op")
print("b) div op")
print("c) idiv op")
answer = input()
if (answer == 'b'):
	print("Воу-воу, полегче")
	score += 10
else:
	print("Error. Правильный ответ a")
print("Score: ", score, "\n")

print("5. Выберите вариант который производит умножение целых со знаком:")
print("a) imul op")
print("b) mul op")
print("c) pow op")
answer = input()
if (answer == 'a'):
	print("А ты не промах")
	score += 10
else:
	print("Error. Правильный ответ a")
print("Score: ", score, "\n")

print("6. Выберите вариант в который произойдет итоговая запись инструкции \"mul op\":")
print("a) ah")
print("b) bx")
print("c) ax")
answer = input()
if (answer == 'c'):
	print("Эйнштейн позавидовал бы тебе")
	score += 10
else:
	print("Error. Правильный ответ с")
print("Score: ", score, "\n")

print("7. С чего начинается любая программа на языке assembler:")
print("a) org 100h;")
print("b) start")
print("c) bruh")
answer = input()
if (answer == 'a'):
	print("Это называется \"Успех\"")
	score += 10
else:
	print("Error. Правильный ответ с")
print("Score: ", score, "\n")

if (score == 0):
	print(" В следующий раз результаты будут лучше.\n")
if (answer == 'c'):
	print("Хоть ты ответил и не правильно, но ты один из лучших людей что есть на этом свете")
	print("Полученна очивка: bruhт\n")
elif (score == 70):
	print("Полученна очивка: Снайпер\n")

fout = open('records.txt', 'a')
fout.write(name + " получил - " + str(score) + " очков из 70\n")
fout.close()

print("Игра закончилась")
