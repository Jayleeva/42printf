# Consignes:
**Créer une fonction imitant printf, qui ne prend en charge que les % suivants: "cspdiuxX%".**

# Fonction variadique
Une fonction variadique peut recevoir un nombre indéterminé d'arguments. Pour pouvoir les gérer, on utilise va_list, va_copy, va_start, va_arg, va_end.
- **va_list :** type de variable qui liste les arguments d'une fonction variadique. On écrit: ``va_list list_name;``
- **va_copy :** 
- **va_start :** macro qui permet d'initialiser la liste au premier argument reçu. Il est nécessaire de l'utiliser avant de faire appel à va_arg. On écrit: ``va_start(list_name, arg0)``
- **va_arg :** macro qui permet d'accéder au prochain argument de la liste d'un type donné. On écrit: ``va_arg(list_name, arg_type)``
- **va_end :** macro qui permet de fermer la liste. Il est nécessaire de l'utiliser une fois qu'on a accédé à tous nos arguments. On écrit: ``va_end(list_name)``

# Hexadécimaux
Un chiffre hexadécimal est compté en base 16 ``0123456789abcdef`` ou ``0123456789ABCDEF`` plutôt qu'en base 10 ``0123456789``. Quand on arrive à 9 et qu'on incrémente de 1, au lieu de passer à ``10``, on passe à ``a`` ou ``A``. Quand on arrive à 15 (écrit f ou F) et qu'on incrémente de 1, au lieu de passer à ``16``, on passe à ``1a`` ou ``1A``.

# ft_printf.h
Le fichier ft_printf.h est le header: il contient tous les prototypes et include nécessaires à la compilation de la fonction.

# Makefile
Le Makefile permet de créer une archive "libftprintf.a" (composée des différents fichiers du projet) que l'on pourra utiliser ensuite lors de la compilation avec un fichier qui appelera la fonction ft_printf.

# Fichier ft_printf.c
## ft_printf()
**Reçoit les arguments du main, les traite pour impression et renvoie le nombre de caractères imprimés**

Une variable va_list est créée et initialisée via le va_start. Une variable int est créée et initialisée à 0: elle servira de valeur de retour et devra être passée à chaque fonction qui fera appel à putchar_fd afin de compter le nombre de caractères effectivement imprimés. 
Une boucle while parcourt la chaîne de caractères reçue en argument. Une condition vérifie si le char indexé est un '%'. Si c'est le cas, l'index est incrémenté et la fonction call_ft_by_type est appelée, avec le char indexé et la va_list en argument. Sinon, la fonction putchar_fd est appelée, avec le char indexé également. Que ce soit le cas ou non, l'index est ensuite incrémenté. Une fois la condition de sortie remplie, la va_list est fermée par un va_end. La fonction retourne le nombre de caractères imprimés. 
## call_ft_by_type()
**Appelle la fonction appropriée en fonction du char reçu en argument**

Une variable char* est créée afin de stocker temporairement le résultat d'un éventuel itoa.
Des conditions vérifient si le char reçu est un '%', 'c', 's', 'd' ou 'i', 'u' ou 'x' ou 'X', 'p', ou autre chose. 
- **% :**
putchar_fd est appelée avec un '%' en argument.
- **c :**
putchar_fd est appelée avec le prochain va_arg de int cast en char.
- **s :**
putstr_fd est appelée, avec le prochain va_arg de *char.
- **d** OU **i :**
itoa est appelée, avec le prochain va_arg de int. Puis, putstr_fd est appelée avec le résultat de l'itoa. Ce même résultat est alors free() pour éviter les leaks.
- **u** OU **x** OU **X :**
printf_unsigned est appelée, avec le prochain va_arg de unsigned int et le char reçu.
- **p :**
printf_pointer est appelée, avec le prochain va_arg de unsigned long long.
- **autre :**
putchar_fd est appelée avec le char reçu en argument.

# Fichier write.c
## printf_unsigned()
**Transforme les unsigned en chaîne de caractères et les envoie à l'impression**

Une variable char* est créée afin de stocker temporairement le résultat de l'itoa_base.
Une condition vérifie si l'unsigned int reçu est égal à 0. Si c'est le cas, putchar_fd est appelée avec '0' en argument. Sinon, des conditions vérifient le type reçu est un 'u', un 'x' ou un 'X'. 
- **u :**
itoa_base est appelée avec l'unsigned int reçu et la base 10.
- **x :**
itoa_base est appelée avec l'unsigned int reçu et la base 16.
- **X :**
itoa_base est appelée avec l'unsigned int reçu et la base 16. Puis, ft_to_upper est appelé avec le résultat de l'itoa_base.

Puis, putstr_fd est appelée avec le résultat de l'itoa. Ce même résultat est alors free() pour éviter les leaks.
## printf_pointer()
**Transforme le pointeur en chaîne de caractères et l'envoie à l'impression**

Une variable char* est créée afin de stocker temporairement le résultat de l'itoa_base.
Une condition vérifie si l'unsigned long long reçu est égal à 0. Si c'est le cas, putstr_fd est appelée avec "0x0" en argument. Sinon, putstr_fd est appelée une première fois avec "0x" en argument, puis itoa_base est appelée avec l'unsigned long long reçu et la base 16 en arguments, et enfin putstr_fd est rappelée avec le résultat de l'itoa_base. Ce même résultat est alors free() pour éviter les leaks.

## to_upper()
**Transforme les lettres minuscules de la chaîne reçue en majuscules correspondantes**

Une boucle while parcourt la chaîne de caractères reçue. Une condition vérifie si le char indexé est une lettre minuscule: si c'est le cas, le char indexé est décrémenté de 32 afin de le changer en la lettre majuscule correspondante. Dans tous les cas, l'index est incrémenté. Une fois la condition de sortie remplie, la fonction s'arrête et retourne la chaîne de caractères transformée.

## putstr_fd()
**Envoie chaque caractère de la chaîne reçue à putchar_fd**

Une condition vérifie si la chaîne reçue est nulle. Si c'est le cas, la fonction putstr_fd est rappelée avec "(null)" en argument, puis la fonction s'arrête et retourne le nombre de caractères imprimés. Sinon, une boucle while appelle putchar_fd avec le char indexé en argument, puis incrémente l'index. Une fois la condition de sortie remplie, la fonction s'arrête et retourne le nombre de caractères imprimés.

## putchar_fd()
**Imprime le char reçu en argument et incrémente le compteur de caractères imprimés**

Le char est passé à write(). Le nombre de caractères imprimés est incrémenté. La fonction retourne ce nombre.

# Fichier itoa.c
**Transforme l'int reçu en chaîne de caratères et retourne cette dernière**

Même fonction que dans la libft.

# Fichier itoa_base.c
**Transforme l'unsigned int reçu en chaîne de caratères et retourne cette dernière**

Même chose qu'itoa, sans la prise en charge d'int négatifs et donc de INT_MIN; de plus, les divisions et modulo par 10 d'itoa sont ici faites par la base reçue en argument. Les hexadécimaux sont pris en charge par des conditions qui vérifient si le nombre actuel est plus grand que 9: si c'est le cas, au lieu de prendre la valeur n % base + '0' (ex. : 123 % 10 = 3; 3 + 48 = 51; int 51 = '3'), le char indexé prend la valeur n % base + 'a' - 10 (ex. : 2c % 16 = 12; 12 + 97 - 10 = 99; int 99 = 'c'). 
