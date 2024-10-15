/*
  Enrico Manzolli Bertoni RA: 176259
  exemplo gravacao de arquivo
  15/10/2024
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *arq; //cria variável ponteiro para o arquivo
  char palavra[20]; //variável tipo string

  //abrindo o arquivo com tipo de abertura w
  arq = fopen("arquivo_palavra.txt", "w");
  
  if(arq == NULL){
    printf("Erro na abertura do arquivo!\n");
    return 1;
  }
  printf("Escreva uma palavra para gravar no arquivo: ");
  scanf("%s", palavra);

  //usando fprintf para armazenar a string no arquivo
  fprintf(arq, "%s", palavra);

  //usando fclose para fechar o arquivo
  fclose(arq);
  printf("Dados gravados com sucesso!\n");
  return 0;
}