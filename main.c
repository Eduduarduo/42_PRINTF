# include <stdio.h>
# include "ft_printf.h"



int main()
{
	//ft_printf("DEU certo Krai\n\n");

	int test = 0;
	
    //ft_printf("1 Esse e meu printf");
    //printf("\n2 Esse e o printf do sistema \n\n\n");
    
    ft_printf("3 Meu ft_printf c: ' %-10c ' ==> ", 'P');
	ft_printf("XXXXXXXXX   %-*c ' ==> ", 10, 'P');
    printf("\n4 Sistema c : ' %c ' \n\n", 'P');
    
	ft_printf("5 Meu ft_printf c e c: ' %c ' e ' %c ' e ' %c ' ==> ", 'P', 's', 'x');
    printf("\n6 Sistema c e c : ' %c ' e ' %c ' \n\n", 'P', 's');

   	ft_printf("7 Meu ft_printf d: ' %d ' ==> ", 5);
    printf("\n8 Sistema d : ' %d ' \n\n", 5);


}