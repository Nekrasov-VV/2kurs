#include"my.h"

Student::Student (int x){ 
	N=x;
	name= new char[N+1];
	for(int i=0;i<x;i++)
		name[i]='a'+rand()%26;//заполняем фамилию случайными прописными буквами
	name[x]=0;//завершаем заполнение фамилии
	if(N>0)
		name[0]-='a'-'A';//первую букву фамилии делаем заглавной
	group=101+rand()%26;//при рождении студента регистрируем в группу первого курса случайным образом
}
Student::Student (){ 
	N=0;
	name=nullptr;
	
}
void Student::pr()const{
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
	cout<<student.name<<" group N "<<student.group <<endl;//вставляем в выходной поток фамилию и номер группы
	return cout;
}
Student Student::operator+(const Student &student){
	Student tmp(*this);//строим локальный временный объект, т.к. хотим сохранить слагаемые, бе этого нельзя
	tmp.group=student.group;// по построению tmp унаследовал фамилию первого слагаемого, определяем его в группу второго слагаемого
	return tmp;//возвращаем локальный объект. При этом он будет скопирован (путем вызова конструктора копии) во временный объект функции, производящей сложение
}
Student::~Student(){    
	delete []name;
	name=nullptr;
}
Student & Student::operator=(const Student &student){ //  c=a=b;
	if(this==&student)
		return *this;	
	N=student.N;
	group=student.group;
	delete []name;
	if(N==0){
		name=0;
		return *this;
	}
	name=new char[N+1];
        strcpy(this->name,student.name);
	return *this;
}
Student::Student (const Student &student){
	N=student.N;
	group=student.group;
	if(N==0){
		name=0;
		return ;
	}
	name=new char[N+1];
	strcpy(this->name,student.name);
}

Student &Student::operator=(Student &&student){
	N=student.N;
	group=student.group;
	delete []name;
	name=student.name;
	student.name=nullptr;
	return *this;
}
Student::Student (Student &&student){
        N=student.N;
	group=student.group;
	name=student.name;
	student.name=nullptr;
}
