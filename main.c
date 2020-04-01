#include <stdio.h>
#include <stdlib.h>

typedef struct data1{
	int cod;
	char nome[30];
	char email[30];
	char telefone[13];
	char logradouro[200];
	char cidade[20];
	char estado[20];
	char cep[8];
	char cpf[11];
	char rg[8];
	char data_nascimento[10];
	
}clientes;
typedef struct data2{
	int cod;
	char nome[50];
	char categoria[100];
	char unidade_medida[10];	// unidade de medida do produto
	char validade[13];
	float valor;
	float quantidade;
}produtos;
typedef struct data3{
	char produto[100];
	char cliente[100];
	float valor_total;
	float quantidade;
}vendas;

int menu();
void cadastrarClientes();
void cadastrarProdutos();
void adicionarProdutos();
void buscarProdutoId();
void buscarClienteId();
void listarClientes();
void listarProdutos();
void efetuarVenda();
void listarVendas();

void main(){
	int op;
	do{
		op = menu();
		switch(op){
			case 1:
				cadastrarClientes();
				break;
			case 2:
				listarClientes();
				break;
			case 3: 
				buscarClienteId();
				break;
			case 4:
				cadastrarProdutos();
				break;
			case 5:
				listarProdutos();
				break;
			case 6:
				buscarProdutoId();
				break;
			case 7:
				adicionarProdutos();
				break;
			case 8:
				efetuarVenda();
				break;
			case 9:
				listarVendas();
				break;
			case 0:
				printf("  Saindo!\n");
				break;
			default:	
				printf("Escolha uma opcao valida\n");
				break;
		}
	}while(op != 0);
}
int menu(){
	int op;
	
	printf("\n       == MENU ==        \n\n");
	printf(" (1)...Cadastrar clientes\n");
	printf(" (2)...Listar clientes\n");
	printf(" (3)...Buscar clientes\n\n");
	printf(" (4)...Cadastrar produtos\n");
	printf(" (5)...Listar produtos\n");
	printf(" (6)...Buscar produtos\n");
	printf(" (7)...Adicionar produtos\n\n");
	printf(" (8)...Realizar venda\n");
	printf(" (9)...Listar vendas\n\n");
	printf(" ---------------------\n\n");
	printf(" (0)...Sair do sistema\n\n");
	printf("  Escolha uma opcao: ");
	scanf("%d", &op);
	printf("\n");
	return(op);
}
void cadastrarClientes(){
	clientes cliente;
	FILE *arq_clientes;
	arq_clientes = fopen("clientes.txt", "a");
	if(arq_clientes == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1); 
	}
	system("cls");
	printf("\n ==== Cadastro de clientes ==== \n");
	printf("\nInforme um codigo para o cliente: ");
	scanf("%d", &cliente.cod);
	fprintf(arq_clientes, "%d\n", cliente.cod);
	
	printf("\nInforme o nome: ");
	setbuf(stdin, NULL);
	scanf(" %[^\n]s", cliente.nome);
	fprintf(arq_clientes, "%s\n", cliente.nome);
	
	printf("\nInforme o email: ");
	scanf(" %[^\n]s", cliente.email);
	fprintf(arq_clientes, "%s\n", cliente.email);
	
	printf("\nInforme o telefone: ");
	scanf(" %[^\n]s", cliente.telefone);
	fprintf(arq_clientes, "%s\n", cliente.telefone);
	
	printf("\nInforme o logradouro: ");
	scanf(" %[^\n]s", cliente.logradouro);
	fprintf(arq_clientes, "%s\n", cliente.logradouro);
	
	printf("\nInforme a cidade: ");
	scanf(" %[^\n]s", cliente.cidade);
	setbuf(stdin, NULL);
	fprintf(arq_clientes, "%s\n", cliente.cidade);
	
	printf("\nInforme o estado: ");
	scanf(" %[^\n]s", cliente.estado);
	fprintf(arq_clientes, "%s\n", cliente.estado);
	
	printf("\nInforme o cep: ");
	scanf(" %[^\n]s", cliente.cep);
	fprintf(arq_clientes, "%s\n", cliente.cep);
	
	printf("\nInforme o cpf: ");
	scanf(" %[^\n]s", cliente.cpf);
	fprintf(arq_clientes, "%s\n", cliente.cpf);
	
	printf("\nInforme o rg: ");
	scanf(" %[^\n]s", cliente.rg);
	fprintf(arq_clientes, "%s\n", cliente.rg);
	
	printf("\nInforme o data de nascimento(dd/mm/aaaa): ");
	scanf(" %[^\n]s", cliente.data_nascimento);
	fprintf(arq_clientes, "%s\n", cliente.data_nascimento);
	
	printf("\n === Cliente cadastrado! === \n\n");
	fclose(arq_clientes);
	system("pause");
	system("cls");
}

void listarClientes(){
		clientes cliente;
		FILE *arq_clientes;
		arq_clientes = fopen("clientes.txt", "r");
		if(arq_clientes == NULL){
			printf("\nERRO AO ABRIR O ARQUIVO");
			exit(1);
		}
		system("cls");
		printf("\n ==== Lista de clientes: ==== \n");
		while(1){	
			fscanf(arq_clientes, "%d", &cliente.cod);
			if(feof(arq_clientes)){
				break;
			}
			printf("\n COD [%d]", cliente.cod);
		
			fscanf(arq_clientes, " %[^\n]s", cliente.nome);
			printf("\n Nome do cliente: %s", cliente.nome);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.email);
			printf("\n Email: %s", cliente.email);
	
			fscanf(arq_clientes, " %[^\n]s", cliente.telefone);
			printf("\n Telefone: %s", cliente.telefone);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.logradouro);
			printf("\n Logradouro: %s", cliente.logradouro);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.cidade);
			printf("\n Cidade: %s", cliente.cidade);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.estado);
			printf("\n Estado: %s", cliente.estado);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.cep);
			printf("\n Cep: %s", cliente.cep);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.cpf);
			printf("\n Cpf: %s", cliente.cpf);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.rg);
			printf("\n Rg: %s", cliente.rg);
			
			fscanf(arq_clientes, " %[^\n]s", cliente.data_nascimento);
			printf("\n Data de Nascimento: %s\n", cliente.data_nascimento);
			printf(" -----------------------");
		}fclose(arq_clientes);	
		printf("\n\n === FIM DA LISTA ===\n\n");
		system("pause");
		system("cls");
}
void buscarClienteId(){
	clientes cliente;
	FILE *arq_clientes;
	arq_clientes = fopen("clientes.txt", "r");
	if(arq_clientes == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	int cod;
	system("cls");
	printf("\n === Buscar cliente ===\n");
	printf("\n Informe o codigo do cliente: ");
	scanf("%d", &cod);
	while (!feof(arq_clientes)){
			// le todo o arquivo 
			fscanf(arq_clientes, "%d", &cliente.cod);
			fscanf(arq_clientes, " %[^\n]s", cliente.nome);
			fscanf(arq_clientes, " %[^\n]s", cliente.email);
			fscanf(arq_clientes, " %[^\n]s", cliente.telefone);
			fscanf(arq_clientes, " %[^\n]s", cliente.logradouro);
			fscanf(arq_clientes, " %[^\n]s", cliente.cidade);
			fscanf(arq_clientes, " %[^\n]s", cliente.estado);
			fscanf(arq_clientes, " %[^\n]s", cliente.cep);
			fscanf(arq_clientes, " %[^\n]s", cliente.cpf);
			fscanf(arq_clientes, " %[^\n]s", cliente.rg);	
			fscanf(arq_clientes, " %[^\n]s", cliente.data_nascimento);
			if(cod != cliente.cod){ // testa se o cod informado se compara ao lido no arq
				if(!feof(arq_clientes)){
					continue; 
				}else{
					printf("\n Cliente n cadastrado! \n\n");
					break;
				}
			}else{
				printf("\n COD [%d]", cliente.cod);
				printf("\n Nome do cliente: %s", cliente.nome);
				printf("\n Email: %s", cliente.email);
				printf("\n Telefone: %s", cliente.telefone);
				printf("\n Logradouro: %s", cliente.logradouro);
				printf("\n Cidade: %s", cliente.cidade);
				printf("\n Estado: %s", cliente.estado);
				printf("\n Cep: %s", cliente.cep);
				printf("\n Cpf: %s", cliente.cpf);
				printf("\n Rg: %s", cliente.rg);
				printf("\n Data de Nascimento: %s\n\n", cliente.data_nascimento);
				break;
			}
		} fclose(arq_clientes);
		system("pause");
		system("cls");
}
void cadastrarProdutos(){
	produtos produto;
	FILE *arq_produtos;
	arq_produtos = fopen("produtos.txt", "a");
	if(arq_produtos == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	system("cls");
	printf("\n === Cadastro de produtos === \n");
	printf("\n Informe o codigo do produto: ");
	scanf("%d", &produto.cod);
	fprintf(arq_produtos, "%d\n", produto.cod);
	
	printf("\n Informe a quantidade: ");
	scanf("%f", &produto.quantidade);
	fprintf(arq_produtos, "%f\n", produto.quantidade);
	
	printf("\n Informe o nome do produto: ");
	scanf(" %[^\n]s", &produto.nome);
	fprintf(arq_produtos, "%s\n", produto.nome);
	
	printf("\n Informe a categoria: ");
	scanf(" %[^\n]s", &produto.categoria);
	fprintf(arq_produtos, "%s\n", produto.categoria);
	
	printf("\n Informe a unidade de medida: ");
	scanf(" %[^\n]s", &produto.unidade_medida);
	fprintf(arq_produtos, "%s\n", produto.unidade_medida);
	
	printf("\n Informe a validade(dd/mm/aaaa): ");
	scanf(" %[^\n]s", &produto.validade);
	fprintf(arq_produtos, "%s\n", produto.validade);
	
	printf("\n Informe o valor (R$): ");
	scanf("%f", &produto.valor);
	fprintf(arq_produtos, "%f\n", produto.valor);
	
	fclose(arq_produtos);
	printf("\n === Produto cadastrado! ==== \n\n");
	system("pause");
	system("cls");
}
void listarProdutos(){
	produtos produto;
	FILE *arq_produtos;
	arq_produtos = fopen("produtos.txt", "r");
	if(arq_produtos == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	system("cls");
	printf("\n === Lista de produtos === \n");
	while (1){	
    	fscanf(arq_produtos, "%d", &produto.cod);
    	if(feof(arq_produtos)){
			break;
			}
		printf("\n COD [%d]", produto.cod);
		
		fscanf(arq_produtos, "%f", &produto.quantidade);
		printf("\n Quantidade: %.2f", produto.quantidade);
	
		fscanf(arq_produtos, " %[^\n]s", &produto.nome);
		printf("\n Nome: %s", produto.nome);
	
		fscanf(arq_produtos, " %[^\n]s", &produto.categoria);
		printf("\n Categoria: %s", produto.categoria);
	
		fscanf(arq_produtos, " %[^\n]s", &produto.unidade_medida);
		printf("\n Unidade de medida: %s", produto.unidade_medida);
	
		fscanf(arq_produtos, " %[^\n]s", &produto.validade);
		printf("\n Validade: %s", produto.validade);
	
		fscanf(arq_produtos, "%f", &produto.valor);
		printf("\n Valor: R$ %.2f\n", produto.valor);
		printf(" -----------------------");
		}
	fclose(arq_produtos);
	printf("\n\n === FIM DA LISTA === \n\n");
	system("pause");
	system("cls");
}
void buscarProdutoId(){
	produtos produto;
	FILE *arq_produtos;
	arq_produtos = fopen("produtos.txt", "r");
	if(arq_produtos == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	int cod;
	system("cls");
	printf("\n === Buscar produto === \n");
	printf("\n Informe o codigo do produto: ");
	scanf("%d", &cod);
	while (!feof(arq_produtos)){
			fscanf(arq_produtos, "%d", &produto.cod);
			fscanf(arq_produtos, "%f", &produto.quantidade);
			fscanf(arq_produtos, " %[^\n]s", produto.nome);
			fscanf(arq_produtos, " %[^\n]s", produto.categoria);
			fscanf(arq_produtos, " %[^\n]s", produto.unidade_medida);
			fscanf(arq_produtos, " %[^\n]s", produto.validade);
			fscanf(arq_produtos, "%f", &produto.valor);
			if(cod != produto.cod){ // testa se o cod informado se compara ao lido no arq
				if(!feof(arq_produtos)){
					continue;
				}else{
					printf("\n Produto n cadastrado\n");
					break;
				}
			}else{
				printf("\n COD [%d]", produto.cod);
				printf("\n Quantidade: %.2f", produto.quantidade);
				printf("\n Nome: %s", produto.nome);
				printf("\n Categoria: %s", produto.categoria);
				printf("\n Unidade de medida: %s", produto.unidade_medida);
				printf("\n Validade: %s", produto.validade);
				printf("\n Valor : R$ %.2f\n\n", produto.valor);
				break;
			}
		} fclose(arq_produtos);
		system("pause");
		system("cls");
}
void adicionarProdutos(){
	produtos produto;
	FILE *arq_produtos;
	arq_produtos = fopen("produtos.txt", "r+");
	if(arq_produtos == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	int cod;
	fpos_t position; // variavel para guardar posicao do valor da quantidade do produto
	float quantidade;
	system("cls");
	printf("\n === Adicionar produto === \n");
	printf("\n Informe o codigo do produto: ");
	scanf("%d", &cod);
	while (!feof(arq_produtos)){
			fscanf(arq_produtos, "%d", &produto.cod);
			fgetpos (arq_produtos, &position); // le a posicao do inicio valor quantidade
			fscanf(arq_produtos, "%f", &produto.quantidade);
			fscanf(arq_produtos, " %[^\n]s", produto.nome);
			fscanf(arq_produtos, " %[^\n]s", produto.categoria);
			fscanf(arq_produtos, " %[^\n]s", produto.unidade_medida);
			fscanf(arq_produtos, " %[^\n]s", produto.validade);
			fscanf(arq_produtos, "%f", &produto.valor);
			if(cod != produto.cod){ // testa se o cod informado se compara ao lido no arq
				if(!feof(arq_produtos)){
					continue;
				}else{
					printf("\n Produto n cadastrado\n");
					break;
				}
			}else{
				printf("\n COD [%d]", produto.cod);
				printf("\n Quantidade atual: %.2f", produto.quantidade);
				printf("\n Nome do produto: %s", produto.nome);
				printf("\n Informe a quantidade a adicionar: ");
	 			scanf("%f", &quantidade);	
				//seta a posicao e altera o valor quantidade
				fsetpos (arq_produtos, &position);
				quantidade = quantidade + produto.quantidade;
				fprintf(arq_produtos, " %f", quantidade);
				fclose(arq_produtos);
				printf("\n\n === Quantidade adicionda! === \n\n");
				break;
			}
		}
		system("pause");
		system("cls");
}
void efetuarVenda(){
	produtos produto;
	clientes cliente;
	vendas venda;
	FILE *arq_produtos;
	FILE *arq_clientes;
	FILE *arq_vendas;
	arq_produtos = fopen("produtos.txt", "r+");
	if(arq_produtos == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	int cod_c, cod_p;
	fpos_t position;
	float quantidade;
	system("cls");
	printf("\n === Efetuar venda === \n");
	printf("\n Informe o codigo do produto: ");
	scanf("%d", &cod_p);
	// verifica se o produto esta cadastrado lendo todo o arquivo
	while (!feof(arq_produtos)){
			fscanf(arq_produtos, "%d", &produto.cod);
			fgetpos (arq_produtos, &position);
			fscanf(arq_produtos, "%f", &produto.quantidade);
			fscanf(arq_produtos, " %[^\n]s", produto.nome);
			fscanf(arq_produtos, " %[^\n]s", produto.categoria);
			fscanf(arq_produtos, " %[^\n]s", produto.unidade_medida);
			fscanf(arq_produtos, " %[^\n]s", produto.validade);
			fscanf(arq_produtos, "%f", &produto.valor);
			if(cod_p != produto.cod){ // testa se o cod informado se compara ao lido no arq
				if(!feof(arq_produtos)){
					continue;
				}else{
					printf("\n Produto n cadastrado\n");
					break;
				}
			}else{ 
				// continua a venda
				printf("\n DADOS DA VENDA: ");
				printf("\n Nome do produto: %s", produto.nome);
				printf("\n Quantidade atual: %.2f", produto.quantidade);
				printf("\n Valor: %.2f", produto.valor);
				printf("\n\n Informe o quantidade pra venda: ");	
	 			scanf("%f", &quantidade);
	 			if(quantidade <= produto.quantidade){
	 				venda.valor_total = quantidade * produto.valor;
	 				printf("\n VALOR TOTAL: R$ %.2f", venda.valor_total);
	 				printf("\n\n Informe o codigo do cliente: ");
					scanf("%d", &cod_c);
					// inicio da verificao dos clientes
					arq_clientes = fopen("clientes.txt", "r");
					if(arq_clientes == NULL){
						printf("\nERRO AO ABRIR O ARQUIVO");
						exit(1);
					}
					while (!feof(arq_clientes)){ 
						// le todo o arquivo e verifica se existe o cliente informado
						fscanf(arq_clientes, "%d", &cliente.cod);
						fscanf(arq_clientes, " %[^\n]s", cliente.nome);
						fscanf(arq_clientes, " %[^\n]s", cliente.email);
						fscanf(arq_clientes, " %[^\n]s", cliente.telefone);
						fscanf(arq_clientes, " %[^\n]s", cliente.logradouro);
						fscanf(arq_clientes, " %[^\n]s", cliente.cidade);
						fscanf(arq_clientes, " %[^\n]s", cliente.estado);
						fscanf(arq_clientes, " %[^\n]s", cliente.cep);
						fscanf(arq_clientes, " %[^\n]s", cliente.cpf);
						fscanf(arq_clientes, " %[^\n]s", cliente.rg);	
						fscanf(arq_clientes, " %[^\n]s", cliente.data_nascimento);
					if(cod_c != cliente.cod){ // testa se o cod informado se compara ao lido no arq
						if(!feof(arq_clientes)){ 
							continue;
						}else{
							printf("\n Cliente n cadastrado\n");
							fclose(arq_clientes);
							break;
						}
					}else{
						// da baixa no estoque
						fsetpos(arq_produtos, &position);
						float quantidade_venda = quantidade;
						quantidade = produto.quantidade - quantidade;
						fprintf(arq_produtos, " %f", quantidade);
						fclose(arq_produtos);
						// inicio da gravacao do arquivo de vendas
						if(arq_clientes == NULL){
							printf("\nERRO AO ABRIR O ARQUIVO");
							exit(1); // sai do programa
						}
						arq_vendas = fopen("vendas.txt", "a");
						fprintf(arq_vendas, "%s\n", produto.nome);
						fprintf(arq_vendas, "%f\n", quantidade_venda);
						fprintf(arq_vendas, "%f\n", venda.valor_total);
						fprintf(arq_vendas, "%s\n", cliente.nome);
						fclose(arq_vendas);
						printf("\n\n === Venda realizada!!! === \n\n");
						break;
					}
				} fclose(arq_clientes);
					// fim do loop do cliente
				}else{
					printf("\n Quantidade indisponivel!\n");
			}
				break;
			}
		} // fim do loop de verificao do produto
		system("pause");
		system("cls");
}
void listarVendas(){
	vendas venda;
	FILE *arq_vendas;
	arq_vendas = fopen("vendas.txt", "r");
	if(arq_vendas == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO");
		exit(1);
	}
	system("cls");
	printf("\n === Lista de vendas === \n");
	while (1){	
    	fscanf(arq_vendas, " %[^\n]s", venda.produto);
    	if(feof(arq_vendas)){
				break;
			}
		printf("\n PRODUTO: %s", venda.produto);
		
		fscanf(arq_vendas, "%f", &venda.quantidade);
		printf("\n Quantidade: %.2f", venda.quantidade);
		
		fscanf(arq_vendas, "%f", &venda.valor_total);
		printf("\n Valor total: %.2f", venda.valor_total);
		
		fscanf(arq_vendas, " %[^\n]s", venda.cliente);
		printf("\n Cliente: %s\n", venda.cliente);
		
		printf(" -----------------------");
		
	}
	fclose(arq_vendas);
	printf("\n\n === FIM DA LISTA ===\n\n");
	system("pause");
	system("cls");
}
