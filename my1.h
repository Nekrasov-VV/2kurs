#include<stdio.h> //реализация сложного класса
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string.h>
using namespace std;

class Student{
	char *name; //память нужно выделять в конструкторах
	int N;  // количество букв в фамилии
	int group;
	public:
	void pr()const;
	Student (int); 
	Student (); 

	Student operator+(const Student &);
	Student & operator ++(void);//инкремент  ++student возвращает измененный объект
	Student   operator ++(int);//инкремент student++ возвращает копию исходного объекта, и потом исходный изменяет
	friend ostream &operator<<(ostream &, const Student &);//const необходим, иначе нельзя вставлять временные объекты, в т.ч. суммы такого типа: a+b++ +Student()
	//  _______//___________
	~Student(); //деструктор
	Student & operator=(const Student &);//присваивание копированием
	Student (const Student &); //конструктор копии
	Student (Student &&); //копирование перемещением
	Student & operator=(Student &&student); //присваивание перемещением

};
