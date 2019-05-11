#ifndef STACK_H
#define LIST_H
#include <iostream>
#include <sstream>
#include <ctype.h>
#include "calc_stack.h"
#include "ope_stack.h"
#include "out_stack.h"
#include <math.h>
#include <map>
using namespace std;
template <typename T>
class Stack{
    private:
        Ope_stack<string>* ope_stack;
        Out_stack<string>* out_stack;
        Calc_stack<double>* calc_stack;
        map<char,string> var;
    public:
        Stack();
        void topostfix(string operation);
        void stack_to_output(bool bracket);
        string tostr(auto);
        double calculator();
        ~Stack();
};
template<class T> Stack<T>::Stack(){
    out_stack= new Out_stack<string>;
    ope_stack= new Ope_stack<string>;
}
template<class T> Stack<T>::~Stack(){
    delete calc_stack;
    delete out_stack;
    delete ope_stack;
}
template<class T> double Stack<T>::calculator(){
    calc_stack= new Calc_stack<double>;
    //Opera en notacion de postfix e imprime el resultado
    do{
        try
          {
            if(!isdigit(stoi(ope_stack->operator_stack.top()))){
                calc_stack->calc_rpn.push(stod(ope_stack->operator_stack.top()));
            }
            ope_stack->operator_stack.pop();
          }
          catch (...)
          {
            double alone_num=0,num2=0,num1=0;
            if(calc_stack->calc_rpn.size()==1){
                alone_num = calc_stack->calc_rpn.top();
                calc_stack->calc_rpn.pop();
            }
            else{
                num2= calc_stack->calc_rpn.top();
                calc_stack->calc_rpn.pop();
                num1= calc_stack->calc_rpn.top();
                calc_stack->calc_rpn.pop();
            }
            if(ope_stack->operator_stack.top()=="+"){
                if(alone_num!=0){
                    calc_stack->calc_rpn.push(alone_num);
                }else{
                calc_stack->calc_rpn.push(num1+num2);
                }
            }
            else if(ope_stack->operator_stack.top()=="-"){
                if(alone_num!=0){
                    calc_stack->calc_rpn.push(alone_num*-1);
                }else{
                calc_stack->calc_rpn.push(num1-num2);
                }
            }
            else if(ope_stack->operator_stack.top()=="*"){
                calc_stack->calc_rpn.push(num1*num2);
            }
            else if(ope_stack->operator_stack.top()=="/"){
                calc_stack->calc_rpn.push(num1/num2);
            }
            else if(ope_stack->operator_stack.top()=="^"){
                calc_stack->calc_rpn.push(pow(num1,num2));
            }
            ope_stack->operator_stack.pop();
          }
    }
    while(!ope_stack->operator_stack.empty());
    delete ope_stack;
    cout << "La respuesta es: " <<calc_stack->calc_rpn.top() << endl;
    delete calc_stack;
}
template<class T> string Stack<T>::tostr(auto data){
    //Convierte los datos a string
    stringstream ss;
    ss << data;
    string s = ss.str();
    return s;
}

template<class T> void Stack<T>::stack_to_output(bool bracket){
    //Envia todos los datos del stack_operator al stack_output
    do{
        if(ope_stack->operator_stack.top()=="("){
           if(bracket){
            ope_stack->operator_stack.pop();
           }
           break;
        }
        out_stack->output_queue.push(ope_stack->operator_stack.top());
        ope_stack->operator_stack.pop();
    }
    while(!ope_stack->operator_stack.empty());
}
template<class T> void Stack<T> ::topostfix(string operation){
   //Convierte de notacion infix a postfix
   bool next_num=false;
   for(int x=0;x<operation.length();x++){
        if(isdigit(operation[x])){
            if(next_num){
                out_stack->output_queue.top()=tostr(out_stack->output_queue.top())+tostr(operation[x]);
            }
            else{
                out_stack->output_queue.push(tostr(operation[x]));
            }
            if(isdigit(operation[x+1])){

                next_num=true;
            }
            else{
                next_num=false;
            }
        }
        else if(operation[x]=='.'){
            out_stack->output_queue.top()=tostr(out_stack->output_queue.top())+tostr(operation[x]);
            next_num=true;
        }
        else if((int(operation[x])>=97 && int(operation[x])<=122)){
            if(var.find(operation[x])->first==operation[x]){
                out_stack->output_queue.push(var.find(operation[x])->second);
            }
            else{
                string temp;
                cout << "Ingrese un valor para la variable "<< operation[x] << endl;
                getline (cin, temp);
                out_stack->output_queue.push(temp);
                var[operation[x]]= temp;
            }
        }
        else if(operation[x]=='('){
            ope_stack->operator_stack.push(tostr(operation[x]));
        }
        else if(operation[x]==')'){
            stack_to_output(true);
        }
        else{
            if(operation[x]=='*'){
                if(!ope_stack->operator_stack.empty()){
                if(ope_stack->operator_stack.top()=="/" || ope_stack->operator_stack.top()=="^"){
                    stack_to_output(false);
                }
                }
            }
            else if(operation[x]=='-'){
                if(!ope_stack->operator_stack.empty()){
                if(ope_stack->operator_stack.top()=="*" || ope_stack->operator_stack.top()=="^" || ope_stack->operator_stack.top()=="-" || ope_stack->operator_stack.top()=="/"){
                    stack_to_output(false);
                }}
                if(operation[x+1]=='-'){
                    operation[x]='|';
                    operation[x+1]='+';
                }
                else if(operation[x+1]=='+'){
                    operation[x]='|';
                    operation[x+1]='-';
                }
            }
            else if(operation[x]=='+'){
                if(!ope_stack->operator_stack.empty()){
                if(ope_stack->operator_stack.top()=="-" || ope_stack->operator_stack.top()=="^" || ope_stack->operator_stack.top()=="*" || ope_stack->operator_stack.top()=="/"){
                    stack_to_output(false);
                }}
                if(operation[x+1]=='-'){
                    operation[x]='|';
                    operation[x+1]=='-';
                }
                else if(operation[x+1]=='+'){
                    operation[x]='|';
                }
            }
            if(operation[x]!='|'){
                ope_stack->operator_stack.push(tostr(operation[x]));
            }
        }
        ////////////////////////
    }
    stack_to_output(false);
    do{
        ope_stack->operator_stack.push(out_stack->output_queue.top());
        out_stack->output_queue.pop();
    }
    while(!out_stack->output_queue.empty());
    delete out_stack;
    calculator();
}
#endif
