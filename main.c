/*
* @file main.c
* @author Renat Kagal <kagal@itspartner.net>
*
* Assembling : gcc -Wall main.c -o main
*
* Description : program makes bits oparations with numbers
*
* Copyright (c) 2021, ITS Partner LLC.
* All rights reserved.
*
* This software is the confidential and proprietary information of
* ITS Partner LLC. ("Confidential Information"). You shall not
* disclose such Confidential Information and shall use it only in
* accordance with the terms of the license agreement you entered into
* with ITS Partner.
*/

#include "head.h"

int main () {
	int n = 0, i = 0;
	FILE* fp;

	if ( (fp = fopen ("text.txt", "w") ) == NULL) {
		puts ("Failes open file");
		exit (EXIT_FAILURE);
	}/*
	scanf ("%d", &n);
	task_1 (n, fp);

	scanf ("%d", &n);
	task_2 (n, fp);

	scanf ("%d", &n);
	task_3 (n, fp);

	scanf ("%d", &n);
	task_4 (n, fp);

	scanf ("%d%d", &n, &i);
	task_5 (n, i, fp);

	scanf ("%d%d", &n, &i);
	task_6 (n, i, fp);
	
	scanf ("%d%d", &n, &i);
	task_7 (n, i, fp);
	
	scanf ("%d", &n);
	task_8 (n, fp);
	
	scanf ("%d", &n);
	task_9 (n, fp);
	*/
	scanf ("%d", &n);
	task_10 (n, fp);
}

void task_1 (int n, FILE* fp) {
	n = 1 << n;
	printf ("task_1 : %d\n", n);
	fprintf (fp, "task_1 : %d\n", n);
}

void task_2 (int n, FILE* fp) {
	char* bits = "";

	while (n > 0) {
		asprintf (&bits, "%d%s", (n & 1), bits);
		n = n >> 1;
	}
	printf ("task_2 : %s\n", bits);
	fprintf (fp, "task_2 : %s\n", bits);
}

void task_3 (int n, FILE* fp) {
	int count = 0;

	while (n > 0) {
		if (n & 1) 
			count++;
		n = n >> 1;
	}
	printf ("task_3 : %d\n", count);
	fprintf (fp, "task_3 : %d\n", count);
}

void task_4 (int n, FILE* fp) {
	for (int i = 32; i > 0; i--) {
		if (n & (1 << (i - 1))) {
			printf ("task_4 : %d\n", i);
			fprintf (fp, "task_4 : %d\n", i);
			break;
		}
	}
}

void task_5 (int n, int i, FILE* fp) {
	printf ("task_5 : %d\n", (n | (1 << i)));
	fprintf (fp, "task_5 : %d\n", (n | (1 << i)));
}

void task_6 (int n, int i, FILE* fp) {
	printf ("task_6 : %d\n", (n & ~(1 << i)));
	fprintf (fp, "task_6 : %d\n", (n & ~(1 << i)));
}

void task_7 (int n, int i, FILE* fp) {
	printf ("task_7 : %d\n", (n ^ (1 << i)));
	fprintf (fp, "task_7 : %d\n", (n ^ (1 << i)));
}

void task_8 (int n, FILE* fp) {
	int i = 0;

	for (i = 31; i >= 0; i--) {
		if (n & (1 << i)) {
			break;
		}
	}
	n = ((n & ~(1 << i)) << 1) | 1;

	printf ("task_8 : %d\n", n);
	fprintf (fp, "task_8 : %d\n", n);
}

void task_9 (int n, FILE* fp) {
	task_2 (n, fp);
	int count = 0;

	while (n > 1) {
		if ( (n & 1)&& (n & (1 << 1))) {
			count++;
		}
		n = n >> 1;
	}

	printf ("task_9 : %d\n", count);
	fprintf (fp, "task_9 : %d\n", count);
}

void task_10 (int n, FILE* fp) {
	task_2 (n, fp);
	int i1 = 0, i2 = 0;

	printf ("Enter i1 i2 \n");
	scanf ("%d%d", &i1, &i2);

	if ((n & (1 << i1)) && (n & (1 << i2))) ;
	else {
		n = n ^ (1 << i1);
		n = n ^ (1 << i2);
	}
	task_2 (n, fp);
	printf ("task_10 : %d\n", n);
	fprintf (fp, "task_10 : %d\n", n);	
}
/*
Задачи на битовые операции:
1. Ввести целое число n и вывести 2^𝑛, используя битовые операции.
2. Вывести двоичное представление целого положительного числа, используя битовые операции.
3. Найти количество единиц в двоичном представлении целого положительного числа.
4. Найти номер старшего бита в двоичном представлении целого положительного числа.
5. Ввести целые числа n и i и вывести целое число, у которого i-й бит установлен в 1, а все остальные биты совпадают с битами числа n на тех же
позициях. Например, если введены 9 и 1, ответом будет 11.
6. Ввести целые числа n и i и вывести целое число, у которого i-й бит сброшен в 0, а все остальные биты совпадают с битами числа n на тех же
позициях. Например, если введены 11 и 1, ответом будет 9.
7. Ввести целые числа n и i и вывести целое число, у которого i -й бит отличается от i -го бита числа n , а все остальные биты совпадают с битами
числа n на тех же позициях. Например, если введены 5 и 1, ответом будет 7.
8. Ввести целое число n и вывести число, полученное в результате
циклического сдвига числа n на один разряд влево, т. е. старший бит перемещается в позицию младшего, а все остальные биты сдвигаются на один
разряд влево. Например, если введено 130, ответом будет 5.
9. Определить, сколько раз встречается 11 в двоичном представлении целого
положительного числа (в двоичном представлении 11110111 оно встречается
5 раз).
10. Поменять местами два бита с заданными номерами в двоичном представлении целого положительного числа.
11. Вычеркнуть i-й бит из двоичного представления целого положительного числа (младшие i-го биты остаются на месте, старшие сдвигаются на
один разряд вправо). Например, если введены 11 и 2, ответом будет 7.
12. Написать макросы для перевода 1,2,4 байтовых переменных в сетевое представление(big endian)

Каждый пункт можно оформить как вызов функции в главном main'e с передачей парамтеров(чтобы не делать кучу мелких задач)
*/