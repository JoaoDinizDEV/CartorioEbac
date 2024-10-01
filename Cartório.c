#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espac�o em memoria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca responsavel por cuidar da string 

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema 
{     
     //inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario 
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo no banco de dados 
	file =fopen(arquivo, "w"); // cria o arquivo "w" � referente a um novo arquivo
	fprintf(file, cpf);// salvo o valor da variavel 
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessa o arquivo no banco de dados "a" responsavel por atualizar o arquivo
	fprintf(file, ","); //salva o valor da variavel dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//solicita o nome para o usuario
	scanf("%s",nome);//%s � referente a string
	
	file = fopen(arquivo, "a");//acessa o arquivo no banco de dados "a" atualiza o arquivo
	fprintf(file, nome);//salva o valor da variavel no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//acessa o arquivo no banco de dados "a" atualiza o arquivo
	fprintf(file, ",");//salva o valor da varialvel 
	fclose(file);//fecha o arquivo

    printf("Digite o sobrenome a ser cadastrado: ");//coletando dados do usuario
    scanf("%s", sobrenome);//%s � referente a string
    
    file = fopen(arquivo, "a");//acessa o arquivo no banco de dados "a" atualiza o arquivo
    fprintf(file, sobrenome);//salva o valor da variavel 
    fclose(file);//fecha o arquivo
    
	file = fopen(arquivo, "a");//acessa o arquivo no banco de dados "a" atualiza o arquivo
	fprintf(file, ",");//salva o valor da variavel 
	fclose(file);//fecha o arquivo 

    printf("Digite o cargo a ser cadastrado: ");//coleta as informa��es do usuario
    scanf("%s", cargo);//%s � referente a string
    
    file = fopen(arquivo, "a");//acessa o arquivo no banco de dados "a" atualiza o arquivo
    fprintf(file, cargo);//salva o valor da variavel 
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//acessa o arquivo no banco de dados "a" atualiza o arquivo
	fprintf(file, ",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	

    
    	
}
int consulta()
{
		setlocale(LC_ALL, "portuguese");// Definindo o linguagem 
		//inicio da cria��o de variaveis/string
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");//solicitando dados ao usuario
	scanf("%s", cpf);//%s � referente a string
	
	FILE *file; //vai abrir o arquivo existente 
	file = fopen(cpf, "r");//responsavel por ler o arquivo dentro do banco de dados
	
	if(file == NULL)//verifica se o arquivo � nullo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");//caso o usuario digite algo que n�o esta no banco de dados aparece essa mensagem
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
		system("pause");
	
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); 
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O us�ario n�o se encontra no sistema.\n");
		system("pause");
	}
}

int main ()
{
	
	int opcao=0; //Definindo as veriaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "portuguese");// Definindo o linguagem 
		printf("### Cart�rio da EBAC  ###\n\n");//Inicio do menu
	    printf("Escolha a op��o desejada do menu: \n\n");
	    printf("\t1- Registrar nomes \n");
	    printf("\t2- Consultar os nomes \n");
	    printf("\t3- Deletar os nomes \n\n");
	    printf("Op��o: ");//Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuario 
	
	    system("cls"); //responsavel por limpar a tela 
	    
	    switch(opcao) //inicio da sele��o do menu 
		{
			case 1:
			registro(); //chamada da fun��o registro 
		    break;
		
		    case 2: 
		    consulta(); //chamada da fun��o consulta 
		    break;
		
		    case 3:
			deletar(); //chamada da fun��o deletar 
		    break;
		    
		    default: 
		    printf("Essa op��o n�o esta disponivel!\n");
		    system("pause");
		    break;	//fim da sele��o do menu 
		}
	

}



	
	
		
}

