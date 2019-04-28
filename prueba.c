//Librerías a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *archivo_entrada, *archivo_salida;
    int numero_casos;     
    char buffer[100],*palabra1,*palabra, *pal;
    archivo_entrada = fopen("simbolos.txt","r");

    while (!feof(archivo_entrada))
    {
        memset(buffer,0, 100);

        fscanf(archivo_entrada," %119[^\n]",buffer);

        palabra = strtok(buffer," ");
        palabra1 = palabra;

        while(palabra != NULL)
        {
            palabra = strtok(NULL," ");
        	printf("%s\n",palabra);
        	
            if(palabra!=NULL)
            {
            	pal = "";
            	for (int i = 0; i < strlen(palabra); ++i)
            	{
            		pal[i] = palabra[i];
            		printf("%c\n",pal[i]);
            		/*
            		if(strcmp(pal,"if")==0)
            		{
            			printf("IF\n");
            			break;
            		}*/

            	}
       	 		//printf("%s\n",pal);       	 	
            }

        }
        fgetc(archivo_entrada);
    }
    fclose(archivo_entrada);
}
