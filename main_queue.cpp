#include"queue.h"
#include"my.h" // тест для класса , определенного в этом afqkt

int main(){
	srand(time(NULL));
	Queue<Student>q(5);//очередь целых чисел создается вызовом Queue<>
	int k=3;
	do{
	   ;
	}
	while(q.push(++Student(++k)));//заполняем очередь студентами
	pr(q);
	Student u;
	q.pop(u); //обслуживаем голову
	q.push(Student(3)); //очередь подвинулась на 1 позицию
	pr(q);
    	return 0;
}

