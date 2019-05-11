#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
Fun��o para ler uma parcela. O operando � utilizado para mostrar uma mensagem para o usu�rio,
 mas n�o � feita valida��o do valor digitado pelo usu�rio.
*/
int lerParcela(char* mensagem) {
	int parcela;

	printf(mensagem);
	scanf("%d", &parcela);
	return parcela;
}

/*
Fun��o para ler uma parcela at� obter um valor correto.
*/
int lerParcelaCorreta(char* mensagemErro, char* mensagemLeituraParcela, char operador) {
	do {
		printf(mensagemErro);
		int parcela = lerParcela(mensagemLeituraParcela);
		if (operador == '<') {
			if (parcela < 0) {
				return parcela;
			}
		} else if (operador == '>') {
			if (parcela > 0) {
				return parcela;
			}
		} else {
			printf("ERRO PROGRAMADOR - OPERADOR INVALIDO - %c", operador);
			return 0;
		}
	} while(1);
}

int main ()
{
    int i, inicial, parcela, finale;
    char sentido;
    
    printf ("\n Qual o valor inicial? ");
    scanf  ("%d", &inicial);
    printf (" Qual o valor final? ");
    scanf  ("%d", &finale);
    parcela = lerParcela(" Contar de quanto em quanto? ");

	//
	// Acerta o valor da parcela para permitir que o loop chegue ao fim.
	//
    if (finale<inicial && parcela>0)
    {
    	parcela = lerParcelaCorreta(" Valor final < valor inicial \n", "\n Digite uma parcela < 0! ", '<');
    }else if (finale>inicial && parcela<0)
    {
    	parcela = lerParcelaCorreta(" Valor final > valor inicial \n", "\n Digite uma parcela > 0! ", '>');
    }

	//
	// Voc� n�o precisa verificar todas as outras condi��es. O c�digo n�o vai executar at� aqui se a parcela n�o estiver com o valor correto.
	//    
    if (parcela < 0) {
        for (i = inicial; i>=finale; i+=parcela){
            printf(" %d \n", i);
        }
	} else {
        for (i=inicial;i<=finale;i+=parcela){
            printf(" %d \n", i);
        }
	}

	/*
    //inicio posit ou negat ; parcela <0; final < inicial, ou seja, contagem regressiva.
    if (parcela<0 && inicial>finale){
            for (i = inicial; i>=finale; i+=parcela){
                printf(" %d \n", i);
            }
        }else
            {   //inicio posit ou negat; parcela > 0; final > inicial, ou seja, contagem progressiva.
                if (parcela>0 && inicial<finale){
                        for (i=inicial;i<=finale;i+=parcela){
                            printf(" %d \n", i);
                        }
                    } else
                        {
                            printf("Erro! \n");
                            printf("O valor da parcela nao gera o resultado pretendido! \n\n");
                        }
            }
	*/
    return 0;
}
