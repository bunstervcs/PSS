#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t1.h"

uint borrar_bits(uint x, uint pat, int len){
    int aux=len; 
    uint mask=~(-1<<aux);
    while(aux<=15){
                       
            uint p=x&mask;
            if(p==pat){/*esto quiere decir que el patron se presento*/
                x^=pat;
                pat<<=len;
                mask<<=len;    
                aux+=len;
            }
            else{
                pat<<=1;
                mask<<=1;
                aux++;
            } 
    }
    
    return x;
} 

char *reemplazo(char *s, char c, char *pal){
    char *p=s;    
    char *q=pal;
    int slen=0;
    int palen=0;
    while(*q!='\0'){    
        palen++;
        q++;
        }    
    while(*p!='\0'){
        if(*p==c){
            slen+=palen;
            p++;
        }
        else{
            slen++;
            p++;
        }
    }
    char *re=malloc(slen*sizeof(char));
    char *res=re;
    char *fin=s;
    while(*fin!='\0'){
        if(*fin==c){
            int k;
            char *r=pal;
            for(k=0;k<palen;k++){
                *res=*r;
                res++;      
                r++;
            }                    
            fin++;
        }
        else{
            *res=*fin;
            fin++;
            res++;  
        }
    }
    if(*fin=='\0'){
        *res=*fin;
    }
       
    return re;
}

void reemplazar(char *s, char c, char *pal){
        
    char *pS =s;
    char *qP=pal;
    int pallen=0;
    char *slen=s;
    int len;
    if(*qP=='\0'){
        while(*pS!='\0'){
            if(*pS==c){
                pS++;
            }
            else{
                *slen=*pS;
                slen++;
                pS++;
            }
        }
        if(*pS=='\0'){
            *slen=*pS;
        }                    
    }

    while(*qP!='\0'){    
        pallen++;
        qP++;
    }
 
    if(pallen==1){
        char *r=pal;
        while(*pS!='\0'){
            if(*pS==c){
                *pS=*r;
                pS++;
                
            }
            else{
                pS++;
            }
        }
    }

    else{
        while(*pS!='\0'){/*mientras no estudie el final*/
            if(*pS == c){
                slen+=pallen;
                len+=pallen;
                pS++;
            }
            else{
                slen++;
                len++;
                pS++;
            }
        }/*ahora p esta al final del string s y slen esta ubicado en la nueva posicion final*/
        while(len!=0){
            if(*pS==c){
                int k;
                int i;
                char *r=pal;
            for(i=0;i<pallen-1;i++){
                r++;
                }
            for(k=0;k<pallen;k++){
                *slen=*r;
                slen--;  
                len--;    
                r--;
                }
            pS--;
            }
            else{
                *slen=*pS;
                pS--;
                slen--;
                len--;
            }
        }
    }
}                              
