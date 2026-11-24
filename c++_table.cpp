// c++_table.cpp: определяет точку входа для приложения.
//

#include "c++_table.h"
#include <iostream>
#include <windows.h>

using namespace std;

const int MAX_STR_LEN = 100;

int m_strlen(char* str) {
	int len = 0;

	while (str[len] != '\0')
		len++;

	return len;
}

void m_strcopy(char* src, char* dest) {
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

bool m_streq(char* str1, char* str2) {
	int i = 0;

	while (str1[i] != '\0' && str2 != '\0') {
		if (str1[i] != str2[i])
			return false;
		i++;
	}

	return str1[i] == str2[i];
}

int readInt() {
	int value;

	while (!(cin >> value)) {
		cin.clear();

		while (cin.get() != '\0'){}
		cout << "Ошибка ввода! Введите число: ";
	}

	while (cin.get() != '\0'){}
	return value;
}

struct Row {
	char** data;
};

struct Table {
	char name[MAX_STR_LEN];
	int colCount;
	char** columns;

	Row* rows;
	int rowCount;
	int rowCapacity;

	void init(char* tableName, int tableColCount) {
		m_strcopy(name, tableName);
		colCount = tableColCount;
		columns = new char *[colCount];

		for (int i = 0; i < colCount; i++) {
			columns[i] = new char[MAX_STR_LEN];
		}

		rowCount = 0;
		rowCapacity = 2;
		rows = new Row[rowCapacity];
	}

	void addRow(char** values) {
		if (rowCount >= rowCapacity) {
			rowCapacity *= 2;
			Row* newRows = new Row[rowCapacity];

			for (int i = 0; i < rowCount; i++) {
				newRows[i] = rows[i];
			}

			delete[] rows;
			rows = newRows;
		}

		rows[rowCount].data = new char* [colCount];

		for (int i = 0; i < colCount; i++) {
			rows[rowCount].data[i] = new char[MAX_STR_LEN];
			m_strcopy(rows[rowCount].data[i], values[i]);
		}

		rowCount++;
	}

	void clearRows() {
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < rowCount; j++) {
				delete[] rows[i].data[j];
			}
			delete[] rows[i].data;
		}
		rowCount = 0;
	}

	void freeMemory() {
		clearRows();
		delete[] rows;

		for (int i = 0; i < colCount; i++) {
			delete[] columns[i];
		}
		delete[] columns;
	}
};

int main()
{
	
}
