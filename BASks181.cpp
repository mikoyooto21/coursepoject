#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <cstdio>



using namespace std;
struct data
{
	
	int day;
	int month;
	int year;
	
};

struct fio
{
	
	string f;
	string i;
	string o;
	
};

struct assort
{
	
	string marka;
	fio pib;
	data dat;
	double probig;
	string collor;
	
};

void In_dani (assort as[], int* n);
void Out_dan (assort as[], int* n);	
void Sort1 (assort as[], int* n);		
void Add_rec(assort as[], int* n);		
void P1 (assort as[], int* n);			
void Sort2 (assort as[], int* n);		
void P2 (assort as[], int* n);	
void Sort3 (assort as[], int* n);	
void P3 (assort as[], int* n);


int main ()
{
	setlocale(0, "");
 SetConsoleCP(1251);  //установка кодовой страницы win-cp 1251 в поток вво-да
 SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в по-ток вывода
   
   int punkt;  //номер пункта меню
   int n(0);
   assort as[100];
   int vidp;
   
   
   while (true)
   {system ("cls");
   cout<<endl<<"        Головне меню";
   cout<<endl<<"  1. Завантаження даних";
   cout<<endl<<"  2. Ведення даних";
   cout<<endl<<"  3. Додавання нових даних";
   cout<<endl<<"  4. Виведення списку наявних автомобілів";
   cout<<endl<<"  5. Виведення даних про автомобілі, пробіг яких не перевищує вказаного значення";
   cout<<endl<<"  6. Виведення даних про автомобілі вказаного власника";
   cout<<endl<<"  7. Вихід з програми ";
   cout<<endl<<endl<<"  Виберіть пункт меню   \n  "; 
   cin>>punkt;
   switch (punkt)
   {
   case 1: {In_dani(as, &n); system ("pause"); break; }
   				
   case 2: {system ("cls"); Sort1(as,&n); Out_dan (as,&n); system ("pause"); break; }
   				
   case 3: {system ("cls"); Add_rec (as,&n); system ("pause"); break; }
   				
   case 4: {system ("cls");  P1 (as,&n); system ("pause"); break; }
   case 5: {system ("cls");  Sort2(as,&n);  P2 (as,&n);	system ("pause"); break; }

   case 6: {system ("cls");  P3 (as,&n); system ("pause"); break; }
    
	default : {system ("cls");cout<<endl<<"   Неправильно обраний пункт меню   ";system ("pause"); break; }

   case 7: {system ("cls");
    cout<<endl<<"  Вихід з програми  \n";
    cout<<endl<<"  Чи ви дійсно хочете вийти з програми? \n";
    cout<<endl<<"  Так(1)                  Ні(2)      \n  ";
	cin>>vidp;
	switch(vidp)
	{
	 case 1:	
	 {
	 system("cls");
	 cout<<endl<<"   Програма завершує роботу   "; system("pause"); return 0;
     }
     case 2:{ vidp==2; system("cls"); system ("pause"); break;}
     
     default : {system ("cls"); cout<<endl<<"   Неправильно обраний пункт меню. Повернення до меню.   ";
    system ("pause"); }
	}
	}
	
   
	
    }
}
} 

void In_dani (assort as[], int* n)
{
	
	system ("cls");
	int k(0); //индекс переменной массива
	string s;
	fstream f;
	f.open ("F:dani.txt", ios::in);
	cout<<endl<<"  Завантаження даних "<<endl<<endl;
	system ("cls");
	if(!f.is_open())
	{
		cout<<endl<<"  Помилка відкриття файлу"; return;
	}
	else
	{	
		
		const char* c_inp;
		while(! f.eof() )
   {
		
		getline(f,s); as[k].marka=s;
		getline(f,s); as[k].pib.f=s;
		getline(f,s); as[k].pib.i=s;
		getline(f,s); as[k].pib.o=s;
		getline(f,s); c_inp=s.c_str(); as[k].dat.day=atoi(c_inp);
		getline(f,s); c_inp=s.c_str(); as[k].dat.month=atoi(c_inp);
		getline(f,s); c_inp=s.c_str(); as[k].dat.year=atoi(c_inp);
		getline(f,s); const char* c_inp = s.c_str(); as[k].probig=atof(c_inp);
		getline(f,s); as[k].collor=s;
		 k++;
	}
	f.close();
	*n=k;
	cout<<endl<<"  Перегляд   "<<endl;
	if(*n==0)
	cout<<endl<<endl<<"  Файл даних пустий"<<endl;
	else
	for(int i=0; i<*n; i++)
	cout<<endl<<as[i].marka<<"  "<<as[i].pib.f<<"   "<<as[i].pib.i<<"   "<<as[i].pib.o<<"  "<<as[i].dat.day<<".  "<<as[i].dat.month<<".  "<<as[i].dat.year<<"  "<<as[i].probig<<"  "<<as[i].collor<<"  ";
	cout<<endl;
	
			return;
		}
}
	void Out_dan (assort as[], int* n)
{
	cout<<endl<<"       Асортимент автомобілів   "<<endl<<endl; 
	if (*n==0)
cout<<endl<<endl<<"Масив даних пустий"<<endl<<endl;
else
{ 
cout.setf(ios::left); cout.width(20); cout<<"Марка авто   ";
cout.setf(ios::left); cout.width(40); cout<<"Інніціали   ";
cout.setf(ios::left); cout.width(15); cout<<"Дата   ";
cout.setf(ios::left); cout.width(20); cout<<"Пробіг   ";
cout.setf(ios::left); cout.width(20); cout<<"Колір   "<<endl;
 cout<<endl;

 for (int i=0; i<*n; i++)
 {
cout.setf(ios::left); cout.width(20); cout<<as[i].marka;
cout.setf(ios::left); cout.width(10); cout<<as[i].pib.f<<" ";
cout.width(10); cout<<as[i].pib.i<<" ";
cout.width(20);cout<<as[i].pib.o;"   ";
cout.width(2);cout<<as[i].dat.day<<".";
cout.width(2);cout<<as[i].dat.month<<".";
cout<<as[i].dat.year<<"   ";
cout.setf(ios::left); cout.width(20);cout<<as[i].probig;
cout.setf(ios::left); cout.width(20); cout<<as[i].collor<<endl;
 
}
}
 return;
}

void Sort1 (assort as[], int* n)
{
int i,j;
assort t;
for (i=0; i<*n-1; i++)
for (j=0; j<=*n-2; j++)
if (as[j].marka > as[j+1].marka)
{
	t=as[j]; as[j]=as[j+1]; as[j+1]=t;
	
}
	return;		
}

void Add_rec(assort as[], int* n)
 {
 	char s[256];
	 fstream f;
 	f.open ("F:dani.txt", ios::app); 
 	char c('y'); 
 	int k; k=*n;
 	cout<<endl<<"   Додавання нових даних   "<<endl<<endl;
 	if (!f.is_open())
 	{
	 cout<<endl<<"   Відбулася помилка при відкритті файлу   "; return ;}
 	else
 	{ 	
 		while(c=='y')
	{
 		
 		cout<<endl<<"Введіть назву марки авто "; cin>>as[k].marka; f<<as[k].marka<<'\n';
 		if(char(cin.peek()) == '\n')     cin.ignore();
 		cout<<endl<<"Введіть прізвище та ініціали власника "<<endl;
		cout<<endl<<"Прізвище ";  cin.getline(s,256); as[k].pib.f=s; f<<as[k].pib.f<<'\n';
		cout<<endl<<"Ім'я ";  cin.getline(s,256);as[k].pib.i=s; f<<as[k].pib.i<<'\n';
		cout<<endl<<"По-батькові ";  cin.getline(s,256);as[k].pib.o=s; f<<as[k].pib.o<<'\n';
 		cout<<endl<<"Введіть рік випуску авто "<<endl;
 		cout<<endl<<"  День "; cin>>as[k].dat.day; f<<as[k].dat.day<<'\n';
 		cout<<endl<<"  Місяць "; cin>>as[k].dat.month; f<<as[k].dat.month<<'\n';
 		cout<<endl<<"  Рік "; cin>>as[k].dat.year; f<<as[k].dat.year<<'\n';
 		cout<<endl<<"Введіть пробіг авто "; cin>>as[*n].probig; f<<as[k].probig<<'\n';
		if(char(cin.peek()) == '\n')     cin.ignore();
		cout<<endl<<"Введіть колір авто "; cin.getline(s,256); as[k].collor=s; f<<as[k].collor<<'\n';
		 k++;
		cout<<endl<<"Ви хочете створити ще один запис у каталог? y/n "; 
		cin>>c;
	system ("cls");
	}
*n=k; 	
 }
 f.close();
 return;
}


void P1 (assort as[], int* n)
 {
 	string s;
 	int y;
 	int k(0);
 	cout<<endl<<"  	Виведення списку наявних автомобілів вказаної користувачем марки, рік випуску яких не менше вказаного користувачем;  "<<endl<<endl; 
	if (*n==0) cout<<endl<<endl<<"       Масив даних пустий"<<endl<<endl;
	else
	{
	
	if(char(cin.peek()) == '\n')     cin.ignore();
	cout<<endl<<"Введіть марку та рік випуску автомобіля   "; cin>>s; cin>>y;
	for (int i=0; i<*n; i++)
		if (as[i].marka==s&&as[i].dat.year>=y)
		{
			cout.setf(ios::left); cout.width(20); cout<<as[i].marka;
			cout.setf(ios::left); cout.width(1); cout<<as[i].pib.f<<" ";
			cout.width(1); cout<<as[i].pib.i<<" ";
			cout<<as[i].pib.o;"   ";
			cout.width(2);cout<<as[i].dat.day<<".";
			cout.width(2);cout<<as[i].dat.month<<".";
			cout<<as[i].dat.year<<"   ";
			cout.setf(ios::left); cout.width(20);cout<<as[i].probig;
			cout.setf(ios::left); cout.width(20); cout<<as[i].collor<<endl;
			k++;
		}
	
	if (k==0) cout<<endl<<"Автомобілі  "<<s<<"  "<<y<<"  року  випуску не існують у ассортименті"<<endl;
	}
	return;
}

void Sort2 (assort as[], int* n)
{
int i,j;
assort t;
for (i=0; i<*n-1; i++)
for (j=0; j<=*n-2; j++)
if (as[j].pib.f < as[j+1].pib.f)
{
	t=as[j]; as[j]=as[j+1]; as[j+1]=t;
	
}
	return;		
}

void P2 (assort as[], int* n)
{
	double s;
 	int k(0);
 	cout<<endl<<"  	Автомобілі з пробігом що не перевищує вказаного  "<<endl<<endl; 
	if (*n==0) cout<<endl<<endl<<"       Масив даних пустий"<<endl<<endl;
	else
	{
	
	if(char(cin.peek()) == '\n')     cin.ignore();
	cout<<endl<<"Введіть бажаний пробіг автомобіля   "; cin>>s;
	for (int i=0; i<*n; i++)
		if (as[i].probig<=s)
		{
			cout.setf(ios::left); cout.width(20); cout<<as[i].marka;
			cout.setf(ios::left); cout.width(12); cout<<as[i].pib.f<<" ";
			cout.width(12); cout<<as[i].pib.i<<" ";
			cout.width(12);cout<<as[i].pib.o;"   ";	
			cout.width(2);cout<<as[i].dat.day<<".";
			cout.width(2);cout<<as[i].dat.month<<".";
			cout<<as[i].dat.year<<"   ";
			cout.setf(ios::left); cout.width(20);cout<<as[i].probig;
			cout.setf(ios::left); cout.width(20); cout<<as[i].collor<<endl;
			k++;
		}
		if (k==0) cout<<endl<<"Автомобілі  з пробігом нижче вказного не існують у ассортименті"<<endl;
}
		return;
	
}

void P3 (assort as[], int* n)
{
	string s;
 	int k(0);
 	cout<<endl<<"  	Автомобілі за вказаним власником  "<<endl<<endl; 
	if (*n==0) cout<<endl<<endl<<"       Масив даних пустий"<<endl<<endl;
	else
	{
	
	if(char(cin.peek()) == '\n')     cin.ignore();
	cout<<endl<<"Введіть власника автомобіля   "; cin>>s;
	for (int i=0; i<*n; i++)
		if (as[i].pib.f==s||as[i].pib.i==s||as[i].pib.o==s)
		{
			cout.setf(ios::left); cout.width(20); cout<<as[i].marka;
			cout.width(1); cout<<as[i].pib.f<<" ";
			cout.width(1); cout<<as[i].pib.i<<" ";
			cout<<as[i].pib.o;"   ";
			cout.width(2);cout<<as[i].dat.day<<".";
			cout.width(2);cout<<as[i].dat.month<<".";
			cout<<as[i].dat.year<<"   ";
			cout.setf(ios::left); cout.width(20);cout<<as[i].probig;
			cout.setf(ios::left); cout.width(20); cout<<as[i].collor<<endl;
			k++;
		}
		if (k==0) cout<<endl<<"Автомобілі  з заданим власником не існують у ассортименті"<<endl;
}
		return;
}
