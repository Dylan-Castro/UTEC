#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
    private:
        T* data;
        int dataSize;
        int dimensions;
        int* dimensionSizes;
        Operation ope;
    public:
        Vector() : data(nullptr) {};
        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes) {
            // TODO
            dataSize=1;
            for(int x=0;x<dimensions;x++){
                dataSize*=dimensionSizes[x];
            }
            data = new T[dataSize];
        }
        void set(T datum, int* coordinates){
        // TODO
            int position=ope(coordinates,dimensionSizes,dimensions);
            data[position]=datum;
        }
        T get(int* coordinates){
        // TODO
            int position=ope(coordinates,dimensionSizes,dimensions);
            return data[position];
        }
};

#endif
