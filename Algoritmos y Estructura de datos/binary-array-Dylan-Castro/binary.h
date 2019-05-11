#ifndef BOOLEAN_H
#define BOOLEAN_H
#include <iostream>
using namespace std;
class boolean {
    private:
        char* array;
        int size;

    public:
        boolean(int size) {
            // TODO
            this->size=size;
            if(size%8==0){
                array = new char[size/8];
                for(int x=0;x<size/8;x++){
                    array[x]=0;
                }
            }
            else{
                array = new char[(size/8)+1];
                for(int x=0;x<(size/8)+1;x++){
                    array[x]=0;
                }
            }
        }

        void bitOn(int position) {
            array[position/8] |= 1 << (position%8);
        }

        void bitOff(int position) {
            array[position/8] &= ~(1 << (position%8));
        }

        bool operator[](int position) {
            // TODO
            return (array[position/8] >> (position%8)&1);
        }

        void clear() {
            // TODO
            if(size%8==0){
                for(int x=0;x<size/8;x++){
                    array[x]=0;
                }
            }
            else{
                for(int x=0;x<(size/8)+1;x++){
                    array[x]=0;
                }
            }
        }

        ~boolean() {
            // TODO
            delete array;
        }
};

#endif
