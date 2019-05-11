#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
using namespace std;
int igualar_longitud(string &num1, string &num2){
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
 if(rpta.size()==1){
    respuesta += to_string(rpta[0]);
    return respuesta;
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
string grade_school_multiplication(string num1,string num2){
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
string fibonnaci_iterative(string n){
  if(n.size()==1){
    if(stoi(n)<=1){
        return "1";
    }
  }
  string f_a="0";
  string f_b="1";
  string fibonnaci_value="0";
  string temp="2";
  while(true){
    if(temp==n){
        break;
    }
    fibonnaci_value=suma(f_a,f_b);
    f_a=f_b;
    f_b=fibonnaci_value;
    temp=suma(temp,"1");
  }
  return fibonnaci_value;
}

string fibonnaci_recursive(string n){
  if(n.size()==1){
    if(stoi(n)==1 | stoi(n)==0){

        return n;
    }
  }
    return suma(fibonnaci_recursive(resta(n,"1")),fibonnaci_recursive(resta(n,"2")));
}

string factorial_iterative(string n){
  if(n.size()==1){
    if(stoi(n)<=1){
        return "1";
    }
  }
  string factorial_value="1";
  string temp="2";
  while(true){
    factorial_value= grade_school_multiplication(factorial_value,temp);
    if(temp==n){
        break;
    }
    temp=suma(temp,"1");
  }
  return factorial_value;
}

string factorial_recursive(string n){
  if(n.size()==1){
    if(stoi(n)<=1){
        return "1";
    }
  }
  return grade_school_multiplication(factorial_recursive(resta(n,"1")),n);
}

int main(){
  auto start = chrono::steady_clock::now();
  cout << fibonnaci_iterative("1000") << endl;
  auto end = chrono::steady_clock::now();
  cout << "Fibonnaci Iterative time: " << chrono::duration <double, milli> (end - start).count() << " ms" << endl;
  /////////////////////////////////////////////////////////////////////////////
  start = chrono::steady_clock::now();
  cout << fibonnaci_recursive("1000") << endl;
  end = chrono::steady_clock::now();
  cout << "Fibonnaci recursive time: " <<chrono::duration <double, milli> (end - start).count() << " ms" << endl;
  /////////////////////////////////////////////////////////////////////////////
  start = chrono::steady_clock::now();
  cout << factorial_iterative("1000") << endl;
  end = chrono::steady_clock::now();
  cout << "Factorial Iterative: " << chrono::duration <double, milli> (end - start).count() << " ms" << endl;
  /////////////////////////////////////////////////////////////////////////////
  start = chrono::steady_clock::now();
  cout << factorial_recursive("1000") << endl;
  end = chrono::steady_clock::now();
  cout << "Factorial Recursive: " << chrono::duration <double, milli> (end - start).count() << " ms" << endl;
}
