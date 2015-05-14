#include<conio.h>
#include<iostream.h>
#include<stdio.h>

struct nodo
{
	char codi[15],apel[35];
	float nota[3],prom;
	nodo *next;
};

void main(void)
{
	nodo *i,*j; //DECLARACION DE PUNTEROS
	char op;
	float sum;
	int h;
	textcolor(WHITE); //color de texto
	textbackground(RED);//color de fondo
	i=NULL; //El puntero de cabecera apunta inicialmente a NULL
	do
	{
		clrscr();
		j=new(nodo); //crea un nodo y lo apunta con j
		gotoxy(10,10);
		cout<<"CODIGO              :  "; cin>>j->codi;
		gotoxy(10,12);
		cout<<"APELLIDOS Y NOMBRES :  "; gets(j->apel);
		gotoxy(10,14);
		cout<<"NOTAS                ";
		sum=0;
		for(h=0;h<3;h++)
		{
			gotoxy(20,16+2*h);
			cout<<"NOTA "<<h+1<<"    :  ";
			cin>>j->nota[h];
			sum=sum+j->nota[h];
		}
		gotoxy(20,23);
		cout<<"PROMEDIO  :  ";
		j->prom=sum/3;
		gotoxy(33,23);
		cout<<j->prom;
		j->next=i;
		i=j;
		gotoxy(40,29);
		cout<<"MAS DATOS ? (S/N) ";
		cin>>op;
	}
	while(op=='s'||op=='S');
	clrscr();
	gotoxy(20,5);cout<<"REPORTE DE ALUMNOS APROBADOS";
	gotoxy(13,10);cout<<"CODIGO        APELLIDOS Y NOMBRES     PROMEDIO";
	gotoxy(13,12);cout<<"**********************************************";
	j=i;
	h=1;
	while(j!=NULL)
	{
		if(j->prom>=10.5)
		{
			gotoxy(14,12+2*h);cout<<j->codi;
			gotoxy(27,12+2*h);cout<<j->apel;
			gotoxy(50,12+2*h);cout<<j->prom;
			h=h+1;
		}
		j=j->next;
	}

	getch();
}