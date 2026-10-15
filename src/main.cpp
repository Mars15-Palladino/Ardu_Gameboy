#include <Arduino.h>

// put function declarations here:
void printMenu();
void jogoDaVelha();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  printMenu();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char opcao = Serial.read();
    //Serial.print(opcao);
    switch(opcao){
      case '1':
        Serial.println("Jogo da Velha");
        jogoDaVelha();
        break;
      case '2':
        Serial.println("Jogo da Forca");
        break;
      case '3':
        Serial.println("Dinossauro");
        break;
      default:
        Serial.println("Opção inválida");
        Serial.println("Escolha uma opção válida");
        Serial.println("----------------------------");
        break;
    }
    printMenu();
  }
}

// put function definitions here:
void printMenu() {
  Serial.println("-------ARDU-GAMEBOY-------");
  Serial.println("============================");
  Serial.println("----------Jogos-----------");
  Serial.println("    1 - Jogo da Velha");
  Serial.println("    2 - Jogo da Forca");
  Serial.println("    3 -  Dinossauro");
  Serial.println("    0 -     Sair");
  Serial.println("============================");
  Serial.println("============================");
}
//jogos abaixo
void jogoDaVelha() {
  // Implementação do jogo da velha
  char area_Do_Jogo[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}}; //matriz do jogo
  Serial.println("----------------------------");
  //Serial.println("\n"); erro de espaços 

  for(byte linha=0;linha<3;linha++){
    for(byte coluna=0;coluna<3;coluna++){
      Serial.print(area_Do_Jogo[linha][coluna]);
      Serial.print(" ");
    }
    Serial.println();
  }
  char X_Jogador = 'X';
  while(true){
     Serial.println("Escolha uma posição de 0 a 8: ");
      char escolha;
      while(Serial.available()==0){//aguardando o usuário escolher a posição
      }
      escolha = Serial.read();
      //Serial.print(escolha); debug
        
          if(escolha >= '0' && escolha <='8'){//verificando se a escolha é válida
            byte posicaoEscolhida = escolha - '0'; //conversão de char para int
            Serial.print("Posição escolhida: ");
            Serial.println(posicaoEscolhida);

            byte linhaEscolhida = posicaoEscolhida / 3;//
            byte colunaEscolhida = posicaoEscolhida % 3;//conversão de int para linha e coluna


            if(area_Do_Jogo[linhaEscolhida][colunaEscolhida] != '-'){
              Serial.println("Posição já ocupada, escolha outra posição.");
            }
            else{
              Serial.println("Posição Livre");
              area_Do_Jogo[linhaEscolhida][colunaEscolhida] = X_Jogador;//marcando a posição escolhida com X

              if(X_Jogador == 'X'){
                X_Jogador = 'O';
              }
              else{
                X_Jogador = 'X';
              }
            
              if(area_Do_Jogo[0][0] != '-' && area_Do_Jogo[0][0] == area_Do_Jogo[0][1] && area_Do_Jogo[0][1] == area_Do_Jogo[0][2]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[0][0]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
              if(area_Do_Jogo[1][0] != '-' && area_Do_Jogo[1][0] == area_Do_Jogo[1][1] && area_Do_Jogo[1][1] == area_Do_Jogo[1][2]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[1][0]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
              if(area_Do_Jogo[2][0] != '-' && area_Do_Jogo[2][0] == area_Do_Jogo[2][1] && area_Do_Jogo[2][1] == area_Do_Jogo[2][2]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[2][0]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
              if(area_Do_Jogo[0][0] != '-' && area_Do_Jogo[0][0] == area_Do_Jogo[1][0] && area_Do_Jogo[1][0] == area_Do_Jogo[2][0]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[0][0]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
              if(area_Do_Jogo[0][1] != '-' && area_Do_Jogo[0][1] == area_Do_Jogo[1][1] && area_Do_Jogo[1][1] == area_Do_Jogo[2][1]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[0][1]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
              if(area_Do_Jogo[0][2] != '-' && area_Do_Jogo[0][2] == area_Do_Jogo[1][2] && area_Do_Jogo[1][2] == area_Do_Jogo[2][2]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[0][2]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
              if(area_Do_Jogo[0][0] != '-' && area_Do_Jogo[0][0] == area_Do_Jogo[1][1] && area_Do_Jogo[1][1] == area_Do_Jogo[2][2]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[0][0]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
              if(area_Do_Jogo[0][2] != '-' && area_Do_Jogo[0][2] == area_Do_Jogo[1][1] && area_Do_Jogo[1][1] == area_Do_Jogo[2][0]){
                Serial.print("O jogador ");
                Serial.print(area_Do_Jogo[0][2]);
                Serial.println(" venceu!");
                Serial.println("----------------------------");
                break;
              }
            } 
          }
          for(byte linha=0;linha<3;linha++){
            for(byte coluna=0;coluna<3;coluna++){
              Serial.print(area_Do_Jogo[linha][coluna]);
              Serial.print(" ");
            }
            Serial.println();
          }
  }
} 