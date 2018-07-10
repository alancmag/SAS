#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// src = a string a ser cifrada
// chave = o tamanho do deslocamento das letras
void CifraDeCesar(char *src, int chave)
{
	int n = 0,tam = strlen(src);
	char *ret, a[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

	while(n < tam)// maísculas para minúsculas
	{
		if(src[n] >= 65 && src[n] <= 90){//ser for uma letra maiuscula do alfabeto eu mudo para minusculo
			src[n] = tolower(src[n]);
		}
		n++;
	}

	n = 0;
	while(n < tam)
	{
		// ASCII
		// a = 97;
		// z = 122;
		if(src[n] >= 97 && src[n] <= 122){//ser for uma letra do alfabeto eu cifro
			ret = strchr(a,src[n]);
			src[n] = ret[chave];
		}	
		n++;
	}
}

void QuebraCesar (char  *src)
{
	//Como só existem 25 possibilidades de cifras... Usar força bruta...
	int i, n = 0,fb = 1,tam = strlen(src);
	char a[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	printf("EXECUTANDO FORÇA BRUTA...\nGERANDO TODAS AS POSSIBILIDADES...\n");
	while(n < tam)// maísculas para minúsculas
	{
		if(src[n] >= 65 && src[n] <= 90){//ser for uma letra maiuscula do alfabeto eu mudo para minusculo
			src[n] = tolower(src[n]);
		}
		n++;
	}
	//Fazer os 25 passos de Força Bruta
	while(fb <= 25)
	{
		n = 0;
		printf("%d: ", fb);
	
		while(n < tam)
		{
			if(src[n] >= 97 && src[n] <= 122){//ser for uma letra do alfabeto
				i = 0;
				//Encontro a posição da letra criptografada no segundo alfabeto do vetor para subtrair o FB dele e chegar na letra certa
				while(a[26 + i] != src[n] ) i++;
				printf("%c",a[26 + i - fb]);
			}
			else //Se não é uma letra, só imprime
			{
				printf("%c", src[n]);
			}
			n++;
		}     
		puts("\n");
		
		fb++;  
	}

}

int main()
{
	int escolha,deslocamento;
	char texto[4000] = {0};
	char alf[] = "abcdefghijklmnopqrstuvwxyz";
	
	
	printf("Uso da Cifra de César, digite:\n");
	printf("1 - Cifrar Texto\n");
	printf("2 - Decifrar Texto\n\nOpção: ");

	scanf("%d",&escolha);
	
	if(escolha == 1)
	{
		printf("\nDigite o Deslocamento: \n");
		scanf("%d",&deslocamento);
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		printf("Digite o texto: \n");
		scanf("%[^\n]",texto);
		printf("\nAlfabeto:\t\t\t%s\n", alf);
		CifraDeCesar(alf, deslocamento);
		printf("Alfabeto com deslocamento %d:    %s\n", deslocamento,alf);
		
		CifraDeCesar(texto, deslocamento);
		printf("\nTexto cifrado:\n%s\n", texto);

		
	}
	else if(escolha == 2)
	{
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		printf("Digite o texto para ser Decifrado: \n");
		scanf("%[^\n]",texto);
		QuebraCesar(texto);
		
	}
	return 0;
}
