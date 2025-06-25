Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf with the following constraints:

- It will manage only the following conversions: s,d, and x

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Your function must not leak.


Exemples of the function output:

call: ft_printf("Hello %s\n", "toto");
out:Hello toto$

call: ft_printf("Magic %s is %d", "number", 42);
out:Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out:Hexadecimal for 42 is 2a$

Warning: Your function must not have any leaks, this will be checked during moulinette

Имя назначения: ft_printf
Ожидаемые файлы: ft_printf.c
Разрешенные функции: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Напишите функцию с именем `ft_printf`, которая будет имитировать настоящую printf со следующими ограничениями:

- Она будет управлять только следующими преобразованиями: s, d и x

Ваша функция должна быть объявлена ​​следующим образом:

int ft_printf(const char *, ... );

Перед началом работы мы советуем вам прочитать `man 3 printf` и `man va_arg`.

Чтобы протестировать вашу программу, сравните ваши результаты с настоящей printf.

Ваша функция не должна давать утечек.

Примеры вывода функции:

call: ft_printf("Hello %s\n", "toto");
out:Привет toto$

call: ft_printf("Волшебный %s — %d", "number", 42);
out:Волшебное число — 42%

call: ft_printf("Шестнадцатеричный для %d — %x\n", 42, 42);
out:Шестнадцатеричный для 42 это 2a$

Предупреждение: Ваша функция не должна иметь никаких утечек, это будет проверено во время moulinette