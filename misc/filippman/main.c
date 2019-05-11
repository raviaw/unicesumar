#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
Função para ler uma parcela. O operando é utilizado para mostrar uma mensagem para o usuário,
 mas não é feita validação do valor digitado pelo usuário.
*/
int lerParcela(char* mensagem) {
	int parcela;

	printf(mensagem);
	scanf("%d", &parcela);
	return parcela;
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

    if (finale<inicial && parcela>0)
    {
        do
        {
            printf(" Valor final < valor inicial \n");
		    parcela = lerParcela("\n Digite uma parcela < 0! ");
            scanf("%d", &parcela);
        }
        while (finale<inicial && parcela>0);

    }else
            {
                if (parcela<0 && finale>inicial)
                    {
                        printf(" Valor final > valor inicial \n");
		                parcela = lerParcela("\n Digite uma parcela > 0! ");
                    }
                }

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
    return 0;
}
