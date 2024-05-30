/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:06 by alsiavos          #+#    #+#             */
/*   Updated: 2023/11/20 17:10:05 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkarg(char li, va_list ap)
{
	int	result;

	result = 0;
	if (li == 'c')
		result += ft_print_char(va_arg(ap, int));
	else if (li == 's')
		result += ft_print_str(va_arg(ap, char *));
	else if (li == 'd' || li == 'i')
		result += ft_print_int(va_arg(ap, long int));
	else if (li == 'u')
		result += ft_print_usgnint(va_arg(ap, unsigned int));
	else if (li == 'x' || li == 'X')
		result += ft_print_hexa(va_arg(ap, unsigned int), li);
	else if (li == 'p')
		result += ft_print_ptr(va_arg(ap, long int));
	else if (li == '%')
		result += ft_print_char('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if(!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_checkarg(format[i + 1], ap);
			i++;
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (count);
}


/* #include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i;
	unsigned intj;
	char *str;
	void *ptr;
	int j;

	i = -2147483648;
	ft_printf("int min :\n");
	ft_printf("<-ft : %d\n", ft_printf("%d", i));
	printf("<-OG : %d\n", printf("%d", i));
	str = NULL;
	ft_printf("str NULL :\n");
	ft_printf("<-ft : %d\n", ft_printf("%s", str));
	printf("<-OG : %d\n", printf("%s", str));
	ptr = NULL;
	ft_printf("ptr NULL :\n");
	ft_printf("<-ft : %d\n", ft_printf("%p", str));
	printf("<-OG : %d\n", printf("%p", str));
	ft_printf("guillemets :\n");
	ft_printf("<-ft : %d\n", ft_printf(""));
	printf("<-OG : %d\n", printf(""));
	ft_printf("ft_printf(0) :\n");
	ft_printf("<-ft : %d\n", ft_printf(0));
	printf("<-OG : %d\n", printf(0));
	ft_printf("pourcent :\n");
	ft_printf("<-ft : %d\n", ft_printf("%%"));
	printf("<-OG : %d\n", printf("%%"));
	str = "les loulous";
	ptr = str;
	ft_printf("differents flags au milieu d'un phrase :\n");
	ft_printf("<-ft : %d\n", ft_printf("%p Salut %s l'int %% min vaut %d au revoir %s", ptr, str, i, str));
	printf("<-OG : %d\n", printf("%p Salut %s l'int %% min vaut %d au revoir %s", ptr, str, i, str));
	i = 42;
	ft_printf("print X :\n");
	ft_printf("<-ft : %d\n", ft_printf("%X", i));
	printf("<-OG : %d\n", printf("%X", i));
	ft_printf("print x :\n");
	ft_printf("<-ft : %d\n", ft_printf("%x", i));
	printf("<-OG : %d\n", printf("%x", i));
	j = -2147483648;
	ft_printf("print u :\n");
	ft_printf("<-ft : %d\n", ft_printf("%u", j));
	printf("<-OG : %d\n", printf("%u", j));
} */
