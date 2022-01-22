//
//  Range.hpp
//  Lab: Range 2.4
//
//  Created by Coleton Watt on 1/22/22.
//

#ifndef Range_hpp
#define Range_hpp

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Range;

template <class Type>
ostream& operator << (ostream &, Range<Type> &);


template <class T>
class Range{
private:
    T start;
    T end;
    T step;
public:
    vector<T> numbers;
    Range(T start, T end): start(start), end(end){
        if((end-start) > 0){
            for(T i = start; i <= end; i++){
                numbers.push_back(i);
            }
        }else if((end-start) < 0){
            for(T i = start; i >= end; i--){
                numbers.push_back(i);
            }
        }
    }
    Range(T start, T end, T step): start(start), end(end), step(step){
        if(step > 0){
            for(T i = start; i <= end;){
                numbers.push_back(i);
                i += (step);
            }
        } else if (step < 0){
            for(T i = start; i >= end;){
                numbers.push_back(i);
                i += step;
            }
        }
    }
    int length();
    T sum();
    T average();
    T min();
    T max();
    
    friend ostream& operator << <>(ostream &, Range<T> &);

};

template <class T>
int Range<T>::length(){
    int x = numbers.size();
    //cout << x;
    return x;
}

template <class T>
T Range<T>::sum(){
    T x = 0;
    for(int i = 0; i < numbers.size(); i++){
        x += numbers[i];
    }
    return x;
};

template <class T>
T Range<T>::average(){
    T x = 0;
    for(int i = 0; i < numbers.size(); i++){
        x += numbers[i];
    }
    x/=numbers.size();
    return x;
}

template <class T>
T Range<T>::min(){
    T x = numbers[0];
    for(int i = 0; i < numbers.size(); i++){
        if(x >= numbers[i]){
            x = numbers[i];
        }
    }
    
    return x;
}

template <class T>
T Range<T>::max(){
    T x = numbers[0];
    for(int i = 0; i < numbers.size(); i++){
        if(x <= numbers[i]){
            x = numbers[i];
        }
    }
    
    return x;
}

template <class T>
ostream& operator << (ostream &out, Range<T> &something){
    for(int i = 0; i < something.numbers.size(); i++){
        out << something.numbers[i];
        if(i != (something.numbers.size()-1))
            out << ", ";
    }
     


    return out;
}
#endif /* Range_hpp */
