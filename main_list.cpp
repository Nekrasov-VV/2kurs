#include"list.h" 

int main(){
        List m;
	int n=9;
	for(int i=1;i<n;i++) {
		m.Ins(i); //загружаем в список объект
		m.GoToNext();//сдвигаемся по списку, чтобы сохранить порядок элементов (иначе порядок изменится на противоположный)
	}
	m.GoToBegin();//возвращаемся в начало
        while(m.GoToNext()) //печать списка
		cout<<"   "<<m.Get();
	cout<<"\n";
	m.GoToBegin();//опять встаем в начало, иначе дальше будет обрабатываться  пустой список
	while(m.swap())
		m.GoToNext();
// результат  -- циклический сдвиг списка на 1 позицию влево
	m.GoToBegin();
	while(m.GoToNext())
		cout<<"   "<<m.Get();
	cout<<"\n";
	return 0;
}