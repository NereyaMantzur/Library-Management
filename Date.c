#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Date.h"
#include "General.h"

Date* initDate()
{
	Date* newDate = (Date*)malloc(sizeof(Date));
	if (!newDate)
	{
		return NULL;
	}

	newDate->day = 0;
	newDate->month = 0;
	newDate->year = 0;
	return newDate;
}

void printDate(const Date* date)
{

	printf("%2d/%2d/%4d", date->day, date->month, date->year);
}

Date* add30DaysToCurrentTime(Date* date)
{

	time_t t = time(NULL);
	struct tm currentTime = *localtime(&t);

	// Add 30 days
	currentTime.tm_mday += 30;

	mktime(&currentTime);

	date->day = currentTime.tm_mday;
	date->month = currentTime.tm_mon + 1;
	date->year = currentTime.tm_year + 1900;

	printf(RED_TEXT "Date of return: %02d/%02d/%04d\n" RESET_COLOR, currentTime.tm_mday, currentTime.tm_mon + 1, currentTime.tm_year + 1900);

	return date;
}

