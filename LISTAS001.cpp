#include<iostream.h>
#include<conio.h>

struct nodo
{
	char nomb[15];
   nodo *sig;
};

nodo *crea_i(nodo *p);
nodo *crea_f(nodo *p);
void recorre(nodo *p);
nodo *ins_i(nodo *p);
nodo *ins_f(nodo *p);
nodo *ins_a(nodo *p);
void ins_d(nodo *p);
nodo *elim_p(nodo *p);
nodo *elim_u(nodo *p);
nodo *elim_x(nodo *p);

void main(void)
{
	nodo *p=NULL;
   char ref[15];
   int op;

   do
   {
      clrscr();
   	gotoxy(15,2);cout<<"M  E  N  U";
    	gotoxy(15,3);cout<<"==========";
      gotoxy(5,4);cout<<"1. Crear por el inicio";
      gotoxy(5,6);cout<<"2. Crear por el final";
      gotoxy(5,8);cout<<"3. Insertar al inicio...";
      gotoxy(5,10);cout<<"4. Insertar al final...";
      gotoxy(5,12);cout<<"5. Insertar antes de ...";
      gotoxy(5,14);cout<<"6. Insertar despues de ...";
      gotoxy(5,16);cout<<"7. Eliminar primer dato...";
      gotoxy(5,18);cout<<"8. Eliminar último dato...";
      gotoxy(5,20);cout<<"9. Eliminar un nodo";
      gotoxy(5,22);cout<<"10. Mostrar datos...";
      gotoxy(5,24);cout<<"11. S a l i r";
      gotoxy(25,29);cout<<"Elija opcion: ";cin>>op;
      switch(op)
      {
      	case 1:
            p=crea_i(p);
         	break;
         case 2:
            p=crea_f(p);
         	break;
         case 3:
         	p=ins_i(p);
         	break;
         case 4:
         	p=ins_f(p);
         	break;
         case 5:
         	p=ins_a(p);
         	break;
         case 6:
         	ins_d(p);
         	break;
         case 7:
         	p=elim_p(p);
         	break;
         case 8:
         	p=elim_u(p);
         	break;
         case 9:
         	p=elim_x(p);
         	break;
      	case 10:
         	recorre(p);
         	break;
      }
   }
   while(op>0&&op<11);
}
nodo *crea_i(nodo *p)
{
     nodo *q;
     char opc;
     do
     {
      q=new(nodo);
      cin>>q->nomb;
      q->sig=p;
      p=q;
      cout<<"mas datos ? ";
      cin>>opc;
     }
     while(opc=='s'||opc=='S');
     return(p);
}










