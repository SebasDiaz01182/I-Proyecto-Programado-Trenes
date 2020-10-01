#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v)
    {
       valor = v;
       siguiente = NULL;
    }

nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo *siguiente;
    
        
   friend class listaC;
};

typedef nodo *pnodo;

class listaC {
   public:
    listaC() { primero =  NULL; }
    ~listaC();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void ConvertirCircular();
    
   private:
    pnodo primero;
    
};

listaC::~listaC()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   
}

int largoLista(const Node *aux)
{
int count = 0;
while (aux) {
count++;
aux = aux->next;
}
return count;
}

void listaC::InsertarInicio(int v)
{
	if (ListaVacia()){
		primero=new nodo(v);
	}
	else{
		primero=new nodo(v,primero);
	}
   
}
 
void listaC::InsertarFinal(int v)
{
	pnodo aux;
	aux=primero->siguiente;
	if(ListaVacia()){
		primero=new nodo(v,primero);
	}
	else{
		while(aux!=primero){
		aux=aux->siguiente;
	}
	
	}
	
}


void listaC::InsertarPos(int v,int pos){ 
	if (ListaVacia()){
		 primero = new nodo(v);
	}
   else{
        if(pos <=1){
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else{
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void listaC::BorrarFinal()
{
   
}

void listaC::BorrarInicio()
{
   
}

void listaC:: borrarPosicion(int pos)
{
}
 
void listaC::Mostrar(){
   pnodo aux;
   aux=primero;
   if(primero==NULL){
   	cout<<"La lista esta vacia"<<endl;
   }
   	else{
   		do{
		   cout<<aux->valor<<"->";
   			aux=aux->siguiente;
		   }while(aux!=primero);
   			
	   }
   
}
void listaC::ConvertirCircular(){
	if (primero==NULL){
		cout<<"La lista esta vacia"<<endl;
	}
	else{
		pnodo aux;
		aux=primero;
		while (aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux=primero;
	}
}   

