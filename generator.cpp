#include "./generator.hpp"

Generator::Generator(int upperBound, int rate): upBound(upperBound){
    if(rate == 0){

        genRate = 30;
    }
    genRate = rate;
    srand(time(NULL));
}

int Generator::generate(){ return (rand() % upBound); }
int Generator::rate(){return genRate;}