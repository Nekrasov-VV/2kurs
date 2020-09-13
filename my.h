#include<stdio.h> //реализация простого класса
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iostream>
using namespace std;
#define N 11

class Student{
	char name[N];
	int group;
	public:
	void pr();
	Student (); //конструктор без параметров, заполняет фамилию студента и номер группы случайными числами
	Student(const char *, int); //конструктор с параметрами
	Student operator+(const Student &);//const необходим, иначе нельзя складывать временные объекты
// в сумме фамилия от первого студента, группа от второго
	Student & operator ++(void);//инкремент  ++student возвращает измененный объект
	Student   operator ++(int);//инкремент student++ возвращает копию исходного объекта, и потом исходный изменяет
	friend ostream &operator<<(ostream &, const Student &);//const необходим, иначе нельзя вставлять временные объекты, в т.ч. суммы такого типа: a+b++ +Student()
// вставляет студента в выходной поток
};
