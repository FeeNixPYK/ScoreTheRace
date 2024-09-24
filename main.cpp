#include <iostream>
#include <string>
using namespace std;

int main() {
string input;
int team;
int firstteam;
bool C[26] = {false};
int runners[26] ={0};
double positionSum[26]={0};
double score;
char winteam;

Ask:
cout << "Enter a string of UPPER CASE characters: ";
cin >> input;
if (input == "done" || input == "DONE") goto done;

//Resetting after gotos because I dunno chat GPT said I should :(
team = 0;
firstteam =0;
score = 1000;

//check how many teams and how many runners in each team.
for (int i =0; i<input.size();i++){
    int index = input[i] -'A';
    C[index]=true;
    runners[index]++;
    positionSum[index] += (i+1);
}
//count the teams
for (bool i:C){
    if(i) team++;
}
//check for fairness by comparing teams
for(int i=0; i<26; i++){
    if (runners[i]!=0){
        if (firstteam==0){
            firstteam=runners[i];
        }else if(runners[i]!=firstteam){
            cout << "The teams do not have fair number of runners!!" << endl;
            goto Ask;
        }
    }
}

// count which team has how many runners
cout << "There are " << team << " teams" << endl;

for (int i=0; i<26; i++) {
    if (runners[i] != 0) {
        cout << "There are " << runners[i] << " runners on " <<  (char)(i + 'A') << " team and their score is "
        << positionSum[i]/runners[i]<< endl;
        if (positionSum[i]/runners[i]<score){
            score = positionSum[i]/runners[i];
            winteam = (char)(i+'A');
        }
    }
}

cout << "The winning team is " << winteam << " with a score of " << score << endl;
goto Ask;
done : return 0;
}
