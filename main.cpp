#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;
int find(int n);
void printNumber(int n);
int main(int argc, char *argv[])
{
	int n = 0;
	if(argc == 2)
		n = atoi(argv[1]);
	else
	{
		cout << "Użycie: ./lab4 n" << endl;
	}

	int k = 0;
	k = find(n);

	if(k == 0)
		cout << "Nie udało się odnaleźć odpowiedniego k :(" << endl;
	else
	{
		cout << "Znalezione k to ";
		printNumber(k);
		cout << endl << endl;
		printNumber(n);
		cout << "razy ";
		printNumber(k);
		cout << "daje w wyniku ";
		if(k*n < 1000000)//program nie drukuje większych liczb
			printNumber(k*n);
		else
			cout << "więcej niż milion";
		cout << endl;
	}
}

void printNumber(int n)
{
	string ones[] = {"","jeden ","dwa ","trzy ","cztery ","pięć ","sześć ","siedem ","osiem ","dziewięć "};
	string teens[] = {"","jedenaście ", "dwanaście ", "trzynaście ", "czternaście ", "piętnaście ", "szesnaście ", "siedemnaście ", "osiemnaście ", "dziewiętnaście "};
	string tens[] = {"","dziesięć ", "dwadzieścia ", "trzydzieści ", "czterdzieści ", "pięćdziesiąt ", "sześćdziesiąt ", "siedemdziesiąt ", "osiemdziesiąt ","dziewięćdziesiąt " };
	string hundreds[] = {"", "sto ", "dwieście ", "trzysta ", "czterysta ", "pięćset ", "sześćset ", "siedemset ", "osiemset ", "dziewięćset "};

	int digits[] = {0,0,0,0,0,0};
	int nCopy = n;	
	for (int i = 5; i >= 0; i--)
	{
		digits[i] = nCopy%10;
		nCopy /= 10;
	} 
	//drukowanie pierwszych trzech cyfr
	if(n >= 1000)
	{
		if(digits[0]==0 && digits[1]==0 && digits[2] == 1)
			cout << "tysiąc ";
		else
		{
			cout << hundreds[digits[0]];
			if (digits[1] == 1 && digits[2] != 0)//jeżeli cyfra dziesiątek(tysięcy) jest równa 1, a cyfra jedności(tysięcy) jest równa 0 
			{
				cout << teens[digits[2]];
				cout << "tysięcy ";
			}
			else
			{
				cout << tens[digits[1]];
				cout << ones[digits[2]];
				if((digits[2] == 2 || digits[2] == 3 || digits[2] == 4))//'tysiące' tylko dwa, trzy lub cztery, inaczej 'tysięcy', polska język trudna język
					cout << "tysiące ";
				else
					cout << "tysięcy ";
			}
		}	
	}
	//drukowanie od cyfry czwartej do szóstej
	cout << hundreds[digits[3]];
	if (digits[4] == 1 && digits[5] != 0)
	{
		cout << teens[digits[5]];
	}
	else
	{
		cout << tens[digits[4]];
		cout << ones[digits[5]];
	}
}

int find(int n)
{
	int i = 1;
	unsigned long int check=0;
	for(; i < 1023; i++)//I hope it will fit in int!
	{
		bitset<20> bin (i);
		check = stoi(bin.to_string<char,std::string::traits_type,std::string::allocator_type>());//najprostszy sposób na konwersję liczby na binarną
		if(check%n==0)
			return check/n;
	}
	return 0;
}
