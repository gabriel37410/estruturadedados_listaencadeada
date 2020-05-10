#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC(a) (a *) malloc ( sizeof(a) )

struct no
{
   int info;
        
   struct no *proximo;
   struct no *anterior;
};

// ponteiros de referência
struct no *inicio;
struct no *fim;

//Insere um novo dado na lista
void inserir ( int info )
{
   struct no *novo = MALLOC ( struct no );
   struct no *atual;
        
   if ( !novo )
   {
      perror ( "Malloc: " );
      return ;
   }
        
   // atribuição do novo valor...
   novo->info = info;
        
   // cria lista
   if ( !inicio )
   {
      novo->proximo = NULL;
      novo->anterior  = NULL;
                
      inicio = novo;
      fim = novo;
                
      return ;
   }
        
   // se não for o primeiro elemento da lista...
   atual = inicio;
        
   while ( atual )
   {
      if ( atual->info < info ) {
         atual = atual->proximo;
      }
      else
      {
         // elemento intermediário - caso 2
         if ( atual->anterior )
         {
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            atual->anterior->proximo = novo;
            atual->anterior = novo;
                                
            return ;
         }
         // novo primeiro elemento - caso 1
         novo->proximo = atual;
         novo->anterior = NULL;
         atual->anterior = novo;
         inicio = novo;
                        
         return ;
      }
   }
   // novo último elemento - caso 3
   fim->proximo = novo;
   novo->proximo = NULL;
   novo->anterior = fim;
   fim = novo;
  
   return ;
}

//Imprimi os dados da lista
void imprimeLista ( void )
{
   struct no *atual = inicio;
        
   while ( atual )
   {
      printf ( "Info:  %.2d\n", atual->info );
      atual = atual->proximo;
   }
   return ;
}

//Procura um elemento na lista
struct no *procurar ( int info )
{
   struct no *atual = inicio;
        
   while ( atual )
   {
      if ( atual->info == info) {
         return atual;
      }
      else {
         atual = atual->proximo;
      }
   }
   return printf("Valor nao encontrado");
}



int main ( void )
{
   register int i;
   inicio = fim = NULL;

   //Inseri 10 elementos na lista
   for ( i = 1; i <= 10; i++ ) {
      inserir (i);
   }
   imprimeLista(); puts ("");

   //Inseri elementos na lista     
   inserir (0);
   inserir (12);
   inserir (11); 
        
   imprimeLista (); puts ("");

   // teste da função de procura
   printf ("Procurar( 3 ): %.2d\n\n", procurar(3)->info );

   return 0;
}
