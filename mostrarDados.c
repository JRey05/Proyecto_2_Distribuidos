#include <stdio.h>

void dibujarLinea1(mano dados){
  int i=0;
  for(i=0;i<5;i++){
    printf(" _____\t");
  }
  printf("\n");
}
void dibujarLinea2(mano dados){
  int i=0;
  for(i=0;i<5;i++){
    switch(dados.dados[i]){
      case '1':{
        printf("|- - -|\t");
      }break;
      case '2':{
        printf("|o - -|\t");
      }break;
      case '3':{
        printf("|o - -|\t");
      }break;
      case '4':{
        printf("|o - o|\t");
      }break;
      case '5':{
        printf("|o - o|\t");
      }break;
      case '6':{
        printf("|o - o|\t");
      }break;
    }
  }
  printf("\n");
}
void dibujarLinea3(mano dados){
  int i=0;
  for(i=0;i<5;i++){
    switch(dados.dados[i]){
      case '1':{
        printf("|- o -|\t");
      }break;
      case '2':{
        printf("|- - -|\t");
      }break;
      case '3':{
        printf("|- o -|\t");
      }break;
      case '4':{
        printf("|- - -|\t");
      }break;
      case '5':{
        printf("|- o -|\t");
      }break;
      case '6':{
        printf("|o - o|\t");
      }break;
    }
  }
  printf("\n");
}
void dibujarLinea4(mano dados){
  int i=0;
  for(i=0;i<5;i++){
    switch(dados.dados[i]){
      case '1':{
        printf("|- - -|\t");
      }break;
      case '2':{
        printf("|- - o|\t");
      }break;
      case '3':{
        printf("|- - o|\t");
      }break;
      case '4':{
        printf("|o - o|\t");
      }break;
      case '5':{
        printf("|o - o|\t");
      }break;
      case '6':{
        printf("|o - o|\t");
      }break;
    }
  }
  printf("\n");
}
