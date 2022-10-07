#include<iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;

const int TURNS=5;
char WORD[6];
bool OVER=0;

int main(){

cout<<"Wordle"<<endl;
int n;
//Randomise the word from the list
srand(time(0));
n=(rand())%20;

string word;
ifstream read("words.txt");
int len;
for(int i=0; i<20; i++){
    //Get the word from the list
    getline(read,word);
    len=word.length();
    if(i==n){
        break;
    }
}

cout<<"If u want to know the rules- Press 1"<<endl<<"To start the game- Press 0"<<endl;
    int a;
    cin>>a;
    if(a==1){
        cout<<"Instructions"<<endl<<"Your challenge is to guess a 3/4/5/6-letter word, whose length will be specified in 5 attempts. Each time you guess,"
        "you're told which of your chosen letters are in the target word, and whether they are in the right place. And that's it."<<endl<<
        "0- This letter is not in the word"<<endl<<
        "1- This letter is in the word but in the wrong spot"<<endl<<
        "2- This letter is in the word AND in the right spot"<<endl<<
        "The game will now start"<<endl
        ;
    }
    if(a==0){cout<<"The game will now start"<<endl;}

cout<<"The length of the word is ";
cout<<len<<endl;

strcpy(WORD,word.c_str());

//The array showing the result of the turn
int arr[len];
//The array to store the word input in every turn
int inp_word[len];

for(int t=1; t<=6; t++){
    int counter=0;
    for(int i=0; i<len; i++){
        char ch;
        cin>>ch;
        inp_word[i]=ch;
         //lowercase the word
        if(ch<=90 && ch>=65){
            ch+=32;
        }
        arr[i]=0;
    }

    for(int i=0; i<len; i++){
        if(WORD[i]==inp_word[i]){
            arr[i]=2;
        }
        else{
            for(int j=0; j<len; j++){
                if(WORD[i]==inp_word[j]){
                    arr[j]=1;
                    break;
                }
            }
        }
    }

    for(int i=0; i<len; i++){
        cout<<arr[i];
        if(arr[i]==2){
            counter++;
        }
    }
    if(counter==len){
        OVER=1;
        cout<<endl<<"YOU WIN";
        break;
    }

}

if(OVER==0){
    cout<<endl<<"You Lose";
}

cout<<"Do you wish to know the word?"<<endl<<"Press 1 if yes and Press 0 if no"<<endl;
cin >>int b;
if(b==1){
    cout<<word;
}
else if(b--0){
    cout<<"Thankyou";
}

}
