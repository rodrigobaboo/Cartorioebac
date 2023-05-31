#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cudar das strings


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistemas
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");	//coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo "w"significa escrever
	fprintf(file,cpf); //salva o valor da v�riavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}


int consultar()
{
	 setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
    }
    else
    {
        while (fscanf(file, "%[^,],%[^,],%[^,],%[^\n]", cpf, nome, sobrenome, cargo) != EOF)
        {
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Sobrenome: %s\n", sobrenome);
            printf("Cargo: %s\n", cargo);
            printf("\n");
        }
        
            }
    
    system("pause");
	
}


int deletar()
{
setlocale(LC_ALL, "Portuguese");
	
  char cpf[40];
  
  printf("Digite o CPF do usu�rio a ser deletado: ");
  scanf("%s" ,cpf);
  
  remove (cpf);
  
  FILE *file;
  file = fopen(cpf, "r");
  printf("Usu�rio exclu�do com sucesso! \n");
 
  
  if(file == NULL)
  {
  	printf("Cadastro inexistente! \n");
  	system("pause");
  }
		
}


int main()
	{
		int opcao=0; //Definindo as vari�veis
		int laco=1;
	
		for(laco=1;laco=1;)
		{
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
		printf("~~~ Cart�rio da EBAC ~~~\n\n"); //In�cio do menu
		printf("Op��es de menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");			
		printf("Op��o: ");
		//Fim do menu
			
	
			scanf("%d" , &opcao); //Armazenando escolha do usu�rio
	
			system("cls"); //Respons�vel por limpar a tela
			
			switch(opcao)
			{
				case 1:
				registro();
				break;
				
				case 2:
				consultar();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
							
				default:
				printf("COMANDO INDISPON�VEL\n!");
				system("pause");
				break;
			}
										
			
			
	}


}




