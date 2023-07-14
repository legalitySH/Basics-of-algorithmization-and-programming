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

	Element* GetNext()            // �������� ���������
	{
		return Next;
	};


	Element* GetPrev()            // �������� ����������  
	{
		return Prev;
	};
	Element* GetLast() {
		Element* temp = Head;
		if (!temp) {
			return NULL;    // ���� ������ ������
		}
		while (temp->Next) {    // ���� ��������� �������
			temp = temp->Next;
		}
		return temp;    // ���������� ��������� �� ��������� �������
	}
	void* GetData()           
	{
		return Data;
	}
};








struct Object                     // ���� ���������� ������� 
{
	Element* Head;                 // ��������� �� ������ ������
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // �������� ������ ������� ������
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


	Element* Search(void* data, bool (*compareFunc)(void*, void*));   // �����  ������ ������� �� ������ 
	bool Insert(void* data);       // �������� ������� � ������
	bool InsertEnd(void* data);    // �������� � ����� 
	bool Delete(Element* e);       // ������� �� ������ �������� 
	void DeleteList(Object List);// �������� ������ 
	void PrintList(void (*f)(void*));
	int CountList();

	Object Create();
};

