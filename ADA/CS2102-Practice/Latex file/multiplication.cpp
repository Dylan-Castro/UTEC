#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int igualar_longitud(string &num1, string &num2)
{
    int lenght_1 = num1.size();
    int lenght_2 = num2.size();
    if (lenght_1 < lenght_2)
    {
        for (int i = 0 ; i < lenght_2 - lenght_1 ; i++){
            num1 = '0' + num1;
        }
        return lenght_2;
    }
    else if (lenght_1 > lenght_2)
    {
        for (int i = 0 ; i < lenght_1 - lenght_2 ; i++){
            num2 = '0' + num2;
        }
    }
    return lenght_1;
}

string resta(string num1, string num2){
  int lenght=igualar_longitud(num1,num2);
  vector<int> rpta(lenght,0);
  string respuesta = "";
  int acarreo = 0;
  int res = 0;
  for (int i = 0; i < lenght; i++) {
    if((num1[lenght-1-i] - '0'-acarreo)<(num2[lenght-1-i] - '0')){
      res= 10 + (num1[lenght-1-i] - '0') - (num2[lenght-1-i] - '0') - acarreo;
      acarreo=1;
      rpta[i]=res;
    }
    else{
      res= (num1[lenght-1-i] - '0')-(num2[lenght-1-i] - '0')-acarreo;
      acarreo=0;
      rpta[i]=res;
    }
  }

  for (int i = rpta.size() - 1; i >= 0; i--) {
    if(rpta[rpta.size() - 1] == 0){
      rpta[rpta.size() - 1]='-';
      continue;
    }
      respuesta += to_string(rpta[i]);
  }
  return respuesta;
}


string suma(string num1, string num2){
  if(num1.size()<=8 && num2.size()<=8){
     return to_string(stoi(num1)+stoi(num2));
  }
  int lenght=igualar_longitud(num1,num2);
  vector<int> rpta(lenght+1,0);
  string respuesta = "";
  int acarreo = 0;
  for (int i = 0; i < lenght; i++) {
    int sum= (num1[num1.size()-1-i] - '0')+(num2[num2.size()-1-i] - '0')+rpta[i+1]+acarreo;
    acarreo=sum/10;
    rpta[i]=sum%10;
    if (acarreo > 0){
        rpta[i+1] += acarreo;
    }
  }

  for (int i = rpta.size() - 1; i >= 0; i--) {
    if(rpta[rpta.size() - 1] == 0){
      rpta[rpta.size() - 1]='-';
      continue;
    }
      respuesta += to_string(rpta[i]);
  }
  return respuesta;
}

string karatsuba(string num1,string num2){
    int n = igualar_longitud(num1, num2);
    int fh = n/2;
    int sh = (n-fh);
    if(num1.size()<=8 && num2.size()<=8){
     return to_string(stoi(num1)*stoi(num2));
    }
    string left_1=num1.substr(0,fh);
    string left_2=num2.substr(0,fh);
    string right_1=num1.substr(fh,sh);
    string right_2=num2.substr(fh,sh);
    string s2=karatsuba(left_1,left_2);
    string s0=karatsuba(right_1,right_2);
    string s1= karatsuba(suma(left_1,right_1),suma(left_2,right_2));
    s1= resta(s1,s2);
    s1= resta(s1,s0);
    string rpta= suma(suma(s2+string(ceil(num2.size()/2)*2,'0'),s1+string(ceil(num2.size()/2),'0')),s0);
    return rpta;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
string grade_school_multiplication(string num1,string num2)
{
    vector<int> rpta(num1.size() + num2.size(), 0);
    int indicen1 = 0;
    int indicen2 = 0;
    string respuesta = "";
    for (int i=num1.size()-1; i>=0; i--)
    {
        int acarreo = 0;
        indicen2 = 0;
        for (int j=num2.size()-1; j>=0; j--)
        {
            int sum = (num1[i] - '0')*(num2[j] - '0') + rpta[indicen1 + indicen2] + acarreo;
            acarreo = sum/10;
            rpta[indicen1 + indicen2] = sum % 10;
            indicen2++;
        }
        if (acarreo > 0){
            rpta[indicen1 + indicen2] += acarreo;
        }
        indicen1++;
    }

    for (int i = rpta.size() - 1; i >= 0; i--) {
        if(rpta[rpta.size() - 1] == 0){
      rpta[rpta.size() - 1]='-';
      continue;
    }
        respuesta += to_string(rpta[i]);
    }
    return respuesta;
}

int main(){
  string num1="2718281828459045235360287471352662497757247093699959574966967627";
  string num2="3141592653589793238462643383279502884197169399375105820974944592";
  cout << karatsuba(num1,num2) << endl;
  cout << grade_school_multiplication(num1,num2) << endl;
  //cout << resta("100000","50000");
  //cout << string(5,'0');
  //cout << sizeof(long long int);
}
