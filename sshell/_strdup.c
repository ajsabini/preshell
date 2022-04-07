#include "main.h"

/**
 * _strdup - copia un string con malloc
 * @str: string a copiar
 * Return: retorna la copia
 */
char *_strdup(char *str)
{
	int i = 0;
	char *copiado = NULL;

	if (str != NULL)
	{
		copiado = (char *)malloc(_strlen(str) + 1);
		if (str != NULL)
		{
		for (i = 0; str[i]; i++)
		{
			copiado[i] = str[i];
		}
		}

	}

	return (copiado);
}
