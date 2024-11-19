# Consignes:
**Créer une fonction imitant printf, qui ne prend en charge que les % suivants: "cspdiuxX%".**

# ft_printf.h
Le fichier ft_printf.h est le header: il contient tous les prototypes et include nécessaires à la compilation de la fonction.

# Makefile
Le Makefile permet de créer une archive "libftprintf.a" (composée des différents fichiers du projet) que l'on pourra utiliser ensuite lors de la compilation avec un fichier qui appelera la fonction ft_printf.

# Fichier ft_printf.c
## ft_printf()
**Reçoit les arguments du main, les traite pour impression et renvoie le nombre de caractères imprimés**

Une variable va_list est créée et initialisée via le va_start. Une variable int est créée et initialisée à 0: elle servira de valeur de retour et devra être passée à chaque fonction qui finira par faire imprimer un caractère afin de l'incrémenter correctement. 
Une boucle while parcourt la chaîne de caractères reçue en argument. Une condition vérifie si le char indexé est un '%'. Si c'est le cas, l'index est incrémenté et la fonction call_ft_by_type est appelée, avec le char indexé et la va_list en argument. Sinon, la fonction putchar_fd est appelée, avec le char indexé également. Que ce soit le cas ou non, l'index est ensuite incrémenté. Une fois la condition de sortie remplie, la va_list est fermée par un va_end. La fonction retourne le nombre de caractères imprimés. 
## call_ft_by_type()
**Appelle la fonction appropriée en fonction du char reçu en argument**

Une variable char* est créée afin de stocker temporairement le résultat d'un éventuel itoa.
Des conditions vérifient si le char reçu est un '%', 'c', 's', 'd' ou 'i', 'u' ou 'x' ou 'X', 'p', ou autre chose. 
**- %**
putchar_fd est appelée avec un '%' en argument.
**- c**
putchar_fd est appelée avec le prochain va_arg de int cast en char.
**- s**
putstr_fd est appelée, avec le prochain va_arg de *char.
**- d OU i**
itoa est appelée, avec le prochain va_arg de int. Puis, putstr_fd est appelée avec le résultat de l'itoa. Ce même résultat est alors free() pour éviter les leaks.
**- u OU x OU X**
printf_unsigned est appelée, avec le prochain va_arg de unsigned int et le char reçu.
**- p**
printf_pointer est appelée, avec le prochain va_arg de unsigned long long.
**- autre**
putchar_fd est appelée avec le char reçu en argument.

# Fichier write.c
## printf_unsigned()
Une variable char* est créée afin de stocker temporairement le résultat de l'itoa_base.
Une condition vérifie si l'unsigned int reçu est égal à 0. Si c'est le cas, putchar_fd est appelée avec '0' en argument. Sinon, des conditions vérifient le type reçu est un 'u', un 'x' ou un 'X'. 
**- u**
itoa_base est appelé avec l'unsigned int reçu et la base 10.
**- x**
itoa_base est appelé avec l'unsigned int reçu et la base 16.
**- X**
itoa_base est appelé avec l'unsigned int reçu et la base 16. Puis, ft_to_upper est appelé avec le résultat de l'itoa_base.

Puis, putstr_fd est appelée avec le résultat de l'itoa. Ce même résultat est alors free() pour éviter les leaks.
## printf_pointer()

