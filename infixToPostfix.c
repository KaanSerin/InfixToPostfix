//
// Infix to postfix conversion
//  Using stacks and pointers
//  Created by Kaan on 8.01.2020.
//  Copyright © 2020 Kaan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int tepe;
    int boyut;
    char *dizi;
}s;

s *initialize(int b){
    s *s = malloc(sizeof(s));
    s->dizi = malloc(sizeof(int) * b);
    s->boyut = b;
    s->tepe = 0;
    return s;
}

s *push(s *s1, char a){
    if(s1 == NULL){
        s *s2 = initialize(2);
        s2->dizi[s2->tepe++] = a;
        return s2;
    }
    if(s1->tepe == s1->boyut){
        char *diziBuyuk = malloc(sizeof(char) * s1->boyut + 1);
        for(int i = 0; i < s1->tepe; i++){
            diziBuyuk[i] = s1->dizi[i];
        }
        s1->boyut++;
        free(s1->dizi);
        s1->dizi = diziBuyuk;
    }
    s1->dizi[s1->tepe++] = a;
    
    return s1;
}

char pop(s *s){
    
    if(s->tepe == 0){
        printf("empty stack!\n");
        return -1;
    }
    
    if(s->tepe <= s->boyut / 2){
        char *diziKucuk = malloc(sizeof(char) * s->boyut / 2);
        for(int i = 0; i < s->tepe; i++){
            diziKucuk[i] = s->dizi[i];
        }
        free(s->dizi);
        s->boyut /= 2;
        s->dizi = diziKucuk;
    }
    
    return s->dizi[--s->tepe];
}
void bastir(s *s){
    for(int i = 0; i < s->tepe; i++){
        printf("%c", s->dizi[i]);
    }
    printf("\n");
}

char peek(s *s){
    if(s->tepe > 0)
       return s->dizi[s->tepe - 1];
    else
       return 0;
}

int operatorPrecendece(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '/' || c == '*') return 2;
    if(c == '^') return 3;
    
    return -10;
}

int main(){
    // The infix expression
    char *infix = malloc(sizeof(char) * 40);
    gets(infix);
    
    s *charStack = initialize(2);
    s *operatorStack = initialize(2);
    s *postfixStack = initialize(2);
    
    int i = 0;
    
    while(infix[i] != '\0'){
        if(infix[i] == ' '){
            i++;
            continue;
        }
        
        if((infix[i] >= 65 && infix[i] <= 90) ||
           (infix[i] >= 97 && infix[i] <= 122)){
            /*For testing the input*/charStack = push(charStack, infix[i]);
            postfixStack = push(postfixStack, infix[i]);
        }
        else if(infix[i] == '^' || infix[i] == '('){
            operatorStack = push(operatorStack, infix[i]);
            i++;
            continue;
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/'||
                       infix[i] == '*' || infix[i] == '^'){
            while(operatorPrecendece(infix[i]) <= operatorPrecendece(peek(operatorStack))){
                printf("current operator: %c, operatorStack top: %c\n", infix[i], peek(operatorStack));
                postfixStack = push(postfixStack, pop(operatorStack));
            }
            operatorStack = push(operatorStack, infix[i]);
        }
        
        else if(infix[i] == ')'){
            while(peek(operatorStack) != '('){
                postfixStack = push(postfixStack, pop(operatorStack));
            }
            pop(operatorStack);
        }
        
        else{
            printf("Invalid symbol!\n");
            exit(1);
        }
        i++;
    }
    
    //printf("%s\n", operatorStack->dizi);
    while(operatorStack->tepe > 0){
        postfixStack = push(postfixStack, pop(operatorStack));
    }
    
    bastir(postfixStack);
    return 0;
}
