#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void playspace(char board[]);
void playerturn(char board[],char player);
void compturn(char board[],char computer);
int win(char board[],int gameover,char player);
int main(){
   char board[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',};
   int gameover=0;
   char player;
   char computer;
   
   do{
      cout<<"Choose a move: X or O:";
      cin>>player;
      player=toupper(player);
      if(player!='X'&&player!='O'){
         cout<<"Choose a valid move\n";
      }
   }while(player!='X'&&player!='O');
   if (player=='X'){
      computer='O';
      do{
      playspace(board);
      playerturn(board,player);
      gameover=win(board,gameover,player);
      if(gameover==1){
         break;
      }
      compturn(board,computer);
      gameover=win(board,gameover,player);
      }while(gameover!=1);
   }
   else{
      computer='X';
      while(gameover==0){
      compturn(board,computer);
      gameover=win(board,gameover,player);
      if(gameover==1){
         break;
      }
      playspace(board);
      playerturn(board,player);
      gameover=win(board,gameover,player);
      };
   }
   return 0;
}
void playspace(char board[]){
   printf(" ___ ___ ___ \n");
   printf("|   |   |   |\n");
   printf("| %c | %c | %c |\n",board[0],board[1],board[2]);
   printf("|___|___|___|\n");
   printf("|   |   |   |\n");
   printf("| %c | %c | %c |\n",board[3],board[4],board[5]);
   printf("|___|___|___|\n");
   printf("|   |   |   |\n");
   printf("| %c | %c | %c |\n",board[6],board[7],board[8]);
   printf("|___|___|___|\n");
}
void playerturn(char board[],char player){
   int i=0;
   char input;
   do{
   cout<<"Choose a slot number 1-9 to put "<<player<<"\n";
   cin>>i;
   i--;
   if(board[i]!=' '||(i<0||i>8)){
   	cout<<"Choose a valid unoccupied slot\n";
   }
   }while(board[i]!=' '||(i<0||i>8));
   board[i]=player;
}
void compturn(char board[],char computer){
   srand(time(0));
   int slot;
   do{
      slot=rand()%9;
   }while(board[slot]!=' ');
   board[slot]=computer;
}
int win(char board[],int gameover,char player){
   if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=' '){
      if(player==board[0]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=' '){
      if(player==board[3]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=' '){
      if(player==board[6]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=' '){
      if(player==board[0]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=' '){
      if(player==board[1]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=' '){
      if(player==board[2]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=' '){
      if(player==board[2]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=' '){
      if(player==board[0]){
      playspace(board);
      cout<<"You Win!\n";
      }
      else{
      playspace(board);
         cout<<"You lose!\n";
      }
      return 1;
   }
   else if((board[0]!=' '&&board[1]!=' ')&&(board[2]!=' '&&board[3]!=' ')&&(board[4]!=' '&&board[5]!=' ')&&(board[6]!=' '&&board[7]!=' ')&&(board[8]!=' ')){
      playspace(board);
      cout<<"The game is a draw\n";
      return 1;
   }
   else {
      return 0;
   }
}