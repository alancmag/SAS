#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Gera o novo alfabeto com a continuação do alfabeto sem as letras da chave, e continando a partir da ultima letra da chave
void geraAlfabeto(char *chave, char alfabetoDestino[]){
	int i,n = 0,tam_chave = strlen(chave);
	char a[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char *alf;
	
	
	while(n < tam_chave){// maísculas para minúsculas
	
		if(chave[n] >= 65 && chave[n] <= 90){//ser for uma letra maiuscula do alfabeto eu mudo para minusculo
			chave[n] = tolower(chave[n]);
		}
		n++;
	}
	
	// Colocando a chave no começo do novo alfabeto
	for(n = 0; n < tam_chave; n++){
		alfabetoDestino[n] = chave[n];
	}
	
	
	//Achar a ultima letra da chave e continar o alfabeto a partir daquele ponto e recomeçar se for preciso
	alf = strchr(a,chave[tam_chave -1]);
	alf++;
	
	for(n = 0; n < strlen(alf);n++){
		for(i = 0; i < tam_chave; i++){
			if(alf[n] == chave[i]){ // Se a letra do alfabeto esta na chave, eu tiro do alfabeto
				alf[n] = '0';	
			}
		}
	}	
	
	for(n = 0; n < 26; n++){
		if(alf[n] != '0'){
			//Coloco o resto das letras que nao foram retiradas por ja estarem na chave
			alfabetoDestino[tam_chave++] = alf[n]; 
		}
	}
		
}

// A chave é uma sequencia de caracteres do alfabeto sem repetição
// Texto ser substituido pela sua versao cifrada
void cifraSubsituicao(char *alfabeto,char *texto){
	
	int i,n, tam_texto = strlen(texto);
	char a[] = "abcdefghijklmnopqrstuvwxyz";
	
	n = 0;
	while(n < tam_texto){// maísculas para minúsculas
	
		if(texto[n] >= 65 && texto[n] <= 90){//ser for uma letra maiuscula do alfabeto eu mudo para minusculo
			texto[n] = tolower(texto[n]);
		}
		n++;
	}
	
	n = 0;
	while(n < tam_texto)
	{
		// ASCII
		// a = 97;
		// z = 122;
		if(texto[n] >= 97 && texto[n] <= 122){//ser for uma letra do alfabeto eu cifro
			
			for(i = 0; i < 26 && a[i] != texto[n]; i++); //Achar o indice da letra a ser cifrada
			
			texto[n] = alfabeto[i];
		}	
		n++;
	}
	
}

void quebraSubstituicaoComChave(char texto[],char *chave){
	int i,n, tam_texto = strlen(texto);
	char a[] = "abcdefghijklmnopqrstuvwxyz";
	//int ind[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	char alf[27] = {0};
	//char mat[3][26] = {{0},{0},{0}};
	
	geraAlfabeto(chave,alf);
	
	n = 0;
	while(n < tam_texto){// maísculas para minúsculas
	
		if(texto[n] >= 65 && texto[n] <= 90){//ser for uma letra maiuscula do alfabeto eu mudo para minusculo
			texto[n] = tolower(texto[n]);
		}
		n++;
	}
	
	n = 0;
	while(n < tam_texto)
	{
		// ASCII
		// a = 97;
		// z = 122;
		if(texto[n] >= 97 && texto[n] <= 122){//ser for uma letra do alfabeto eu cifro
			
			for(i = 0; i < 26 && alf[i] != texto[n]; i++); //Achar o indice da letra a cifrada
			
			texto[n] = a[i];
			
		}	
		n++;
	}

}




void quebraSubstituicaoSemChave(char texto[]){
	int i,n, tam_texto = strlen(texto);
	char a[] = "abcdefghijklmnopqrstuvwxyz";
	//int ind[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	char alf[27] = {0};
	//char mat[3][26] = {{0},{0},{0}};
		
	n = 0;
	while(n < tam_texto){// maísculas para minúsculas
	
		if(texto[n] >= 65 && texto[n] <= 90){//ser for uma letra maiuscula do alfabeto eu mudo para minusculo
			texto[n] = tolower(texto[n]);
		}
		n++;
	}
	
	n = 0;
	while(n < tam_texto)
	{
		// ASCII
		// a = 97;
		// z = 122;
		if(texto[n] >= 97 && texto[n] <= 122){//ser for uma letra do alfabeto eu cifro
			
			for(i = 0; i < 26 && alf[i] != texto[n]; i++); //Achar o indice da letra a cifrada
			
			texto[n] = a[i];
			
		}	
		n++;
	}

}
	
	
	



int main()
{
	int escolha;
	char texto[4000] = {0};
	char alf[] = "abcdefghijklmnopqrstuvwxyz";
	char novo_alfabeto[27] = {0};
	char chave[27] = {0};
	printf("Uso da Cifra por Substituição, digite:\n");
	printf("1 - Cifrar Texto\n");
	printf("2 - Decifrar Texto COM a CHAVE\n\nOpção: ");
	printf("3 - Decifrar Texto SEM a CHAVE\n\nOpção: ");
	scanf("%d",&escolha);
	
	if(escolha == 1)
	{
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		
		printf("Digite o a chave SEM repetir letras do alfabeto: \nChave: ");
		
		
		scanf("%[^\n]",chave);
		
		geraAlfabeto(chave,novo_alfabeto);
		//puts(novo_alfabeto);
		
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		printf("Digite o texto a ser cifrado: \n");
		scanf("%[^\n]",texto);
		
		printf("\nAlfabeto:\t\t%s\n", alf);
		printf("Novo Alfabeto\t\t%s\n\n", novo_alfabeto);
		
		cifraSubsituicao(novo_alfabeto, texto);

		printf("\nTexto cifrado:\n%s\n", texto);

		
	}
	else if(escolha == 2)
	{
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		
		printf("Digite o a chave SEM repetir letras do alfabeto: \nChave: ");
		
		
		scanf("%[^\n]",chave);
		
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		printf("Digite o texto a ser Descifrado: \n");
		scanf("%[^\n]",texto);
		
		quebraSubstituicaoComChave(texto,chave);

		printf("\nTexto Descifrado:\n%s\n", texto);
		
	}
	else if(escolha == 3)
	{
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		
		printf("Digite o a chave SEM repetir letras do alfabeto: \nChave: ");
		
		
		scanf("%[^\n]",chave);
		
		scanf("%*[^\n]"); scanf("%*c");//Limpar o buffer do teclado...
		printf("Digite o texto a ser Descifrado: \n");
		scanf("%[^\n]",texto);
		
		quebraSubstituicaoComChave(texto,chave);

		printf("\nTexto Descifrado:\n%s\n", texto);
		
	}
	return 0;
}
