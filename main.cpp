#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>

using namespace std;

char encrypt(char letter, int k){
    char encChar;
    
    if(isalpha(letter)){
        if(letter >= 'A' && letter <= 'Z'){
            encChar = (char)((((letter + k) - 65) % 26) + 65);
        }
        else{
            encChar = (char)((((letter + k) - 97) % 26) + 97);
        }
        
    }
    
    return encChar;
}

char decrypt(char letter, int k){
    char decChar;
    int decInt = 0;
    int hold = 0;
    decInt = int(letter);

    if(letter >= 'A' && letter <= 'Z'){
        if(((decInt - 65) - k) >= 0){
            decChar = (char)((((letter - k) - 65) % 26) + 65);
        }
        else{
            int hold = -1 * ((decInt - 65) - k);
            decChar = (char)((26 - hold) + 65);
        }
    }
    
    else{
        if(((decInt - 97) - k) >= 0){
            decChar = (char)((((letter - k) - 97) % 26) + 97);
        }
        else{
            int hold = -1 * ((decInt - 97) - k);
            decChar = (char)((26 - hold) + 97);
        }
    }
    
    return decChar;
}

int main(int argc, char* argv[]){
    
    int key = 0;
    
    string inFileName;
    string outFileName;
    string content;
    string temp;
    ifstream fin;
    ofstream fout;
    int N = 0;
    bool fileNotOpen = false;
    bool encDec = false;
    
    for(int i = 0; i < argc; i++){
        
        if(strcmp((argv[i]), "-k") == 0){
            key = stoi(argv[i+1]);
            i = i + 1;
        }
        else if(strcmp((argv[i]), "-i") == 0){
            inFileName = argv[i+1];
            i = i + 1;
        }
        else if(strcmp((argv[i]), "-o") == 0){
            outFileName = argv[i+1];
            i = i + 1;
        }
        else if(strcmp((argv[i]), "-e") == 0){
            fin.open(inFileName);
            
            if(encDec == true){
                cout << "Cannot encrypt AND decrypt." << endl;
                return 0;
            }
            
            if(!fin.is_open()){
                fileNotOpen = true;
                cout << "File is not open." << endl;
                return 0;
            }
            
            while(!fin.eof()){
                getline(fin,temp);
                content += temp;
                content += "\n";
            }
            N = content.length();
            
            for(int j = 0; j < N; j++){
                char character = content[j];
                
                if(isalpha(character)){
                    char temporaryChar = encrypt(character,key);
                    content[j] = temporaryChar;
                }
                else{
                    content[j] = character;
                }
            }
            
            fin.close();
            
            fout.open(outFileName);
            fout << content;
            fout.close();
            
            encDec = true;
        }
        else if(strcmp((argv[i]), "-d") == 0){
            fin.open(inFileName);
            
            if(encDec == true){
                cout << "Cannot encrypt AND decrypt." << endl;
                return 0;
            }
            
            if(!fin.is_open()){
                fileNotOpen = true;
                cout << "File is not open." << endl;
                return 0;
            }
            
            while(!fin.eof()){
                getline(fin,temp);
                content += temp;
                content += "\n";
            }
            N = content.length();
            
            for(int j = 0; j < N; j++){
                char character = content[j];
                
                if(isalpha(character)){
                    char temporaryChar = decrypt(character,key);
                    content[j] = temporaryChar;
                }
                else{
                    content[j] = character;
                }
            }
            
            fin.close();
            
            fout.open(outFileName);
            fout << content;
            fout.close();
            
            encDec = true;
        }
        else{
            if(strcmp(argv[i], "./test") != 0){
                cout << "Invalid entry: "  << argv[i] << endl;
            }
        }
    }
    
    
    return 0;
}