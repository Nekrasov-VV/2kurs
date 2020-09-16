#include"my.h"
Student::Student (){ //конструктор без параметров
	int x=2+rand()%(N-3);// фамилия студента рандомной длины
	for(int i=0;i<x;i++)
		name[i]='a'+rand()%26;//заполняем фамилию случайными прописными буквами
	name[x]=0;//завершаем заполнение фамилии
	name[0]-='a'-'A';//первую букву фамилии делаем заглавной
	group=101+rand()%26;//при рождении студента регистрируем в группу первого курса случайным образом
}
void Student::pr(){
	printf("%s %d\n",name,group);
}
Student &  Student::operator ++(void){ //++a
	if(group<600) //если номер курса больше 1, переводим студента на курс ниже
		group+=100;
	return *this; //возвращаем измененный объект
}
Student Student::operator ++(int){ //a++
	Student tmp(*this); //перед изменением делаем копию объекта
	if(group<600) //если номер курса больше 1, переводим студента на курс ниже
		group+=100;
	return tmp;//возвращаем неизмененный объект
}
ostream &operator<<(ostream &cout, const Student &student){
	cout<<student.name<<" group N "<<student.group<<endl;//вставляем в выходной поток фамилию и номер группы
	return cout;
}
Student Student::operator+(const Student &student){
	Student tmp(*this);//строим локальный временный объект, т.к. хотим сохранить слагаемые, бе этого нельзя
	tmp.group=student.group;// по построению tmp унаследовал фамилию первого слагаемого, определяем его в группу второго слагаемого
	return tmp;//возвращаем локальный объект. При этом он будет скопирован (путем вызова конструктора копии) во временный объект функции, производящей сложение
}
Student::Student(const char *name, int group){
	strcpy(this->name,name); 
	this->group=group;
	printf("contr %s  %d\n",name,group);
}
