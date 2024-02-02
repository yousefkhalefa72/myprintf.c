/*
 * File       : my_printf.c
 * Author     : Yousef_Khalefa
 * linkedin   : https://www.linkedin.com/in/yousef-khalefa/
 * created in : 21-sep-2023
 *
 * description:-
 *
 * 1- This is simple implementation of printf function(exercise on variadic function).
 *
 * 2- return of my_printf is num of chars displayed
 *
 * 3- putchar can handle \x
 *
 * 4- i used fprintf to count (int,float,string) out digits
 *
 * 5- my_printf can handle %f(float) %i%d(int) %c(char) %s(string)
 *
 * 6- wait for my_sprintf
 *
 * 7- Thanks
 */


#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
    va_list args;                   //represents a list of variable arguments
    va_start(args, format);         //ready to access the variable arguments
    unsigned int count = 0;         //return of printf is num of printed chars

    while (*format != '\0')
    {
        if (*format != '%')
        {
            putchar(*format);       //out char if not '%'
            count++;                //number of printed chars inc by 2
        }
        else                        // Handle format specifiers
        {
            format++;               //symbol after %
            switch (*format)
            {
            case 'd':
            case 'i':
                count += fprintf(stdout, "%d", va_arg(args, int));
                break;
            case 'c' :
                putchar(va_arg(args,char *));//Fetch char argument
                count++;
                break;
            case 's':
                count += fprintf(stdout, "%s", va_arg(args, char *));
                break;
            case 'f':
                count += fprintf(stdout, "%f", va_arg(args, double));
                break;
            default:                        // Handle unknown format specifiers
                putchar('%');               //print %
                putchar(*format);           // print the unknown symbol
                count += 2;                 //number of chars out inc by 2 due to '%' and the symbol
                break;
            }
        }
        format++;                           //next symbol
    }
    va_end(args);                           //clean up the va_list objec

    return count;                           //return of printf is num of printed chars
}
