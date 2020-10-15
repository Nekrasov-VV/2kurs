#include <iostream> //шаблон очереди объктов класса Type на базе конечного массива
#include<stdio.h>
using namespace std;
template<class Type=int> // по умолчанию очередь из целых чисел
class Queue {
		Type *body;//массив для хранения объектов классса Type
		int Maxsize,head,tail;//глубина, голова и хвост очереди
		int next(int);//кольцевание очереди
		public:
		Queue(int); //создает пустой стек заданной глубины (размера)
		~Queue(); //деструктор очереди
		int push(const Type &);//лобавление элемента в конец очереди
		int pop(Type &);//удаление элемента из головы очереди
		Queue(const Queue<Type> &);//перегрузка конструктора копии (т.к. класс сложный, необходимо)
		Queue<Type> & operator =(const Queue<Type> &);//перегрузка присваивания (т.к. класс сложный, необходимо)
};
template<class Type>
Queue<Type>:: Queue(int n){
		Maxsize=n+1;//лишняя ячейка нужна для дифференциации пустой и зполненной до максимума очереди
		head=tail=n;//в пустой очереди голова и хвост совпадают. 
//Голова непустой очереди -- индекс ее начала, 
//хвост всегда указывает на свободную ячейку в конце очереди 
		body=new Type[n+1];
}
template<class Type>
Queue<Type>:: ~Queue(){
		delete []body;//[] нужен для вызова деструктора объектов, находящихся в очереди
}

template<class Type> int
Queue<Type>::next(int n){
	return n==Maxsize-1? 0:n+1;// индексы внутри очереди движутся по кругу против часовой стрелки
}

template<class Type>
int Queue<Type>::push(const Type &v){// кладем объект v в конец очереди, возвращает 0, если нельзя положить и 1, если можно
	return next(tail)==head?0:(body[tail]=v,tail=next(tail),1);
//надо положить v в свободную ячейку массива по индексу tail и изменить его ппозицию, 
//при  этом нельзя допустить, чтобы в результате голова совпала с tail
}
template<class Type>
int Queue<Type>::pop(Type &v){
	return head==tail?0:(v=body[head],head=next(head),1);
//надо взять элемент по индексу head и изменить положение head,
//операция невозможна, если очередь пуста
}
template<class Type> 
Queue<Type>:: Queue(const Queue<Type> &v){
		Maxsize=v.Maxsize;
		head=v.head;
		tail=v.tail;
	        body=new Type[Maxsize];
		for (int i=0;i<Maxsize;i++)//для простоты копируем все объекты массива, 
//а не только те, которые реально присутствуют
			body[i]=v.body[i];
}

template<class Type> Queue<Type> &
Queue<Type>:: operator=(const Queue<Type> &v){
		if(this==&v)
			return *this;
		delete []body;
		Maxsize=v.Maxsize;
		head=v.head;
		tail=v.tail;
		body=new Type[Maxsize];
		for (int i=0;i<Maxsize;i++)
			body[i]=v.body[i];
		return *this;
}
template<class Type> void
	pr(Queue<Type> v){ // при вызове печати изменения косаюттся только ее копии
		Type u;
		while(v.pop(u)) //пока из очереди можно достать элемент, сохраняем его в u
			cout<<" "<<u;//печатаем u, при этом класс TYpe должен поддерживать операцию << вставить в поток 
	cout<<"\n";
}



