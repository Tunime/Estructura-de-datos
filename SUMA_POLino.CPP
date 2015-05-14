#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

struct nodo
{
	float coef;
	int expo;
	nodo *next;
};
nodo *inserta_a(nodo *p);
void suma(nodo *p,nodo *q);
void recorre(nodo *p,int g);

void main(void)
{
	nodo *p,*q; //DECLARACION DE PUNTEROS
	int op,y=0;
	char opc;
	textcolor(WHITE); //color de texto
	textbackground(RED);//color de fondo
	p=NULL; //El puntero de cabecera apunta inicialmente a NULL
	q=NULL;
	do
	{
		clrscr();
		gotoxy(25,3);cout<<"M E N U ";
		gotoxy(25,5);cout<<"*******";
		gotoxy(20,7);cout<<"1. INSERTAR ";
		gotoxy(20,9);cout<<"2. MOSTRAR ";
		gotoxy(20,11);cout<<"3. SUMA ";
		gotoxy(20,13);cout<<"4. S A L I R ";
		gotoxy(30,19);cout<<"INGRESE OPCION.... ";
		cin>>op;
		switch(op)
		{
			case 1:
					clrscr();
					if(y==0)
					{
						y=1;
						clrscr();
						gotoxy(15,5);cout<<"Leyendo el polinomio P(x)... ";
						do
						{
							p=inserta_a(p);
							gotoxy(25,25);
							cout<<"MAS TERMINOS PARA EL POLINOMIO (S/N))?... ";
							cin>>opc;
						}
						while(opc=='s'||opc=='S');
					}
					else
					{
						clrscr();
						gotoxy(15,5);cout<<"Leyendo el polinomio Q(x)... ";
						do
						{
							q=inserta_a(q);
							gotoxy(25,25);
							cout<<"MAS TERMINOS PARA EL POLINOMIO (S/N))?... ";
							cin>>opc;
						}
						while(opc=='s'||opc=='S');
					}
					break;
			case 2:
					recorre(p,0);
					recorre(q,1);
					getch();
					break;
			case 3:
					clrscr();
					gotoxy(20,10);
					cout<<"	SUMA DE LOS POLINOMIOS .... ";
					suma(p,q);
					getch();
					break;
		}
	}
	while(op>0&&op<4);
}

nodo *inserta_a(nodo *p)
{
	nodo *j,*k,*x;
	int  cen;
	cen=0;
	j=p;
	x=new(nodo);
	gotoxy(10,10);
	cout<<"COEFICIENTE  : ";cin>>x->coef;
	gotoxy(10,12);
	cout<<"EXPONENTE    : ";cin>>x->expo;
	if(p==NULL)
	{
		x->next=NULL;
		p=x;
	}
	else
	{
		while(x->expo<j->expo&&cen==0)
			if(j->next!=NULL)
			{
				k=j;
				j=j->next;
			}
			else
				cen=1;
		if(cen==0)
		{
			if(p==j)
				p=x;
			else
				k->next=x;
			x->next=j;
		}
		else
		{
			x->next=NULL;
			j->next=x;
		}
	}
	return(p);
}
void suma(nodo *p,nodo *q)
{
	nodo *a,*x,*b,*s,*f;
	int v=0;
	s=NULL;
	a=p;
	b=q;
	while(a!=NULL&&b!=NULL)
	{
		if(a->expo==b->expo)
		{
			if(a->expo+b->expo!=0)
			{
				x=new(nodo);
				x->coef=a->coef+b->coef;
				x->expo=a->expo;
				a=a->next;
				b=b->next;
			}
			else
				v=1;
		}
		else
		{
			if(a->expo>b->expo)
			{
				x=new(nodo);
				x->coef=a->coef;
				x->expo=a->expo;
				a=a->next;
			}
			else
			{
				x=new(nodo);
				x->coef=b->coef;
				x->expo=b->expo;
				b=b->next;
			}
		}
		if(v==0)
		{
			x->next=NULL;
			if(s==NULL)
				s=x;
			else
				f->next=NULL;
			f=x;
		}
	}
	while(a!=NULL)
	{
		x=new(nodo);
		x->coef=a->coef;
		x->expo=a->expo;
		a=a->next;
		x->next=NULL;
		f->next=x;
		f=x;
	}
	while(b!=NULL)
	{
		x=new(nodo);
		x->coef=b->coef;
		x->expo=b->expo;
		b=b->next;
		x->next=NULL;
		f->next=x;
		f=x;
	}
	a=s;
	gotoxy(17,15);cout<<"P(x)+Q(x)= ";
	int w=0;
	while(a!=NULL)
	{
		gotoxy(23+8*w,15);
		if(a->coef>=0)
			cout<<" + ";
		if(a->expo!=0)
			cout<<a->coef<<"x^"<<a->expo;
		else
			cout<<a->coef;
		w=w+1;
		a=a->next;
	}
}
void recorre(nodo *p,int g)
{
	nodo *j;
	int h;
	if(g==0)
	{
		h=1;
		clrscr();
		gotoxy(10,5);cout<<"P(x)";
		gotoxy(5,10);cout<<"COEFICIENTE    EXPONENTE";
		gotoxy(5,12);cout<<"*************************";
		j=p;
		while(j!=NULL)
		{
			gotoxy(7,12+2*h);cout<<j->coef;
			gotoxy(17,12+2*h);cout<<j->expo;
			j=j->next;
			h=h+1;
		}
	}
	else
	{
		h=1;
		gotoxy(45,5);cout<<"Q(x)";
		gotoxy(35,10);cout<<"COEFICIENTE    EXPONENTE";
		gotoxy(35,12);cout<<"*************************";
		j=p;
		while(j!=NULL)
		{
			gotoxy(38,12+2*h);cout<<j->coef;
			gotoxy(53,12+2*h);cout<<j->expo;
			j=j->next;
			h=h+1;
		}
	}
}
