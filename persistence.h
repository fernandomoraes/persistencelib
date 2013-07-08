#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef PERSISTENCE_H
#define PERSISTENCE_H


#define ROW 100
#define CONFIG "tables-config.conf"
#define WHERE 3

/*
    Created by Fernando S. de Moraes
    https://github.com/fersmoraes
*/



int tableExists(FILE *arq, char *tableNome){
    char *table;
    char row[ROW];
    char aux[strlen(tableNome)+1];
    
    strcpy(aux, tableNome);
    strcat(aux, "$");
    if(arq){
        while(!feof(arq)){			  
            fgets(row, ROW, arq);
                if(strstr(row, aux)){
                   return 1;               
                   }
        }
    }
        
    return 0;
    }
    
int optionItems(char *select){
	int num=0;
	char * itemTok;
    char item[strlen(select)+1];
    strcpy(item, select);
    
	itemTok = strtok(item, " ");
	while(itemTok){
	   num++;
	   itemTok = strtok(NULL, " ");			   
       }
	return num;
	}
	

    
int tableColummAuto(char *tableNome){
	
	FILE *arq = fopen(CONFIG, "r");

    char row[ROW];
    char aux[strlen(tableNome)+1];
    
    strcpy(aux, tableNome);
    strcat(aux, "$");
    
    arq = fopen(CONFIG, "r");
	if(arq){
		while(!feof(arq)){
            fgets(row, ROW, arq);
            if(strstr(row, aux) && strstr(row, "*")){
				return 1;	   
                }
			}	
	    }
   fclose(arq);	
   return 0;
  	
   }
   
int tableRows(char *tableNome){
	int rows = -1;
	char row[ROW];
	char table[strlen(tableNome)+4];
	strcpy(table, tableNome);
	strcat(table, ".db");
	FILE *arq = fopen(table, "r");
	if(arq){
		while(!feof(arq)){
			fgets(row, ROW, arq);			  
		 	rows++;			  
            }	
	    }
	    fclose(arq);
	    return rows;
	}
    
int tableColumns(char *tableNome){
	
    FILE *arq = fopen(CONFIG, "r");
    if(tableExists(arq, tableNome) != 1){
        return 0;                
        }
	
    int columns=0;
    char row[ROW];
    char aux[strlen(tableNome)+1];
    
    strcpy(aux, tableNome);
    strcat(aux, "$");
    
    arq = fopen(CONFIG, "r");
	if(arq){
		while(!feof(arq)){
            fgets(row, ROW, arq);
            if(strstr(row, aux)){
				int i;
				for(i=0;i<strlen(row); i++){
    			    if(row[i] == ' '){
		  			    columns++;
						  }
					}
				break;		   
                }
			}	
	    }
   fclose(arq);	
   return columns;
   
	}

int createTable(char *tableNome, char *desc){
    FILE *arq = fopen(CONFIG,"a+t");
    if(!arq || tableExists(arq, tableNome) == 1){
         return 0;
         }
         
    char config[strlen(tableNome)+strlen(desc)+4];
    strcpy(config, tableNome);
    strcat(config, "$");
    strcat(config," ");
    strcat(config,desc);
    strcat(config,"\n");
    fprintf(arq, config);
    
    fclose(arq);    
    }
    
int insertInto(char *tableNome, ...){
	int columns = tableColumns(tableNome);
	if(columns == 0){
		return 0;	   
        }
	
	char table[strlen(tableNome)+4];
	strcpy(table, tableNome);
	strcat(table, ".db");
	
	FILE *arq = fopen(table, "a+t");
	
	if(!arq){
		return 0;
        }

	//caso tiver coluna autoincrementa
	if(tableColummAuto(tableNome)==1){
        columns -= 1;
        char row[ROW];
        char *rowSplit;
        int value;
	    if(arq){
			while(!feof(arq)){
	            fgets(row, ROW, arq);					  
	            }
		    rowSplit = strtok(row, "|");
		    if(tableRows(tableNome)>0){
			   value = atoi(rowSplit); 
		        }else {
					 value = 0; 
	                 }
	        value++;
	        itoa (value,rowSplit,10);
	        fprintf(arq, rowSplit);
	        fprintf(arq, "|");
		    }
        }	
	
	va_list args;
	va_start(args, tableNome);
	
	

	int i;
	for(i=0;i<columns;i++){
		fprintf(arq, va_arg(args, char *));	
		fprintf(arq, "|");			   
        }
    fprintf(arq, "\n");
    fclose(arq);
    va_end(args);

	return 1;
	    
    }
    
    
char* selectFrom(char *tableNome, int n, ...){
	  	  
	  FILE *arq = fopen(CONFIG,"a+t");
      if(!arq || tableExists(arq, tableNome) == 0){
         return NULL;
         }

    // monta os parametros passados.
      va_list args;
	  va_start(args, n); 
	  char *parameters[n];
	  int i;
	  for(i=0;i<n;i++){
	      parameters[i] = va_arg(args, char *);
	      }
      
	  va_end(args);
	  
	  
	  char *columm = parameters[0];
	  char *condition = parameters[1];
	  char *logics = parameters[2];
	  char *where = parameters[3];
	  
	  
	  int numSelect = optionItems(columm);
	  char *itens[numSelect]; 
	  
 	  	  
      if(n==1){
		 	  	char * itemTok;
	            char item[strlen(columm)+1];
                strcpy(item, columm);
 	            itemTok = strtok(item, " ");
	            int i;
	            i=0;
	            while(itemTok){
                    itens[i] = itemTok;
                    strcpy(itens[i], itemTok);
	                itemTok = strtok(NULL, " ");

     	            i++;			   
                   }
 		 }
	                printf("%s\n", itens[0]);
	  }
    


#endif
