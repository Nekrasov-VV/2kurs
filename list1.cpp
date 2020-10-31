#include"list.h" 
//_____________________Node
List::Node::Node(){ //используем для построения выделенного элемента, в нем данные не хранятся
	this->v=T();
}
List::Node::Node(const T &v){//строит узел и загружает данные на хранение
	this->v=T(v);
}
//_________________________ List основные методы
List::List(){//создает список, состоящий из выделенного элемента (пустой)
	base=new Node();
	base->next=base;
	cur=base;
}
List::~List(){
	cur=base;//очистка всего списка
	Clean();
}
int List::Del(){ //удаляет следующий элемент, т.е.  next
	if(cur->next==cur)//если список пуст, удалять элемент нельзя
		return 0;
	Node *tmp=cur->next;//запомним указатель на следующий
	cur->next=cur->next->next;//объявляем, что теперь следующим будет next->next
	delete tmp;//стираем вырезанный элемент (освобождаем ранее выделенную под этот узел память
	return 1; //в случае успеха возвращаем 1
}
void List::Clean(){
	if(!base)
		return;
	while(Del())//пока список не пуст, удаляем элемент
		;//нужно понимать, что сдвигаться по списку не надо
	delete base; //пустой список тоже требовал выделения памяти
}
void List::Ins(const T&v){ //вставка элемента происходит рядом (справа) с текущим
	Node *tmp=new Node(v); //строим новый узел
	tmp->next=cur->next;//следующим для tmp будет next
	cur->next=tmp; //вклеиваем новый узел в список
}

void List::GoToBegin(){//передвигаем текущий в начало списка
	cur=base;
}
int List::GoToNext(){ //передвигаем текущий в следующую позицию
	if(cur->next==base)
		return 0;
	cur=cur->next;
		return 1;
}
T& List::Get(){
	return cur->v;
}



List::iterator List::Begin()const{
	return iterator(this);
}

List::Node * List::End() const{
	return base;
}

List::List(const List &l){
	base=new Node();// у копии списка должен быть свой base
	base->next=base;//начинаем копировать с пустого списка
	cur=base; 
	Node *cur0=base;// для сохранения положения текущего (в копии l)
	for(iterator it=l.Begin();it!=l.End();++it){//перебираем элементы списка l
	        Ins(*it);//вставляем такой же в *this
		GoToNext();//сдвигаемся по списку
		if(it.cur==l.cur)//если положение итератора совпало с положением текущего в l, 
		cur0=cur;//запоминаем адрес этого узла в *this
	}	
	cur=cur0;	
}

List::List(List&&l){//конструктор перемещения, нужен для оптимизации (если она требуется)
	base=l.base;//временные объекты (r-value) можно не копировать, а передавать их base   
	cur=l.cur;
	l.base=0;//это нужно, чтобы деструктор временного объекта не разрушил его ресурс
	l.cur=0;
}	
List& List::operator=(List &&l){//присваивание перемещением, аналогично конструктору копии
	if(this==&l)
               	return *this;
	GoToBegin();
	Clean();
	base=l.base;
	cur=l.cur;
	l.base=0;
	l.cur=0;
	return *this;
}
List& List::operator=(const List&l){//перегрузка присваивания  копированием
	if(this==&l)
		return *this;
	GoToBegin();
	Clean();
	base=new Node();
	base->next=base;
	cur=base;
	Node *cur0=base;
	for(iterator it=l.Begin();it!=l.End();++it){
		Ins(*it);
		GoToNext();
		if(it.cur==l.cur)
			cur0=cur;
	}
	cur=cur0;
	return *this;
}	

//_____________________List дополнительные методы
int List::swap(){ //меняем местами(если возможно) следующий с тем, 
//который является следующим для следующего, например, для списка
// ... 1 2 3 4 5 , где текущий -- 1, результатом будет ....1 3 2 4 5
	if(cur->next==base||cur->next->next==base)
		return 0; //base перемещать не будем
	Node *tmp=cur->next; //запомнили узел с 2 
	cur->next=cur->next->next; // вырезали 2,  .. 1 3 4 5   
	tmp->next=cur->next->next; //за 2 должна следовать 4
	cur->next->next=tmp;//вклеиваем за 3 готовый узел с 2, получаем 1 3 2 4 5
	return 1;
}
List::Node* List::del(){ //в отличие от Del не очищает память, используется, если вырезанный узел будет куда-то вставлен
//удаляет следующий элемент, т.е.  next
	Node *tmp=cur->next;//запомним указатель на следующий
	cur->next=cur->next->next;//объявляем, что теперь следующим будет next->next
	return tmp; //в случае успеха возвращаем 1
}
void List::ins(List::Node *tmp){ //вставка узла происходит рядом (справа) с текущим
//в отличие от Ins память не выделяется, и должна быть выделена перед вызовом
	tmp->next=cur->next;//следующим для tmp будет next
	cur->next=tmp; //вклеиваем новый узел в список
}
int List::swap1(){ //то же, что swap + переход к следующему 
//используем del, ins
	if(cur->next==base||cur->next->next==base)
		return 0; //base перемещать не будем
	Node *tmp=del();
	GoToNext();
	ins(tmp);	
	return 1;
}
void List::foo(){ //функция циклического сдвига списка, при этом текущий элемент встает на первое место
 	Node *cur0=cur,*tmp;//запомним позицию текущего
	while(cur->next!=base) 
		GoToNext();//переход к последнему элементу списка
	tmp=del();//вырежем base
	cur=cur0;//вернемся к текущему
	ins(tmp); //вставляем base после текущего
}
void List::sort(){//сортировка списка методом пузырька
	int flag=1;//флаг для того, чтобы проверить, нужно ли сортировать
	while(flag){
		for(GoToBegin();cur->next!=base&&cur->next->next!=base;){//пустой список и список из одного элемента счортировать не надо
			if(cur->next->v>cur->next->next->v){//сравниваем 2 соседних элемента
				flag=0;//в случае, когда это необходимо, меняем флаг на проривоположный
				swap1(); //меняем порядок следования соседних элементов
			}
			GoToNext(); //если элементы стоят в правильном порядке, переходим к следующему
		}
		if(flag) //если при проходе пузырька не встетилось неупорядоченной пары 
			break;   //список отсортирован
		flag=1;//иначе будем делать еще проход пузырька
	}
}
//______________________________Итератор____________
List::iterator::iterator(const List *l){
	this->l=const_cast<List *>(l);//преобразование из const List * в List *
	this->cur=l->base->next; //встаем в начало списка
}
	
T & List::iterator::operator*(){
	return cur->v;

}
List::iterator & List::iterator::operator ++(void){ // ++it
		cur=cur->next;
		return *this;
}
int List::iterator:: operator !=(Node *node){
		if(cur!=node)
			return 1;
		return 0;
}
//_____________________
ostream & operator<<(ostream &cout,const List &m){
 	for(auto it=m.Begin();it!=m.End();++it)
		cout<<*it<<" ";
	cout<<"\n";
	return cout;
}
