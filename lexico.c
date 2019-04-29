//Librerías a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analizarArchivo();
int main(int argc, char const *argv[])
{
    if(argc > 3)
    {
        printf("Demasiados parametros\nUso: lexico.exe archivo_entrada archivo_salida\n");
        exit(1);
    }
    else if(argc <= 2)
    {
        printf("Faltan parametros\nUso: lexico.exe archivo_entrada archivo_salida\n");
        exit(1);
    }
    analizarArchivo(argv[1],argv[2]);
}
void analizarArchivo(const char *nombre_entrada,const char *nombre_salida)
{
    FILE *archivo_entrada, *archivo_salida;
    char sintaxis[54][10] = {"main","(",")","{","}",",",";","auto","extern","register","static","*","=","break","continue","default",":","do","while","for","goto","if","else","return","&","-","|","~","sizeof","short","unsigned","long","int","float","char","double","==","!=","<",">","<=",">=","&&","||","!","?","+","/","%","^","<<",">>","++","--"};
    char sintaxisMayus[54][10] = {"MAIN","(",")","{","}",",",";","AUTO","EXTERN","REGISTER","STATIC","*","=","BREAK","CONTINUE","DEFAULT",":","DO","WHILE","FOR","GOTO","IF","ELSE","RETURN","&","-","|","~","SIZEOF","SHORT","UNSIGNED","LONG","INT","FLOAT","CHAR","DOUBLE","==","!=","<",">","<=",">=","&&","||","!","?","+","/","%","^","<<",">>","++","--"};
    char buffer[500],*palabra,*pal;

    archivo_entrada = fopen(nombre_entrada,"r");
    archivo_salida = fopen(nombre_salida,"r");

    if(archivo_entrada==NULL){
    printf("Error: El archivo de entrada no existe.\n");
    exit(1);
    }
    if(archivo_salida!=NULL){
        printf("Error: El archivo de salida ya existe.\n");
        exit(1);
    }
    fclose(archivo_salida);
    archivo_salida = fopen(nombre_salida,"w");


    while (!feof(archivo_entrada))
    {
        memset(buffer,0, 500);

        fscanf(archivo_entrada,"%[^\n]",buffer);

        palabra = strtok(buffer," ");
        while(palabra != NULL)
        {
            pal = (char*)calloc(strlen(palabra),sizeof(char));
            int j = 0;
            int pivote = 0;
            if(palabra!=NULL)
            {
                for (int i = 0; i < strlen(palabra); ++i)
                {
                    pal[j] = palabra[i];
                    
                    for (int k = 0; k < 54; ++k)
                    {
                        if(strcmp(pal,sintaxis[k])==0)
                        {
                    /*=*/   if(k ==12){
                                if(palabra[i+1]=='='){
                                    k = 36;
                                    i++;
                                }
                            }
                    /*&*/   else if(k==24){
                                if(palabra[i+1]=='&'){
                                    k = 42;
                                    i++;
                                }
                            }
                    /*-*/   else if(k==25)
                            {
                                if(palabra[i+1]=='-'){
                                    k = 53;
                                    i++;
                                }
                            }
                    /*|*/   else if (k ==26){
                                if(palabra[i+1]=='|'){
                                    k = 43;
                                    i++;
                                }
                            }

                    /*<*/   else if(k == 38){
                                if(palabra[i+1]=='='){
                                    k = 40;
                                    i++;
                                }
                                else if(palabra[i+1]=='<'){
                                    k = 50;
                                    i++;
                                }
                            }
                    /*>*/   else if(k == 39){
                                if(palabra[i+1]=='='){
                                    k = 41;
                                    i++;
                                }
                                else if(palabra[i+1]=='>'){
                                    k = 51;
                                    i++;
                                }
                            }
                    /*!*/   else if(k == 44){
                                if(palabra[i+1]=='='){
                                    k = 37;
                                    i++;
                                }
                            }
                    /*+*/   else if(k == 46){
                                if(palabra[i+1]=='+'){
                                    k = 52;
                                    i++;
                                }
                            }
                            fprintf(archivo_salida, "%s\n",sintaxisMayus[k]);
                            j= -1;
                            k = 54;
                            pivote = i;
                            pal = (char*)calloc(strlen(palabra),sizeof(char));
                        
                        }
                    }
                    if(i >= strlen(palabra)-1 && pivote<strlen(palabra))
                    {   
                        pivote++;
                        i = pivote-1;
                        j= -1;
                        pal = (char*)calloc(strlen(palabra),sizeof(char));

                    }
                    
                    j++;

                }
            }
            palabra = strtok(NULL," ");

        }
        fgetc(archivo_entrada);
    }
    fclose(archivo_entrada);
    fclose(archivo_salida);
}
