#include <iostream>

class Bird {
    public: //all can see
 
    Bird(double w){
    // kept in the family
        double  weight;
    }
    virtual void call(){
        std::cout<<"Tweet!"<< std::endl;
    }
    protected:
        double weight;
    private: // hide from everyone

};

class Duck : public Bird { //Birrd is a constructor method
    public:
        Duck(double w, double v) : Bird(w){
            quack_volume = v;
        }
        void call(){
            std::cout << "Quack!"<<std::endl;

        }
    protected:
    double quack_volume;
};
int main(){
    std::cout<<"Hello Word";
    Duck d(10.0,55.0); // d points to duck
    Bird *birdy = &daffy;   // this names method to call b to call method

    birdy->call(); // this cals the method, howevver if you runit without the (virtual tag) 
    //then it will run quack because there is no checker foor child methods

    daffy.call(); // this called duck method

}