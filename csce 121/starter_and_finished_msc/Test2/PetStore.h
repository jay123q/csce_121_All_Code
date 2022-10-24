#ifndef PETSTORE_H
#define PETSTORE_H

class PetStore
{
    private:
        std::string name;
      //    std::vector<Post*> tagPosts;
        std::vector<availablePets> Collection;
    public:
        std::string PetStore(std::string name);
        std::string getName();
        PetStore addPet(Pet(std::string name,float weight,bool isAdopted));
}



#endif