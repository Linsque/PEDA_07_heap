// Rafael Bonfim Zacco

/*
Sua tarefa será construir um heap (binário, max-heap), e criar métodos para criar a árvore e a partir de um array, inserir, excluir, e buscar valores_aleatorios na árvore. Seu objetivo é explicar o funcionamento dos  métodos  que  você  irá  criar.  Para  isso,  deve  buscar  em  sites  acadêmicos,  exemplos  de implementação de árvores heap. 
Para  testar,  você deve usar  um  array  com,  no  mínimo, 500  itens,  gerados  randomicamente  e criar métodos para testar se a estrutura criada obedece a regra de criação que você determinou. 
*/

// algoritmo de heap
// métodos de inserir, excluir e buscar
// explicar métodos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam = 0;

void troca(int *a, int *b){
  
  int aux = *b;
  *b = *a;
  *a = aux;

}

void heapify(int array[], int tam, int i){
  
  if (tam == 1){
    printf("Apenas um elemento no heap!");
  }
    
  else{
    int ultimo = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < tam && array[l] > array[ultimo])
      ultimo = l;
    
    if (r < tam && array[r] > array[ultimo])
      ultimo = r;
    
    if (ultimo != i){
      troca(&array[i], &array[ultimo]);
      heapify(array, tam, ultimo);
    }
  }
  
}

void inserir(int array[], int novo){

  if (tam == 0){
    array[0] = novo;
    tam += 1;
  }
    
  else{
    array[tam] = novo;
    tam += 1;
    
    for (int i = tam / 2 - 1; i >= 0; i--){
      heapify(array, tam, i);
    }
  }

}

void excluir(int array[], int num){
  
  int i;
  for (i = 0; i < tam; i++){
    if (num == array[i])
      break;
  }

  troca(&array[i], &array[tam - 1]);
  tam -= 1;
  for (int i = tam / 2 - 1; i >= 0; i--){
    heapify(array, tam, i);
  }
  
}

void printArray(int array[], int tam){
  
  for (int i = 0; i < tam; ++i)
    printf("%d ", array[i]);
  printf("\n");
  
}

int main(){
  
  int tamanho = 10;
  int array[tamanho];
  
  int valores_aleatorios[tamanho];
  int semente;
  int valor_aleatorio;
  
  int i;
  
  srand(time(NULL));
  semente = 1 + rand() % 100;
  for (i=0;i<tamanho;i++){
    srand(semente+i);
    valor_aleatorio = 1 + rand() % 100; // vai de 1 até 100
    valores_aleatorios[i] = valor_aleatorio;
  }

  for (i=0;i<tamanho;i++){
    inserir(array,valores_aleatorios[i]);
  }

  printf("Array: ");
  printArray(array, tam);

  printf("\nExcluindo o número 100...\n\n");
  
  printf("Array: ");
  printArray(array,tam);

  return 0;
  
}