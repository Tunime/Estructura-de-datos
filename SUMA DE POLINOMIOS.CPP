#include <conio.h>
#include <iostream.h>

//formamos la estructura del nodo
struct nodo
{
	float num;
   int exp;
   nodo *sig;
};
//comensamos con  el cuerpo del programa
void main (void)
{
	clrscr();
   nodo *q , *p=NULL;
   char op;
   cout<<"SUMA DE POLINOMIOS 	\n";
   cout<<"INTRODUCE EL  POLINOMIO A(x)\n\n";
   do
   {
   	q=new(nodo);
      cout<<"NUMERO : ";
      cin>>q->num;
      cout<<"\n\n";
      cout<<"EXPONENTE : ";
      cin>>q->exp;
      q->sig=p;
      p=q;
      cout<<"\n\n\t MAS FACTORES S/N? ... ";
      cin>>op;
      clrscr();

   }while(op=='s'||op=='S');

   //comensamoa a crear la lita para el polinomia 2
   cout<<"INTRODUCE EL  POLINOMIO B(x)\n\n";
   //tener en cuenta que no estoy seguro si el p=NULL va fuera o dentro de  el do while
   nodo *y;
   nodo *x=NULL;
   do
   {

   	x=new(nodo);
      cout<<"NUMERO : ";
      cin>>y->num;
      cout<<"\n\n";
      cout<<"EXPONENTE : ";
      cin>>y->exp;
      y->sig=x;
      x=y;
      cout<<"\n\n\t MAS FACTORES S/N? ... ";
      cin>>op;
      clrscr();

   }while(op=='s'||op=='S');
   // se culmina la creacion de las listas
   //comnsamos a  suma y dar las condiciones

  q=p;
  y=x;
  float a;
  nodo *j,*k=NULL;

  do
  {
  		if(q->exp==y->exp)
      {
      	a=q->num+y->num;

         j=new(nodo);
      	j->num=a;
  			j->exp=q->exp;                                          
      	j->sig=k;
      	k=j;

         q=q->sig;
      }
      else
      {
      	y=y->sig;
      }
  }while(q!=NULL||y!=NULL);
}
