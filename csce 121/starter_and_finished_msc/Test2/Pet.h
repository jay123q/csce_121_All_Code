#ifndef PET_H
#define PET_H


class Pet
{
    private:
        std::string name;
        float weight;
        bool isAdopted;
    public:
       Pet Pet(std::string name, float weight, bool isAdopted);
       std::string getName();
       float getWeight();
       bool getIsAdopted();
}

#endif