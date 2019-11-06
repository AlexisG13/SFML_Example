#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
using namespace std; 

void addPlayer(){
    ofstream myFile;
    myFile.open("scores.txt",ios_base::app);
    cout << "Ingrese el jugador y luego su score"<<endl;
    string player;
    int score;
    cin >> player >> score;
    myFile << endl << player << " " << score;
    myFile.close();
}

void ordenarPlayers(string players[],int scores[],int n){
    for (int i = 0; i < n; i++)                     
	{
		for (int j = 0; j < n; j++)             
		{
			if (scores[j] < scores[i])                
			{
				int tmp = scores[i]; 
                string tmps = players[i];        
				scores[i] = scores[j];   
                players[i] = players[j];         
				scores[j] = tmp;
                players[j] = tmps;             
			}
		}
	}
}

int playerCount(){
    int cont = 0;
    ifstream myFile;
    myFile.open("scores.txt");
    while(!myFile.eof()){
        string player;
        int score; 
        myFile >> player >> score;
        cont++;
    }
    return cont;
}

void getPlayers(int n){
    string players[n];
    int scores[n];
    int cont = 0;
    ifstream myFile;
    myFile.open("scores.txt");
    while(!myFile.eof()){
        string player;
        int score; 
        myFile >> player >> score;
        players[cont] = player;
        scores[cont] = score;
        cont ++;
    }
    myFile.close();
    ordenarPlayers(players,scores,n);
    cout << left << setw(20) << "PLAYER " << "SCORE" << endl;
    for(int i =0;i<n;i++){
        cout << left << setw(20) <<players[i] << scores[i] << endl;
    }
}

int main(){
    int n = 0;
    int opt = 0;
    while(opt!=3){
        cout << "Elija una opcion"<< endl;
        cout << "1. Ingresar un nuevo jugador" << "\n" << "2. Ver todos los jugadores" << 
         " \n " << "3. Salir" << endl;
        cin >> opt;
        switch(opt){
            case 1:
                addPlayer();
                break;
            case 2:
                n = playerCount();
                getPlayers(n);
                break;
            default:
                break;    
        }
    }
    return 0;
}