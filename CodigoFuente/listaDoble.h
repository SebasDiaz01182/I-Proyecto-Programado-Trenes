
#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(string v)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
    }

nodo(string v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }
    string valor;
    nodo *siguiente;
    nodo *anterior;
    
        
   friend class listaD;
};

typedef nodo *pnodo;

class listaD {
   public:
    listaD() { primero = NULL; }
    ~listaD();
    
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    int largoLista();
    pnodo primero;
  
};

listaD::~listaD()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   
}

int listaD::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void listaD::InsertarInicio(string v)
{
   if (ListaVacia()){
   	primero = new nodo(v);
   }
   else
   {
   	pnodo aux= primero;
   	primero=new nodo(v,primero);
   	aux->anterior=primero;
   }
   
}

void listaD::InsertarFinal(string v)
{
	if (ListaVacia()){
		primero= new nodo(v);
	}
	else
	{
		pnodo aux=primero
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		nuevo=new nodo(v);
		aux->siguiente=nuevo;
		nuevo->anterior=aux:
		
	}
}
void listaD::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}

