#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

using namespace std;


int num(){
    int x;
    cout << "1 to run the program 2 to quit" << endl;
    cin >> x; 
    return x;  
}

int num_str(string str){
    int x;
    cout << str << endl;
    cin >> x; 
    return x;  
}

int main(){
    while(true){
        int input = num();
        if(input == 1){
            
            float fga = num_str("Enter field goal attempts");
            float fgm = num_str("Enter field goals made");
            float tpa = num_str("Enter three point attempts");
            float tpm = num_str("Enter three point made");
            
            ofstream MyWriteFile("Calculator.txt");

            MyWriteFile << "run \n";
            MyWriteFile << fga << "," << fgm << "," << tpa << "," << tpm;
            MyWriteFile.close();
            sleep(10);

            ifstream MyReadFile("Calculator.txt");
            string myText;
            getline (MyReadFile, myText);
            printf("%s\n", myText.c_str());
            MyReadFile.close();

            float num = stof(myText);

            printf("Effective Field Goal Percentage %.2f\n", num);
            
        }
        else if(input == 2){
            ofstream MyWriteFile("Calculator.txt");
            MyWriteFile << "quit";
            MyWriteFile.close();
            return 1;
        }
        else{
            printf("Plese pick 1 or 2");
        }
    }
}