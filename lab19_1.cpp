#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream paper;
    paper.open(filename);
    string v;
    char n[50];
    int a, b, c, cal;
    while(getline(paper, v)){
        sscanf(v.c_str(), "%[^:]: %d %d %d", n, &a, &b, &c);
        names.push_back(n);
        cal = a+b+c;
        scores.push_back(cal);
        grades.push_back(score2grade(cal));
        
    }
}

void getCommand(string &command, string &key){
    string text;
    char c[20];
    char k[20];
    cout << "Please input your command: ";
    getline(cin, text);
    sscanf(text.c_str(), "%s %[^:]", c, k);
    command = c;
    key = k;
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades, string key){
    string n;
    bool f = false;
    cout << "---------------------------------\n";
    for(unsigned int i=0; i<names.size(); i++){
        n = names[i];
        if(toUpperStr(n)==key){
            cout << names[i] << "'s score = " << scores[i] << endl;
            cout << names[i] << "'s grade = " << grades[i]<< endl;
            f = true;
        }
    }
    if(f == false) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
    
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades, string key){
    string n;
    cout << "---------------------------------\n";
    for(unsigned int i=0; i<names.size(); i++){
        n = grades[i];
        if(toUpperStr(n)==key){
            cout << names[i] << " (" << scores[i] << ")\n";
        }
    }
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
