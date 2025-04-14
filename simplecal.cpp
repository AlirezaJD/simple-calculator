#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class MATHClass{

    vector<float> extractIntegers(string str){
        vector<float> floats;
        string temp = "";

        for(int i=0;i<str.length();i++){
            if(str.at(i)=='-' || isdigit(str.at(i)) ||str.at(i)=='.' ){
                for(int j=i;j<str.length();j++){
                    if(str.at(j)=='-' || isdigit(str.at(j)) || str.at(j)=='.' ){
                        temp+=str.at(j);
                        i=j;
                    }
                    else{
                        i=j;
                        floats.push_back(stof(temp));
                        temp="";
                        break;
                    }
                }
            }
        }
        if(temp.size()!=0){
            floats.push_back(stof(temp));
        }
        return floats;
    }

public:
    void sum(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = numbers.at(0) + numbers.at(1);
        printf("%.4f", temp);
        cout<<"\n";
    }
    void sub(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = numbers.at(0) - numbers.at(1);
        printf("%.4f", temp);
        cout<<"\n";
    }

    void pow(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = std::pow(numbers.at(0), numbers.at(1));
        printf("%.4f", temp);
        cout<<"\n";
    }

    void remainder(string str){ //%
        vector<float> numbers = extractIntegers(str);
        float temp = std:: fmod( numbers.at(0),numbers.at(1));
        printf("%.4f", temp);
        cout<<"\n";
    }

    void multiply(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = numbers.at(0) * numbers.at(1);
        printf("%.4f", temp);
        cout<<"\n";
    }

    void divide(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = numbers.at(0) / numbers.at(1);
        printf("%.4f", temp);
        cout<<"\n";
    }

    void log(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = std::log( numbers.at(0) ) / std::log( numbers.at(1) ); // log x / log base
        printf("%.4f", temp);
        cout<<"\n";
    }

    void radical(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = std::sqrt(numbers.at(0));
        printf("%.4f", temp);
        cout<<"\n";
    }


    void sin(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = std::sin(numbers.at(0)*M_PI/180);
        printf("%.4f", temp);
        cout<<"\n";
    }

    void cos(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = std::cos(numbers.at(0)*M_PI/180);
        printf("%.4f", temp);
        cout<<"\n";
    }

    void tan(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = std::tan(numbers.at(0)*M_PI/180);
        printf("%.4f", temp);
        cout<<"\n";
    }

    void arcSin(string str){
        vector<float> numbers = extractIntegers(str);
        float temp = std::asin(numbers.at(0));
        temp = (temp * 180) / M_PI;
        printf("%.4f", temp);
        cout<<"\n";
    }

};

int main(){

    MATHClass mathClass;
    string str, strTemp;

    cout<<"input string without space:('End' to exit)\n";
    cout<<"you can use one of these in each line:\n"
          "sin, cos, tan, arcsin, ^, %(remainder), *, /, +, _(use underLine for sub), log, radical\n";

    while (true){

        cin>>str;
        strTemp = str;

        if(str == "End")
            break;

        if(str.find("arcsin") != string::npos) {
            mathClass.arcSin(strTemp);
        }
        else if(str.find("cos") != string::npos){
            mathClass.cos(strTemp);
        }
        else if(str.find("tan") != string::npos){
            mathClass.tan(strTemp);
        }
        else if(str.find("sin") != string::npos){
                mathClass.sin(strTemp);
        }
        else if(str.find("^") != string::npos){
            mathClass.pow(strTemp);
        }
        else if(str.find("%") != string::npos){ // for remainder
            mathClass.remainder(strTemp);
        }
        else if(str.find("*") != string::npos){
            mathClass.multiply(strTemp);
        }
        else if(str.find("/") != string::npos){
            mathClass.divide(strTemp);
        }
        else if(str.find("+") != string::npos){
            mathClass.sum(strTemp);
        }
        else if(str.find("_") != string::npos){
            mathClass.sub(strTemp);
        }
        else if(str.find("log") != string::npos){
            mathClass.log(strTemp);
        }
        else if(str.find("radical") != string::npos){
            mathClass.radical(strTemp);
        }
        else
            cout<<"\nplease input correctly...\n";
    }
}