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
 SetConsoleCP(1251);  //��������� ������� �������� win-cp 1251 � ����� ���-��
 SetConsoleOutputCP(1251); //��������� ������� �������� win-cp 1251 � ��-��� ������
   
   int punkt;  //����� ������ ����
   int n(0);
   assort as[100];
   int vidp;
   
   
   while (true)
   {system ("cls");
   cout<<endl<<"        ������� ����";
   cout<<endl<<"  1. ������������ �����";
   cout<<endl<<"  2. ������� �����";
   cout<<endl<<"  3. ��������� ����� �����";
   cout<<endl<<"  4. ��������� ������ ������� ���������";
   cout<<endl<<"  5. ��������� ����� ��� ��������, ����� ���� �� �������� ��������� ��������";
   cout<<endl<<"  6. ��������� ����� ��� �������� ��������� ��������";
   cout<<endl<<"  7. ����� � �������� ";
   cout<<endl<<endl<<"  ������� ����� ����   \n  "; 
   cin>>punkt;
   switch (punkt)
   {
   case 1: {In_dani(as, &n); system ("pause"); break; }
   				
   case 2: {system ("cls"); Sort1(as,&n); Out_dan (as,&n); system ("pause"); break; }
   				
   case 3: {system ("cls"); Add_rec (as,&n); system ("pause"); break; }
   				
   case 4: {system ("cls");  P1 (as,&n); system ("pause"); break; }
   case 5: {system ("cls");  Sort2(as,&n);  P2 (as,&n);	system ("pause"); break; }

   case 6: {system ("cls");  P3 (as,&n); system ("pause"); break; }
    
	default : {system ("cls");cout<<endl<<"   ����������� ������� ����� ����   ";system ("pause"); break; }

   case 7: {system ("cls");
    cout<<endl<<"  ����� � ��������  \n";
    cout<<endl<<"  �� �� ����� ������ ����� � ��������? \n";
    cout<<endl<<"  ���(1)                  ͳ(2)      \n  ";
	cin>>vidp;
	switch(vidp)
	{
	 case 1:	
	 {
	 system("cls");
	 cout<<endl<<"   �������� ������� ������   "; system("pause"); return 0;
     }
     case 2:{ vidp==2; system("cls"); system ("pause"); break;}
     
     default : {system ("cls"); cout<<endl<<"   ����������� ������� ����� ����. ���������� �� ����.   ";
    system ("pause"); }
	}
	}
	
   
	
    }
}
} 

void In_dani (assort as[], int* n)
{
	
	system ("cls");
	int k(0); //������ ���������� �������
	string s;
	fstream f;
	f.open ("F:dani.txt", ios::in);
	cout<<endl<<"  ������������ ����� "<<endl<<endl;
	system ("cls");
	if(!f.is_open())
	{
		cout<<endl<<"  ������� �������� �����"; return;
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
	cout<<endl<<"  ��������   "<<endl;
	if(*n==0)
	cout<<endl<<endl<<"  ���� ����� ������"<<endl;
	else
	for(int i=0; i<*n; i++)
	cout<<endl<<as[i].marka<<"  "<<as[i].pib.f<<"   "<<as[i].pib.i<<"   "<<as[i].pib.o<<"  "<<as[i].dat.day<<".  "<<as[i].dat.month<<".  "<<as[i].dat.year<<"  "<<as[i].probig<<"  "<<as[i].collor<<"  ";
	cout<<endl;
	
			return;
		}
}
	void Out_dan (assort as[], int* n)
{
	cout<<endl<<"       ���������� ���������   "<<endl<<endl; 
	if (*n==0)
cout<<endl<<endl<<"����� ����� ������"<<endl<<endl;
else
{ 
cout.setf(ios::left); cout.width(20); cout<<"����� ����   ";
cout.setf(ios::left); cout.width(40); cout<<"��������   ";
cout.setf(ios::left); cout.width(15); cout<<"����   ";
cout.setf(ios::left); cout.width(20); cout<<"�����   ";
cout.setf(ios::left); cout.width(20); cout<<"����   "<<endl;
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
 	cout<<endl<<"   ��������� ����� �����   "<<endl<<endl;
 	if (!f.is_open())
 	{
	 cout<<endl<<"   ³������� ������� ��� ������� �����   "; return ;}
 	else
 	{ 	
 		while(c=='y')
	{
 		
 		cout<<endl<<"������ ����� ����� ���� "; cin>>as[k].marka; f<<as[k].marka<<'\n';
 		if(char(cin.peek()) == '\n')     cin.ignore();
 		cout<<endl<<"������ ������� �� ������� �������� "<<endl;
		cout<<endl<<"������� ";  cin.getline(s,256); as[k].pib.f=s; f<<as[k].pib.f<<'\n';
		cout<<endl<<"��'� ";  cin.getline(s,256);as[k].pib.i=s; f<<as[k].pib.i<<'\n';
		cout<<endl<<"��-������� ";  cin.getline(s,256);as[k].pib.o=s; f<<as[k].pib.o<<'\n';
 		cout<<endl<<"������ �� ������� ���� "<<endl;
 		cout<<endl<<"  ���� "; cin>>as[k].dat.day; f<<as[k].dat.day<<'\n';
 		cout<<endl<<"  ̳���� "; cin>>as[k].dat.month; f<<as[k].dat.month<<'\n';
 		cout<<endl<<"  г� "; cin>>as[k].dat.year; f<<as[k].dat.year<<'\n';
 		cout<<endl<<"������ ����� ���� "; cin>>as[*n].probig; f<<as[k].probig<<'\n';
		if(char(cin.peek()) == '\n')     cin.ignore();
		cout<<endl<<"������ ���� ���� "; cin.getline(s,256); as[k].collor=s; f<<as[k].collor<<'\n';
		 k++;
		cout<<endl<<"�� ������ �������� �� ���� ����� � �������? y/n "; 
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
 	cout<<endl<<"  	��������� ������ ������� ��������� ������� ������������ �����, �� ������� ���� �� ����� ��������� ������������;  "<<endl<<endl; 
	if (*n==0) cout<<endl<<endl<<"       ����� ����� ������"<<endl<<endl;
	else
	{
	
	if(char(cin.peek()) == '\n')     cin.ignore();
	cout<<endl<<"������ ����� �� �� ������� ���������   "; cin>>s; cin>>y;
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
	
	if (k==0) cout<<endl<<"��������  "<<s<<"  "<<y<<"  ����  ������� �� ������� � �����������"<<endl;
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
 	cout<<endl<<"  	�������� � ������� �� �� �������� ���������  "<<endl<<endl; 
	if (*n==0) cout<<endl<<endl<<"       ����� ����� ������"<<endl<<endl;
	else
	{
	
	if(char(cin.peek()) == '\n')     cin.ignore();
	cout<<endl<<"������ ������� ����� ���������   "; cin>>s;
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
		if (k==0) cout<<endl<<"��������  � ������� ����� �������� �� ������� � �����������"<<endl;
}
		return;
	
}

void P3 (assort as[], int* n)
{
	string s;
 	int k(0);
 	cout<<endl<<"  	�������� �� �������� ���������  "<<endl<<endl; 
	if (*n==0) cout<<endl<<endl<<"       ����� ����� ������"<<endl<<endl;
	else
	{
	
	if(char(cin.peek()) == '\n')     cin.ignore();
	cout<<endl<<"������ �������� ���������   "; cin>>s;
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
		if (k==0) cout<<endl<<"��������  � ������� ��������� �� ������� � �����������"<<endl;
}
		return;
}
