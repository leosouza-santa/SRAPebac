#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de strings

int registrar() //cadastra usu�rios no sistema
{
	//definindo strings
	char arquivo[40];
	char cpf[40]; //string de refer�ncia
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("CPF a ser cadastrado:\t\t");
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo, cpf); //copia o valor do cpf em arquivo
	
	FILE *file; //acessa a fun��o de arquivo
	file = fopen(arquivo,"w"); //cria o arquivo, abre e escreve
	fprintf(file, "CPF: ");
	fprintf(file, cpf); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Nome a ser cadastrado:\t\t");
	scanf("%s", nome); //%s refere-se � string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, "\nNome e Sobrenome: ");
	fprintf(file, nome); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Sobrenome a ser cadastrado:\t");
	scanf("%s", sobrenome); //%s refere-se � string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, " ");
	fprintf(file, sobrenome); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Cargo a ser cadastrado:\t\t");
	scanf("%s", cargo); //%s refere-se � string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, "\nCargo: ");
	fprintf(file, cargo); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("\nOs dados foram registrados com sucesso.\n\n");
}

int consultar() //consulta usu�rios do sistema
{
	//definindo strings
	char cpf[40]; //string de refer�ncia
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	printf("CPF a ser consultado:\t\t");
	scanf("%s", cpf); //%s refere-se � string
	
	FILE *file; //acessa a fun��o de arquivo
	file = fopen(cpf, "r"); //abre o arquivo para leitura
	
	if(file == NULL) //verifica se o arquivo foi encontrado
	{
		printf("\nCPF n�o foi localizado ou n�o est� registrado.");
	}else //caso n�o seja
	{
		printf("\nDados vinculados ao CPF digitado:\n\n");
		
		while(fgets(conteudo, 200, file) != NULL) //enquanto coleta informa��es do arquivo
		{
			printf("%s", conteudo); //%s refere-se � string, mostra as informa��es
		}
		
	}
	
	fclose(file); //fecha o arquivo
	
	printf("\n\n");
}

int deletar() //deleta usu�rios do sistema
{
	//definindo strings
	char cpf[40]; //string de refer�ncia
	
	printf("CPF a ser deletado: ");
	scanf("%s", cpf); //%s refere-se � string
	
	FILE *file; //acessa a fun��o de arquivo
	file = fopen(cpf, "r"); //abre o arquivo para leitura
	
	if(file == NULL) //verifica se o arquivo foi encontrado
	{
		printf("\nCPF n�o foi localizado ou n�o est� registrado.");
	}else //caso seja
	{
		fclose(file);  //fecha o arquivo
		
		if(remove(cpf) == 0) //verifica se consegue remov�-lo
		{
			printf("\nDados vinculados ao CPF foram removidos do sistema.");
		}else //caso n�o consiga
		{
			printf("\nN�o foi poss�vel deletar os dados vinculados ao CPF.");
		}
		
	}
	
	printf("\n\n");
}

int main()
{
	//definindo vari�veis
	int opcao = 0;
	char usuario[30];
	char senha[30];
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	do //inicio do loop login
	{	
		system("cls");	//limpa a tela
		
		printf("### Registro de Nomes da EBAC ###"); //inicio da tela de login
		printf("\n\nDigite seu nome de usu�rio:\t");
		scanf("%s", usuario); //%s refere-se � string
		printf("Digite sua senha:\t\t");
		scanf("%s", senha); //%s refere-se � string e fim da tela de login
		
		system("cls"); //limpa a tela
		
		if(strcmp(usuario, "admin") != 0 && strcmp(senha, "admin") != 0) //checa se deve monstrar a mensagem de usu�rio e senha incorretos
		{
			printf("Usu�rio e/ou senha incorreto(a) ou inv�lido(a).\n\n");
			system("pause"); //pede pausa para o sistema, aguardando comando
		}
	}while(strcmp(usuario, "admin") != 0 && strcmp(senha, "admin") != 0); //fim do loop login, checando se usu�rio e senha est�o corretos
		
	do //inicio do loop menu
	{
		system("cls"); //limpa a tela
			
		printf("### Registro de Nomes da EBAC ###"); //inicio do menu
		printf("\n\nO que voc� deseja?");
		printf("\n\n\t1. Registrar Nomes\n\t2. Consultar Nomes\n\t3. Deletar Nomes\n\t4. Sair\n"); //op��es de escolha
		printf("\nDigite o n�mero correspondente:\t"); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usu�rio
	
		system("cls"); //limpa a tela
	
		switch(opcao) //resultado da escolha
		{
			case 1:
				registrar(); //chama a fun��o
				system("pause"); //pede pausa para o sistema, aguardando comando
			break;
	
			case 2:
				consultar(); //chama a fun��o
				system("pause"); //pede pausa para o sistema, aguardando comando
			break;
	
			case 3:
				deletar(); //chama a fun��o
				system("pause"); //pede pausa para o sistema, aguardando comando
			break;
			
			case 4:
				printf("Saindo do programa.\n");
			break;		

			default: //caso escolha uma op��o inv�lida
				printf("N�o � uma op��o v�lida.\n\n");
				system("pause"); //pede pausa para o sistema, aguardando comando
		}
	
	} while(opcao != 4); //define a op��o 4 como sa�da do programa e fim do loop menu
		
	return 0;
}
