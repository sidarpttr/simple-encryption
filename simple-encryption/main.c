#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char table[26];

void create_table(){

    for(int i = 0; i < 26; i++)
        table[i] = 65 + i;
    
}

char encrypt(char text, int key){

    text = toupper(text);

    for(int i = 0; i < 26; i++){
        if(text == table[i]){
            text = table[(i+key)%26];
            break;
        }
    }
    
    return text;
    
}

char decrypt(char text, int key){

    text = toupper(text);
    for(int i = 0; i < 26; i++){
        if(table[i] == text){
            text = table[(i+26-key)%26];
            break;
        }
    }

    return text;
}


int main(){

    FILE *read, *write;
    char karakter;
    create_table();
    
    read = fopen("read.txt","r");
    if(read == NULL){
        perror("error.");
        fclose(read);
        return EXIT_FAILURE;
    }

    write = fopen("write.txt","w");
    if(write == NULL){
        perror("error.");
        fclose(write);
        return EXIT_FAILURE;
    }

    while((karakter = fgetc(read)) != EOF){
        karakter = decrypt(karakter,12);
        fprintf(write, "%c" ,karakter);
    }

    fclose(write);
    fclose(read);

    return 0;
}
