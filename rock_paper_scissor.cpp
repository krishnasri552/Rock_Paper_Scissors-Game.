#include <bits/stdc++.h>
using namespace std;

void printFinalScore(int userscore, int computerscore){
    cout<<"\nFinal Score - Your Score is: "<<userscore<<" "<<" | "<<"Computer Score is: "<<computerscore<<endl;
}

void printWinner(int userscore, int computerscore){
    if(userscore > computerscore){
        cout<<"\nYou Won!!"<<endl;
    }else if(computerscore > userscore){
        cout<<"\nComputer Won!! Better Luck Next Time."<<endl;
    }else{
        cout<<"\nAhh, It's A Tie"<<endl;
    }
}

int main() {
  srand(time(nullptr));
  string options[] = {"rock", "paper", "scissors"};
  int numOptions = sizeof(options) / sizeof(options[0]);
  int userscore = 0, computerscore = 0;
  while(true){
    string userChoice;
    cout<<"Enter your choice (rock, paper, scissors): ";
    cin>>userChoice;
    for(char &c:userChoice){
        c=tolower(c);
    }
    bool validChoice = false;
    for(int i=0;i<numOptions;i++) {
      if(userChoice==options[i]) {
        validChoice=true;
        break;
      }
    }
    if(!validChoice){
      cout<<"Invalid choice, please try again."<<endl;
      continue;
    }
    int computerChoiceIndex=rand()%numOptions;
    string computerChoice=options[computerChoiceIndex];
    cout<<"You chose "<<userChoice<<"."<<endl;
    cout<<"The computer chose "<<computerChoice<<"."<<endl;
    if(userChoice==computerChoice){
      cout<<"It's a tie!"<<endl;
    }else if((userChoice=="rock" && computerChoice=="scissors")||
               (userChoice=="paper" && computerChoice=="rock") ||
               (userChoice=="scissors" && computerChoice=="paper")) {
      cout<<"You win!"<<endl;
      userscore++;
      cout<<"Your Score is: "<<userscore<<" "<<"Computer Score is: "<<computerscore<<endl;
    }else{
      cout<<"The computer wins!"<<endl;
      computerscore++;
      cout<<"Your Score is: "<<userscore<<" "<<"Computer Score is: "<<computerscore<<endl;
    }
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    playAgain = tolower(playAgain);
    if(playAgain!='y'){
      break;
    }
  }
  printFinalScore(userscore, computerscore);
  printWinner(userscore, computerscore);
  return 0;
}
