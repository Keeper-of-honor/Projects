/*
 * Param60°. Используя тип TDate и функцию LeapYear (см. задание Param59), описать функцию DaysInMonth(D) целого типа с параметром типа TDate, которая возвращает количество дней для месяца, указанного в дате D. Вывести значение функции DaysInMonth для пяти данных дат (предполагается, что все даты являются правильными)
 */

/// Структура "tdate". Герасимов Д.А., 25.05.2020
#ifndef TDATE_H
#define TDATE_H

struct tdate{
	unsigned int day; /// День
	unsigned int month; /// Месяц
	unsigned int year; /// Год

	/// Количество дней для месяца
	unsigned int days_in_month();
};

#endif /// TDATE_H
