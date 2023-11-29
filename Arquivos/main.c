#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;  // Declara um ponteiro para um arquivo
    char info[1000];  // Declara uma string para armazenar o lembrete
    char linha[1000];  // Declara uma string para ler linhas do arquivo

    fp=fopen("arquivo.txt","a+");  // Abre o arquivo para leitura e escrita no final do arquivo

    printf("Escreva o lembrete: ");  // Solicita ao usu�rio para digitar o lembrete
    fgets(info, 1000, stdin);  // L� a entrada do usu�rio

    int len = strlen(info);  // Obt�m o comprimento da string de entrada
    if(info[len-1] != '\n')  // Se a string n�o terminar com uma quebra de linha
    {
        info[len] = '\n';  // Adiciona uma quebra de linha no final da string
        info[len+1] = '\0';  // Adiciona o caractere nulo no final da string
    }

    fputs(info,fp);  // Escreve a string no arquivo

    fclose(fp);  // Fecha o arquivo

    fp = fopen("arquivo.txt", "r+");  // Reabre o arquivo para leitura e escrita
    if(fp == NULL)  // Se o arquivo n�o p�de ser aberto
    {
        printf("N�o foi poss�vel abrir o arquivo.\n");  // Imprime uma mensagem de erro
        return 1;  // Retorna 1 para indicar um erro
    }

    // L� e imprime cada linha do arquivo
    while(fgets(linha, sizeof(linha), fp) != NULL)
    {
        printf("%s", linha);
    }

    fclose(fp);  // Fecha o arquivo

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}