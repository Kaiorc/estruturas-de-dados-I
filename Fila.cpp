//Kaio Rodrigues

#include <iostream>

using namespace std;

class No{
	private:
		int valor;//Informação no Nó
		No* prox; //Aponta para o próximo Nó
    public:

    	No (int valor){

			this-> valor = valor;

			this-> prox = NULL;

		}



		int getValor(){

			return valor;

		}



		No* getProx(){

			return prox;

		}



		void setValor(int elemento){

			valor = elemento;

		}



		void setProx( No* p){

			prox = p;

		}

};



class Fila{

	private:

	  No* frente; //Nó na frente da Fila

	  No* tras; //Nó atrás da Fila



     public:

     	//Construtor

     	Fila(){

		   this->frente = NULL;

		   this->tras = NULL;

		 }

       //Verifica se a Fila está vazia

       bool isEmpty(){

		   if(frente == NULL){

			   return true;

		   } else{

			   return false;

		   }

	   }


       //Insere elemento na Fila

       void Enqueue(int info){

       	  No* novo = new No(info); // Criação de Nó que será inserido

       	  //Condição caso a Fila esteja Vazia

		  if(isEmpty()){

			frente = novo;

			tras = novo;

          //Condição caso a Fila não esteja vazia

		  } else{

			  tras->setProx(novo);

			  tras = novo;

		  }

	   }

	   //Remove o elemento 1 da Fila, pois Fila é FIFO

	   int Dequeue(){

	   	   if(isEmpty()){

			cout<<"A fila esta vazia"<<endl<<endl;

           } else{

		     int removido = frente->getValor();

		     frente = frente->getProx();

		     return removido;

          }

	   }

	   //Busca elemento da Fila

	   int Search(int info){

	   	   int status = 0; //Guarda o resultado caso o elemento esteja na fila ou não na Fila

		   //Condição caso a Fila esteja Vazia

		   if(frente == NULL){

			 status = 0;

            //Condição caso a Fila não esteja vazia

		   } else{

			   Fila aux;

			   int guarda; //Variável que vai guardar o valor eliminado da Fila

			   while(frente!=NULL){

				 guarda = Dequeue();

				 aux.Enqueue(guarda);

				 if(guarda == info){

					 status = 1;

				 }

			   }

			   //Recupera os dados da Fila depois de buscar

			   int reeinsere;

			  while(aux.frente!=NULL){

				 reeinsere = aux.Dequeue();

				 Enqueue(reeinsere);

			  }

		   }

		   return status;

	   }

};


int main(int argc, char** argv)

{

	Fila f1;

    int item;

   do{

	   cout<<"1 - Inserir "<<endl;

	   cout<<"2 - Remover"<<endl;

	   cout<<"3 - Buscar "<<endl;

	   cout<<"4 - Encerrar"<<endl;

	   cout<<endl;

	   cout<<"Insira o numero da operacao: ";

	   cin>>item;

	   cout<<endl<<endl;


	   if(item == 1){

		   cout<<"Digite o elemento a ser inserido: ";

		   int elemento;

		   cin>>elemento;

		   f1.Enqueue(elemento);

		   cout<<endl<<endl;

	   }

	   else if(item == 2){

	   	  if(!f1.isEmpty()){

		    cout<<"O elemento "<<f1.Dequeue()<<" "<<"foi removido da Fila"<<endl<<endl;

          } else{

			  f1.Dequeue();

		  }

	   }

	   else if(item == 3){

		    cout<<"Elemento a ser buscado na Fila: ";

		   int elemento;

		   cin>>elemento;

		   cout<<endl<<endl;

		   if(f1.Search(elemento) == 1){

			   cout<<"O elemento esta na Fila"<<endl<<endl;

		   } else{

			   cout<<"O elemento nao esta na Fila"<<endl<<endl;

		   }

	   }

	   else if(item < 1 || item > 4){

		   cout<<"Opcao Indisponivel"<<endl<<endl;
	   }

   }while(item != 4);

   return 0;



}
