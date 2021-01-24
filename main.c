#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <zconf.h>
#include <string.h>

int main(int argc, char *argv[]) {
//EJERCICIO 1
int reads_split(int fin, char* buff, int maxlen, char* ch_end){

    int i = 0, oneread = 1;  
    char c = '.'; 

    while(c != ' ' && c != '\n' && oneread == 1 && i < maxlen ) { 

        oneread = read(fin , &c , 1 );
        if(c!=' ' && c!='\n' && oneread == 1 ) { 
            buff[i] = c ; 
            i ++; 
        }
    }
    *ch_end = c; 
    if( i < maxlen ) buff[i] = '\0'; 
    return i ; 
}

int file = open(argv[1], O_CREAT | O_RDWR, 0644);

int cont_words = 0;
int cont_lines = 0;

char buff[80];
char ch_end;


while(reads_split(file, buff, 80, &ch_end) > 0){
  printf("%s", buff);
  printf("%c", ch_end);

  if(ch_end == ' '){
    cont_words++;
  }
  if(ch_end == '\n'){
    cont_lines++;
  }
}

printf("\nNúmero de palabras: %d\n", cont_words);
printf("Número de líneas: %d\n", cont_lines);


//EJERCICIO 2
void ∗malloc(size_t size)
void ∗memcpy (void ∗dest, const void ∗ src,int n) ;




}