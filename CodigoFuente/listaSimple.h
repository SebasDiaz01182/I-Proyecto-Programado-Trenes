#include <iostream>
using namespace std;
//TDA Tipo abstracto de datos, no pertenece al lenguaje, sin embargo cuando el programador lo define se puede empezar a utilizar
class nodo { //Clase Nodo
	
   public:
    nodo(int v) // Tiene diferente cantidad de parametros, diferente tipo. Mismo nimbre de la clase
    {
       valor = v;
       siguiente = NULL;
    }

nodo(int v, nodo * signodo) // Comparte la direccion de memoria
    {
       valor = v;
       siguiente = signodo;
    }

   private: // Atributo
    int valor; // Valor entero
    nodo *siguiente; // Tipo de clase, autoreferencia
    
        
   friend class lista; //Permite que se compartan los metodos
};

typedef nodo *pnodo;  // Alias, redefinir los punteros

class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
    pnodo actual;
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int lista::largoLista(){
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

void lista::InsertarInicio(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
     primero->siguiente=primero;
   else
   { pnodo aux2=primero;
   while (aux2->siguiente!=primero){
   	aux2=aux2->siguiente
   }
     primero=new nodo (v,primero);
     aux2->siguiente=primero
   }
     
}
 
void lista::InsertarFinal(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}


void lista::InsertarPos(int v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else{
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v); // Crea el nodo
             nuevo->siguiente=aux->siguiente;  // Enlaza el nodo con el siguiente(dirección)
             aux->siguiente=nuevo;  // Se acomoda las direcciones anteriores
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                pnodo temp= primero;
                primero= NULL;
                delete temp;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}
dafd av
void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                pnodo temp= primero;
                primero= NULL;
                delete temp;
            } else {

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}


void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
        }
     }

}
 

void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos";  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

void lista::Primero()
{
   actual = primero;
}

void lista::Ultimo()
{
   actual = primero;  
   if(!ListaVacia()) 
      while(actual->siguiente) Siguiente();
}

