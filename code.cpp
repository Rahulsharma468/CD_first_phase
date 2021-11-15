#include<bits/stdc++.h>
#include <regex>
using namespace std;

vector<string> keywords = {"for","while","do","int","float","double","long","void","main","begin","end","End"};

vector<string> paranthesis = {"{","}","(",")","[","]"};

vector<string> operators = {"+","-","*","/",">","<","=","|","&","++","--",":=",",","&&",
                            "||","!",">>","<<",">=","<=","==","+=","-=","*=","/=","%=","^",
                            "~","sizeof","?:"};

vector<string> special_symbols = {"#",";"};

bool handleNumbers(std::string const& input) {
    static const std::regex doubleRegex{ R"([+\-]?(?:0|[1-9]\d*)(?:\.\d*)?(?:[eE][+\-]?\d+)?)" };
    static const std::regex intRegex{ R"(\d+)"};

    if (std::regex_match(input, intRegex)){
        istringstream inputStream(input);
        int i;
        inputStream >> i;
        cout << input << " is a INTEGER\n";
        return true;
    } else if (std::regex_match(input, doubleRegex)) {
        istringstream inputStream(input);
        double d;
        inputStream >> d;
        cout << input << " is a FLOATING POINT\n";
        return true;
    }
    return false;
}   


void handleInput(string s){
    if(find(operators.begin(), operators.end(), s) != operators.end()){
        cout << s << " is an Operator\n";
    }
    else if(find(paranthesis.begin(), paranthesis.end(), s) != paranthesis.end()){
        cout << s << " is a Paranthesis\n";
    }
    else if(find(keywords.begin(), keywords.end(), s) != keywords.end()){
        cout << s << " is a Keyword\n";
    } else if(find(special_symbols.begin(), special_symbols.end(), s) != special_symbols.end()){
        cout << s << " is a special symbol\n";
    } else {
        if(handleNumbers(s)==false){
            cout<<s<<" is an Identifier\n";
        }
    }
}


int main(){
    string s;
    string str_occ = "";
    bool flag = false;
    freopen("input.txt", "r", stdin);

    while(cin >> s){
        if(s[0]=='"' || flag){
            str_occ=str_occ+" "+s+" ";
            flag = true; 
            if(s.back()=='"') {
                cout<<str_occ<<" is a String\n";
                str_occ = " ";
                flag = false;
            }
        } else handleInput(s);
    }

    return 0;
}