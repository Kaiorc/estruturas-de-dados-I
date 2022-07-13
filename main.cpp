//Kaio Rodrigues da Cunha
//1394485

#include <iostream>



using namespace std;



int const MAXTAM = 10;



class Pilha{

	private :

		int vetor[MAXTAM]; //pilha

        int topo; // topo da pilha



   	public:

   		//Construtor da Classe

		Pilha(){

			this->topo= -1;

		}



		//Apaga a Pilha

		void Clear(){

		     this ->topo = -1;

		}



		//Verifica se a pilha esta vazia

		bool isEmpty(){

			if(topo == -1){

				return true;

			} else{

				return false;

			}

		}



		//Verifica se a Pilha esta cheia

		bool isFull(){

			if(topo == MAXTAM-1){

				return true;

			} else{

				return false;

			}

		}



		//Insere um elemento na Pilha

		void Push( int info){

			if(isFull()){

				cout<<"A Pilha ja esta cheia "<<endl;

			}else{

			   vetor[topo+1] = info;

			    topo ++;

			}

        }



        //Remove elemento da Pilha e retorna o elemento que foi removido

        int Pop(){

         int guarda;

		 if(isEmpty()){

           cout<<"A Pilha se encontra vazia"<<endl<<endl;

			} else{

			  guarda = vetor[topo];

			  vetor[topo] == NULL;

			  topo --;

			}

			return guarda;

		}

		//Busca na Pilha

		int Search(int elemento){

		   int status = 0; //Guardará o elemento se o elemento está ou nao na Pilha

		   int guarda;

		   Pilha aux;

		   //Caso a pilha esteja vazia

		   if(topo == -1){

			   status = 0;

		   }

		   //Caso a Pilha só tenha um elemento

		   if(topo == 0){

			   guarda = Pop();

			   if(guarda == elemento){

				   status  = 1;

				   Push(guarda);

			   } else{

				   status = 0;

				   Push(guarda);

			   }

		   }

		   //Caso a Pilha tenha mais de um elemento

		   if(topo > 0){

           int cont = topo;

		   guarda = Pop();

		   //Compara se o elemento que se está buscando é o primeiro da Pilha

		    if(guarda == elemento){

			  status =1;

			  Push(elemento);

           // Se o elemento não estiver na 1º Posição*/

		   } else{

		   	 aux.Push(guarda);

		   	 // Desempilha até achar o elemento e caso não esteja status continua com 0

			  while(topo > -1){

				  guarda = Pop();

				  aux.Push(guarda);

				  cont --;

				  if(guarda == elemento){

					  status = 1;

					  break;

				  }

				  if(cont == 0){

					  break;

				  }

			  }

			  //Processo que irá empilhar na Pilha novamente

			  while(aux.topo!=-1){

				  Push(aux.Pop());

			  }

		    }

		   }

		   return status;

		}
};



int main(int argc, char** argv){

   Pilha p1;

   int item;

   do{
	   cout<<"1 - Inserir"<<endl;

	   cout<<"2 - Remover"<<endl;

	   cout<<"3 - Buscar Elemento "<<endl;

	   cout<<"4 - Apagar Pilha"<<endl;

	   cout<<"5 - Sair"<<endl<<endl;

	   cout<<"Insira o numero da operacao a ser realizada: ";

	   cin>>item;

	   cout<<endl<<endl;


        if(item == 1){

		   cout<<"Insira o elemento que deseja colocar na Pilha: ";

		   int elemento;

		   cin>>elemento;

		   p1.Push(elemento);

		   cout<<endl<<endl;

	   }

	    else if(item == 2){

  	      if(!p1.isEmpty()){

		    cout<<"Elemento: "<<p1.Pop()<<" "<<"foi removido da Pilha"<<endl<<endl;

          } else {

			  p1.Pop();

		  }

	   }


	   else if(item == 3){

		   cout<<"Insira o elemento que deseja buscar na Pilha: ";

		   int elemento;

		   cin>>elemento;

		   cout<<endl<<endl;

		   if(p1.Search(elemento) == 1){

			   cout<<"O elemento se encontra na Pilha"<<endl<<endl;

		   } else{

			   cout<<"O elemento nao esta na Pilha"<<endl<<endl;

		   }

	   }



	   else if(item == 4){

		   p1.Clear();

	   }

	       else if(item < 1 || item > 5){

		   cout<<"Opcao Invalida"<<endl<<endl;

	   }



   } while(item != 5);

}
