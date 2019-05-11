#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int lerParcela(char operando) {
	int parcela;

	printf("Digite uma parcela %c 0: ", operando);
	scanf("%d", &parcela);
	return parcela;
}

int main ()
{
    int i, inicial, parcela, finale;
    char sentido;
    
    int parcela1 = lerParcela('<');

    printf ("\n Qual o valor inicial? ");
    scanf  ("%d", &inicial);
    printf (" Qual o valor final? ");
    scanf  ("%d", &finale);
    printf (" Contar de quanto em quanto? ");
    scanf  ("%d", &parcela);

    if (finale<inicial && parcela>0)
    {
        do
        {
            printf(" Valor final < valor inicial \n");
            printf("\n Digite uma parcela < 0! ");
            scanf("%d", &parcela);
        }
        while (finale<inicial && parcela>0);

    }else
            {
                if (parcela<0 && finale>inicial)
                    {
                        printf(" Valor final > valor inicial \n");
                        printf("\n Digite uma parcela > 0!");
                        scanf("%d", &parcela);
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
