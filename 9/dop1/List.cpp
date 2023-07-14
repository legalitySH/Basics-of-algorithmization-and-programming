#include "stdafx.h"



Element* Object::Search(void* data, bool (*compareFunc)(void*, void*)) {
    Element* temp = Head;
    while (temp) {
        if (compareFunc(temp->Data, data)) {
            return temp;
        }
        temp = temp->Next;
    }
    return NULL;
}

bool Object::Insert(void* data)
{
    Element* temp = new Element(NULL, data, Head);
    if (!temp) {
        return false;
    }
    if (Head) {
        Head->Prev = temp;
    }
    Head = temp;
    return true;
}

bool Object::InsertEnd(void* data)
{
    Element* temp = new Element(GetLast(), data, NULL);
    if (!temp) {
        return false;
    }
    if (!Head) { 
        Head = temp; 
        return true;
    }
    Element* last = GetLast();
    last->Next = temp;
    return true;
}

bool Object::Delete(Element* e)       // удалить по адресу элемента 
{
    if (!e) {
        return false;
    }
    if (e == Head) {    
        Head = e->Next;
    }
    if (e->Prev) {    
        e->Prev->Next = e->Next;
    }
    if (e->Next) {    
        e->Next->Prev = e->Prev;
    }
    delete e;    
    return true;
}

void Object::DeleteList(Object List)
{
    Element* current = List.Head;
    while (current != NULL)
    {
        Element* next = current->GetNext();
        delete current;
        current = next;
    }
    List.Head = NULL;
}

void Object::PrintList(void (*f)(void*)) {
    Element* curr = Head;
    while (curr != NULL) {
        f(curr->GetData());
        curr = curr->GetNext();
    }
}

int Object::CountList()
{
    int count = 0;
    Element* current = Head;
    while (current != NULL)
    {
        count++;
        current = current->GetNext();
    }
    return count;
}

Object Object::Create()
{
    Object list;
    return list;
}
