#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de strings

int registrar() //cadastra usuários no sistema
{
	//definindo strings
	char arquivo[40];
	char cpf[40]; //string de referência
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("CPF a ser cadastrado:\t\t");
	scanf("%s", cpf); //%s refere-se à string
	
	strcpy(arquivo, cpf); //copia o valor do cpf em arquivo
	
	FILE *file; //acessa a função de arquivo
	file = fopen(arquivo,"w"); //cria o arquivo, abre e escreve
	fprintf(file, "CPF: ");
	fprintf(file, cpf); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Nome a ser cadastrado:\t\t");
	scanf("%s", nome); //%s refere-se à string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, "\nNome e Sobrenome: ");
	fprintf(file, nome); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Sobrenome a ser cadastrado:\t");
	scanf("%s", sobrenome); //%s refere-se à string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, " ");
	fprintf(file, sobrenome); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Cargo a ser cadastrado:\t\t");
	scanf("%s", cargo); //%s refere-se à string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, "\nCargo: ");
	fprintf(file, cargo); //salva o valor dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("\nOs dados foram registrados com sucesso.\n\n");
}

int consultar() //consulta usuários do sistema
{
	//definindo strings
	char cpf[40]; //string de referência
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	printf("CPF a ser consultado:\t\t");
	scanf("%s", cpf); //%s refere-se à string
	
	FILE *file; //acessa a função de arquivo
	file = fopen(cpf, "r"); //abre o arquivo para leitura
	
	if(file == NULL) //verifica se o arquivo foi encontrado
	{
		printf("\nCPF não foi localizado ou não está registrado.");
	}else //caso não seja
	{
		printf("\nDados vinculados ao CPF digitado:\n\n");
		
		while(fgets(conteudo, 200, file) != NULL) //enquanto coleta informações do arquivo
		{
			printf("%s", conteudo); //%s refere-se à string, mostra as informações
		}
		
	}
	
	fclose(file); //fecha o arquivo
	
	printf("\n\n");
}

int deletar() //deleta usuários do sistema
{
	//definindo strings
	char cpf[40]; //string de referência
	
	printf("CPF a ser deletado: ");
	scanf("%s", cpf); //%s refere-se à string
	
	FILE *file; //acessa a função de arquivo
	file = fopen(cpf, "r"); //abre o arquivo para leitura
	
	if(file == NULL) //verifica se o arquivo foi encontrado
	{
		printf("\nCPF não foi localizado ou não está registrado.");
	}else //caso seja
	{
		fclose(file);  //fecha o arquivo
		
		if(remove(cpf) == 0) //verifica se consegue removê-lo
		{
			printf("\nDados vinculados ao CPF foram removidos do sistema.");
		}else //caso não consiga
		{
			printf("\nNão foi possível deletar os dados vinculados ao CPF.");
		}
		
	}
	
	printf("\n\n");
}

int main()
{
	//definindo variáveis
	int opcao = 0;
	char usuario[30];
	char senha[30];
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	do //inicio do loop login
	{	
		system("cls");	//limpa a tela
		
		printf("### Registro de Nomes da EBAC ###"); //inicio da tela de login
		printf("\n\nDigite seu nome de usuário:\t");
		scanf("%s", usuario); //%s refere-se à string
		printf("Digite sua senha:\t\t");
		scanf("%s", senha); //%s refere-se à string e fim da tela de login
		
		system("cls"); //limpa a tela
		
		if(strcmp(usuario, "admin") != 0 && strcmp(senha, "admin") != 0) //checa se deve monstrar a mensagem de usuário e senha incorretos
		{
			printf("Usuário e/ou senha incorreto(a) ou inválido(a).\n\n");
			system("pause"); //pede pausa para o sistema, aguardando comando
		}
	}while(strcmp(usuario, "admin") != 0 && strcmp(senha, "admin") != 0); //fim do loop login, checando se usuário e senha estão corretos
		
	do //inicio do loop menu
	{
		system("cls"); //limpa a tela
			
		printf("### Registro de Nomes da EBAC ###"); //inicio do menu
		printf("\n\nO que você deseja?");
		printf("\n\n\t1. Registrar Nomes\n\t2. Consultar Nomes\n\t3. Deletar Nomes\n\t4. Sair\n"); //opções de escolha
		printf("\nDigite o número correspondente:\t"); //fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usuário
	
		system("cls"); //limpa a tela
	
		switch(opcao) //resultado da escolha
		{
			case 1:
				registrar(); //chama a função
				system("pause"); //pede pausa para o sistema, aguardando comando
			break;
	
			case 2:
				consultar(); //chama a função
				system("pause"); //pede pausa para o sistema, aguardando comando
			break;
	
			case 3:
				deletar(); //chama a função
				system("pause"); //pede pausa para o sistema, aguardando comando
			break;
			
			case 4:
				printf("Saindo do programa.\n");
			break;		

			default: //caso escolha uma opção inválida
				printf("Não é uma opção válida.\n\n");
				system("pause"); //pede pausa para o sistema, aguardando comando
		}
	
	} while(opcao != 4); //define a opção 4 como saída do programa e fim do loop menu
		
	return 0;
}
