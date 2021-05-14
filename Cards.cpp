#include <iostream>
#include <cstdlib>
using namespace std;
class Cards
{
	
};

int main()
{
	//1.we havecreate the deck of cards
	
	// 2.We need to populate our deck with cards
    // Now we will create and populate the deck of cards using an array of strings
	const char *deck_card[52]={"Ac","Ad","Ah","As","2c","2d","2h","2s","3c","3d","3h","3s","4c","4d","4h","4s",
	"5c","5d","5h","5s","6c","6d","6h","6s","7c","7d","7h","7s","8c","8d","8h","8s","9c","9d","9h","9s","10c","10d","10h","10s",
	"Jc","Jd","Jh","Js","Kc","Kd","Kh","Ks","Qc","Qd","Qh","Qs"};
	//I will create another array here and copy all the values of the deck_card array as they are in order to use it access the indexes of each element
	const char *deck_card_copy[52];
	for (int i =0;i<52;i++)
	{
		deck_card_copy[i]=deck_card[i];
	}
	
	//3.we need to shuffle our original deck  of cards
	//The folowing for loop generates two random numbers 52 times to exchange cards, i.e to shuffle
	for (int i =0;i<52;i++)
	{
			int randnum1 = rand() % (0-51);
			int randnum2 = rand() % (0-51);
			const char *temp[1] = {deck_card[randnum2]};
			deck_card[randnum1]=deck_card[randnum2];
			deck_card[randnum2]=temp[0];
			
	}
	
	//const char *deck_card_two[52]= deck_card;
	//We asign cards to each player three cards each from index 51 to index 53
	const char *player_one[3]={deck_card[51],deck_card[49],deck_card[47]};
	const char *player_two[3]={deck_card[50],deck_card[48],deck_card[46]};
	//Now we start to play as from index 45:
	int condition = 45;
	while (condition>=0)
	{
			cout<<"\tPLAYER ONE";
	         cout<<"\t\t\tPLAYER TWO"<<endl;
	         cout<<"\t 1."<<player_one[0];
	         cout<<"\t\t\t 1."<<player_two[0]<<endl;
	         cout<<"\t 2."<<player_one[1];
	         cout<<"\t\t\t 2."<<player_two[1]<<endl;
	         cout<<"\t 3."<<player_one[2];
	         cout<<"\t\t\t 3."<<player_two[2]<<endl;
	         
	         //DEALING WITH PLAYER ONE NOW
	         cout<<endl;
	         cout<<"TURN FOR PLAYER ONE TO PLAY"<<endl;
	             if(player_one[0]==player_one[1] && player_one[0]==player_one[2])
	         {  //RULE NUMBER 1: if all the three cards are equal
	         	cout<<"GAME OVER!! PLAYER ONE WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			 //If the game is not over player one picks a card
	         const char *player_one_picks_card[1] = {deck_card[condition]};
	         // RULE NUMBER 2: To check if the card picked resembles any two cards the player has in his deck
	         if(player_one_picks_card[0]==player_one[0] &&player_one_picks_card[0]==player_one[1])
	         {
	         	cout<<"GAME OVER!! PLAYER ONE WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_one_picks_card[0]==player_one[0] &&player_one_picks_card[0]==player_one[2])
	         {
	         	cout<<"GAME OVER!! PLAYER ONE WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_one_picks_card[0]==player_one[1] &&player_one_picks_card[0]==player_one[2])
	         {
	         	cout<<"GAME OVER!! PLAYER ONE WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
	         
	       	// RULE NUMBER 3: To check if the four cards of a player are consecutive
	       	//index of first card
	       	int index_of_card1=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_one[0]==deck_card_copy[i])
	         	{
	         		index_of_card1=i+1;
				 }
			 }
			 //index of second card
			int index_of_card2=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_one[1]==deck_card_copy[i])
	         	{
	         		index_of_card2=i+1;
				 }
			 }
			 //index of third card
			int index_of_card3=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_one[2]==deck_card_copy[i])
	         	{
	         		index_of_card3=i+1;
				 }
			 }
			 // index of the the card picked
		   	int index_of_card4=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_one_picks_card[0]==deck_card_copy[i])
	         	{
	         		index_of_card4=i+1;
				}
			 }
			 //now we now form an array of four inegers using the above indexes to determine max and min value to know if the numbers are consecutive
			 int check_consecutive_arr[4]={index_of_card1,index_of_card2,index_of_card3,index_of_card4};
			 //Determine the maximum number in the array
			 int max = check_consecutive_arr[0];
			 for( int j =1;j<4;j++)
			 {
			 	if(check_consecutive_arr[j]>max)
			 	{
			 		max=check_consecutive_arr[j];
				 }
			 }
			 
	         //Determine the minimum number in the array
			 int min = check_consecutive_arr[0];
			 for( int j =1;j<4;j++)
			 {
			 	if(check_consecutive_arr[j]<min)
			 	{
			 		min=check_consecutive_arr[j];
				 }
			 }
			 if(max-min==3)
			 {
			 	cout<<"GAME OVER!! PLAYER ONE WINS BY CONSECUTIVENESS OF THE FOUR CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
		    //RULE NUMBER 4:Check weather the there are to pairs which are equal, i.e two cards are the same and the other two cards are the same
		     if(player_one[0]==player_one[1] && player_one[2]==player_one_picks_card[0])
	         {
	         	cout<<"GAME OVER!!! PLAYER ONE WINS BY EQUALITY OF TWO PAIRS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_one[0]==player_one[2] && player_one[1]==player_one_picks_card[0])
	         {
	         	cout<<"GAME OVER!!! PLAYER ONE WINS BY EQUALITY OF TWO PAIRS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_one[0]==player_one_picks_card[0] && player_one[1]==player_one[2])
	         {
	         	cout<<"GAME OVER!!! PLAYER ONE WINS BY EQUALITY OF TWO PAIRS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			 //Now if player one haven't won, he/ she has to drop one card, and he or she should choose which ca to drop
			 cout<<"Choose a card to drop, 1, 2, or 3 or any other integer to drop the picked card"<<endl;
			 cout<<"The card you picked is "<<player_one_picks_card[0]<<endl;
			 cout<<"Enter your option"<<endl;
			 int option;
			 cin>>option;
			 if (option==1)
			 {
			 	player_one[0]=player_one_picks_card[0];		
			 }
			 if(option==2)
			 {
			 	player_one[1]=player_one_picks_card[0];
			 }
			 
			 if(option==3)
			 {
			 	player_one[2]=player_one_picks_card[0];
			 	
			 }
             //Now we are done with dealing with player 1 now we decrement the value of our condition so that we can't pick the same card twice
             condition = condition -1;
             //Now WE DEAL WITH PLAYER TWO 
                cout<<endl;
                cout<<" TURN FOR PLAYER TWO TO PLAY"<<endl;
	             if(player_two[0]==player_two[1] && player_two[0]==player_two[2])
	         {  //RULE NUMBER 1: if all the three cards are equal
	         	cout<<"GAME OVER!! PLAYER TWO WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			 //If the game is not over player one picks a card
	         const char *player_two_picks_card[1] = {deck_card[condition]};
	         // RULE NUMBER 2: To check if the card picked resembles any two cards the player has in his deck
	         if(player_two_picks_card[0]==player_two[0] &&player_two_picks_card[0]==player_two[1])
	         {
	         	cout<<"GAME OVER!! PLAYER TWO WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_two_picks_card[0]==player_two[0] &&player_two_picks_card[0]==player_two[2])
	         {
	         	cout<<"GAME OVER!! PLAYER TWO WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_two_picks_card[0]==player_two[1] &&player_two_picks_card[0]==player_two[2])
	         {
	         	cout<<"GAME OVER!! PLAYER TWO WINS BY EQUALITY OF ALL THREE CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
	         
	       	// RULE NUMBER 3: To check if the four cards of a player are consecutive
	       	//index of first card
	       	int index_card1=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_two[0]==deck_card_copy[i])
	         	{
	         		index_card1=i+1;
				 }
			 }
			 //index of second card
			int index_card2=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_two[1]==deck_card_copy[i])
	         	{
	         		index_card2=i+1;
				 }
			 }
			 //index of third card
			int index_card3=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_two[2]==deck_card_copy[i])
	         	{
	         		index_card3=i+1;
				 }
			 }
			 // index of the the card picked
		   	int index_card4=0;
	         for(int i =0;i<52;i++)
	         {
	         	if(player_two_picks_card[0]==deck_card_copy[i])
	         	{
	         		index_card4=i+1;
				}
			 }
			 //now we now form an array of four inegers using the above indexes to determine max and min value to know if the numbers are consecutive
			 int check_consecutive_array[4]={index_card1,index_card2,index_card3,index_card4};
			 //Determine the maximum number in the array
			 int maximum = check_consecutive_arr[0];
			 for( int j =1;j<4;j++)
			 {
			 	if(check_consecutive_array[j]>maximum)
			 	{
			 		maximum=check_consecutive_array[j];
				 }
			 }
			 
	         //Determine the minimum number in the array
			 int minimum = check_consecutive_array[0];
			 for( int j =1;j<4;j++)
			 {
			 	if(check_consecutive_array[j]<minimum)
			 	{
			 		minimum=check_consecutive_array[j];
				 }
			 }
			 if(maximum-minimum==3)
			 {
			 	cout<<"GAME OVER!! PLAYER TWO WINS BY CONSECUTIVENESS OF THE FOUR CARDS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
		    //RULE NUMBER 4:Check weather the there are to pairs which are equal, i.e two cards are the same and the other two cards are the same
		     if(player_two[0]==player_two[1] && player_two[2]==player_two_picks_card[0])
	         {
	         	cout<<"GAME OVER!!! PLAYER TWO WINS BY EQUALITY OF TWO PAIRS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_two[0]==player_two[2] && player_two[1]==player_two_picks_card[0])
	         {
	         	cout<<"GAME OVER!!! PLAYER TWO WINS BY EQUALITY OF TWO PAIRS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			  if(player_two[0]==player_two_picks_card[0] && player_two[1]==player_two[2])
	         {
	         	cout<<"GAME OVER!!! PLAYER TWO WINS BY EQUALITY OF TWO PAIRS"<<endl;
	         	exit(0);//This lines terminates the program
			 }
			 //Now if player two haven't won, he/ she has to drop one card, and he or she should choose which ca to drop
			 cout<<"Choose a card to drop, 1, 2, or 3 or any other integer to drop the picked card"<<endl;
			 cout<<"The card you picked is "<<player_two_picks_card[0]<<endl;
			 cout<<"Enter your option"<<endl;
			 int myoption;
			 cin>>myoption;
			 if (myoption==1)
			 {
			 	player_two[0]=player_two_picks_card[0];		
			 }
			 if(myoption==2)
			 {
			 	player_two[1]=player_two_picks_card[0];
			 }
			 
			 if(myoption==3)
			 {
			 	player_two[2]=player_two_picks_card[0];
			 	
			 }
             //Now we are done with dealing with player 2 now we decrement the value of our condition so that we can't pick the same card twice
             condition = condition -1;
             //Now lets ask the players whether they are willing to clear the screen
             cout<<endl;
             cout<<"Players, would you like to clear the screen?"<<endl;
             cout<<"1. Press 1 for YES"<<endl;
             cout<<"2. Press any other integer for NO"<<endl;
	         int clear_option;
	         cout<<"Enter your option"<<endl;
	         cin>> clear_option;
	         if (clear_option==1)
	         {
	             system("CLS");	//This statement clears the screen
	         }
	         
	         
	}
	
	
  return 0;
	  
}
