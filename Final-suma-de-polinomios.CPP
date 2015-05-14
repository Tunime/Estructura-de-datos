#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

struct nodo
{
	float num;
   int exp;
   nodo *sig;
};
nodo *crear(nodo *p);
void recorre(nodo *p);
void suma(nodo *p, nodo¨*q);

void main(void)
{
	nodo *p,*q;
   int op;
   char opc;
   p=NULL;
   q=NULL;

   	clrscr();
   	cout<<"Leyendo el polinomio A(x)... ";
   	do
   	{
   			p=crear(p);
            clrscr();
   			gotoxy(25,25);
   			cout<<"MAS TERMINOS PARA EL POLINOMIO (S/N))?... ";
  		   	cin>>opc;
   	}while(opc=='s'||opc=='S');


   	clrscr();
   	gotoxy(15,5);cout<<"Leyendo el polinomio B(x)... ";
   	do
   	{
   		q=crear(q);
         clrscr();
   		gotoxy(25,25);
   		cout<<"MAS TERMINOS PARA EL POLINOMIO (S/N))?... ";
   		cin>>opc;
   	}
   	while(opc=='s'||opc=='S');
      recorre(p);
   	recorre(q);
      suma(p,q);
      getch();


}



nodo *crear(nodo *p)
{
	nodo *j,*x;
	j=p;
	x=new(nodo);
	gotoxy(10,10);
	cout<<"COEFICIENTE  : ";cin>>x->num;
	gotoxy(10,12);
	cout<<"EXPONENTE    : ";cin>>x->exp;
   x->sig=j;
   j=x;
	return(j);
}
void recorre(nodo *p)
{
	nodo *j;
   j=p;
		while(j!=NULL)
		{
			cout<<j->num;
			cout<<j->exp;
			j=j->sig;
		}
}
void suma(nodo *p, nodo¨*q)
{



}


















