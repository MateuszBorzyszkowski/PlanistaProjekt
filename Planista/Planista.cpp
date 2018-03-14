#include <iostream>

using namespace std;

struct lista
{
	lista *next;
	int id;
};

class lista_cykliczna
{
private:
	lista *S;

public:
	lista_cykliczna(); //konstruktor
	~lista_cykliczna(); //destruktor

	void push(int v); // dodanie
	bool pop_t(int v); //usuwanie t
	void pop(void); //usuwanie
	void wypisz(void); //wypisz
	bool przesun(void); // przzesuwa wskaznik
};

lista_cykliczna::lista_cykliczna()
{
	S = NULL;
}

lista_cykliczna::~lista_cykliczna()
{
	while (S) pop();
}

void lista_cykliczna::push(int v) //dodanie
{
	lista *e = new lista;
	lista *b = new lista;

	e->id = v;


	if (S)
	{
		e->next = S;
		b = S;
		while (b->next != S)
		{
			b = b->next;	
		}
		b->next = e;
	}
	else
	{
		e->next = e;
		S = e;
	}

	
}

void lista_cykliczna::pop(void) //usuwanie
{
	if (S)
	{
		lista *e = S->next;
		S->next = e->next;
		if (e->next == e) S = NULL;
		delete e;
	}
}

bool lista_cykliczna::pop_t(int v) //usuwanie
{
	lista *b = new lista;
	lista *e = new lista;

	if (S) // czy lista jest pusta
	{
		if (S->id == v) // sprawdzam czy pierwszy element jest podana dana
		{
			if (S == S->next) // sprawdzam czy jest tam tylko jeden element
			{
				e = S;
				delete e;
				S = NULL;
				return true;
			}
			else
			{
				b = S;
				e = S;
				while (e->next->id != v)
				{
					e = e->next;
				}
				S = S->next;
				e->next = S;
				delete b;
				
				return true;
			}
		}
		else // inny niz pierwszy element to podana dana
		{
			b = S;
			while (b->next != S)
			{
				if (b->next->id == v) // sprawdzam nastepnik czy to podana dana
				{
					e = b->next;
					b->next = e->next;
					delete e;
					return true;
				}
				else
				{
					b = b->next;
				}
			}
			return false;
		}
	}
	return false;
}

bool lista_cykliczna::przesun(void)
{ 
	if (S)
	{
		cout << S->id << endl;
		S = S->next;
		return true;
	}
	else
	{
		return false;
	}
}

void lista_cykliczna::wypisz(void) //wypisz
{
	lista *e = S;

	if (e)
	do
	{
		cout << e->id << " ";
		e = e->next;
	} while (e != S);
}

// Program główny
int main()
{
	lista_cykliczna jeden;
	lista_cykliczna zero;
	lista_cykliczna minus;


	char znak;
	int id, priorytet;

	cin >> znak;

	while (cin.good())/*!feof(stdin)*/
	{
		

		switch (znak)
		{
		case 'n': //przesuniencie wskaznika
			if (!jeden.przesun())
			{
				if (!zero.przesun())
				{
					if (!minus.przesun())
					{
						cout << "idle" << endl;
					}
				}
			}
			
			break;
		case 'c': //utworzenie procesu
			cin >> id;
			cin >> priorytet;
			if (priorytet == 1) jeden.push(id);
			if (priorytet == 0) zero.push(id);
			if (priorytet == -1) minus.push(id);
			break;
		case 't': //zakończenie zadania
			cin >> id;
			if (!jeden.pop_t(id)) {
				if (!zero.pop_t(id)) {
					if (!minus.pop_t(id)) {
					}
				}
			}
			break;
		case 'p': //zmiana priorytetu
			cin >> id;
			cin >> priorytet;
			if (!jeden.pop_t(id)) {
				if (!zero.pop_t(id)) {
					if (!minus.pop_t(id)) {
					}
				}
			}
			if (priorytet == 1) jeden.push(id);
			if (priorytet == 0) zero.push(id);
			if (priorytet == -1) minus.push(id);
			break;
		case 'l': //lista zadań
			cout << "1: "; jeden.wypisz();
			cout << endl << "0: "; zero.wypisz();
			cout << endl << "-1: "; minus.wypisz();	
			cout << endl;
			break;
		default:
			break;
		}
		cin >> znak;
	}

	return 0;
}