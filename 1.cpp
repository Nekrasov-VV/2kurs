#include<stdio.h> //реализация простого класса
#include<stdlib.h>
#include<string.h>
#define N 111
struct Student{
	private:
	char name[N];
	int group;
	public:
	void pr();
	Student (){ //конструктор без параметров
	name[0]=0;
	group=0;
	printf("constr %s\n",name);
	}
	Student(const char *, int); //конструктор с параметрами
	Student(const Student &);//конструктор копии для простого класса не нуждается в перегрузке
	int change_group(int); //перевод студента в другую группу его курса
	~Student(){ //деструктор для простого класса не делает ничего, поэтому не требуется писать
	printf("destr %s  %d\n",name,group);
	}
	friend Student change_kurs(Student student);//внешняя функция (не метод класса), переводит студента на следующий курс
	Student & operator=(const Student &student){//оператор присваивания, для простых классов в перегрузке не нуждается
		if(this==&student) // чтобы обработать случай самолприсваивания а=а;
			return *this;
		strcpy(this->name,student.name);
		this->group=student.group; 
		//this->pr();
		return *this;
	}
};
void Student::pr(){
	printf("%s %d\n",name,group);
}
Student::Student(const char *name, int group){
	strcpy(this->name,name); //this -- указатель на конкретный объект класса Student, именно тот, к которому применяется метод класса
	this->group=group;
	printf("contr %s  %d\n",name,group);

}	
Student::Student(const Student &student){
	strcpy(this->name,student.name);
	this->group=student.group;
	printf("copy-contr %s   %d\n",name,group);//для проверки, когда вызывается конструктор копии
}	
int Student::change_group(int group){//метод функции, не нуждается в параметрах иметь объект класса, т.к. всегда применяется к уже живущему по адресу this объекту
	if(abs(this->group/100-group/100)==0&&group>100){
	this->group=group;
	return 1;
	}
	return 0;
}
Student change_kurs(Student student){ //внешняя функция, является другом класса и поэтому имеет доступ к полям private
	
	printf("Vhod v function ");//аргумент - объект класса, поэтому вызывается конструктор копии, который строит временный объект (клон)
	student.group+=100;//переводим клона студента на другой курс
	printf("clon student=");
	student.pr();
	return student;//возвращаем клона в вызывающую функцию, при этом он еще раз копируется и затем погибает
}
int main(){
	int x=125;
	Student a("Ivanov",x),b=a; //явный вызов конструктора копии
	printf("a= ");
	a.pr();
	while(a.change_group(x--));//переводим студента в группу с  меньшим номером, пока это возможно
        printf("a= ");
	a.pr();
	printf("b= ");
	b.pr(); //b должен остаться в 125 группе
	b=change_kurs(b); //переводим b в 225 группу при этом дважды! вызыватся конструктор  копирования и деструктор
	printf("b= ");
	b.pr(); 
}
