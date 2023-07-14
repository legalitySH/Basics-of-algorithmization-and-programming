#pragma once 


struct Element
{
	Element* Head;
	Element* Prev;              
	Element* Next;            
	void* Data; 


	Element(Element* prev, void* data, Element* next)
	{
		Prev = prev;
		Data = data;
		Next = next;
		Head = NULL;
	}

	Element* GetNext()            // получить следующий
	{
		return Next;
	};


	Element* GetPrev()            // получить предыдущий  
	{
		return Prev;
	};
	Element* GetLast() {
		Element* temp = Head;
		if (!temp) {
			return NULL;    // если список пустой
		}
		while (temp->Next) {    // ищем последний элемент
			temp = temp->Next;
		}
		return temp;    // возвращаем указатель на последний элемент
	}
	void* GetData()           
	{
		return Data;
	}
};








struct Object                     // Блок управления списком 
{
	Element* Head;                 // указатель на начало списка
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // получить первый элемент списка
	{
		return Head;
	};
	Element* GetLast() {
		if (Head == NULL)
		{
			return NULL;
		}
		Element* ptr = Head;
		while (ptr->Next != NULL)
		{
			ptr = ptr->Next;
		}
		return ptr;
	}


	Element* Search(void* data, bool (*compareFunc)(void*, void*));   // найти  первый элемент по данным 
	bool Insert(void* data);       // добавить элемент в начало
	bool InsertEnd(void* data);    // добавить в конец 
	bool Delete(Element* e);       // удалить по адресу элемента 
	void DeleteList(Object List);// очистить список 
	void PrintList(void (*f)(void*));
	int CountList();

	Object Create();
};

