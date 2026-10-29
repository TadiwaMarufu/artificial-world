#include <iostream>
#include <vector>
#include <string>



class Organism{
    private:
        std::string name;
        int id;
        int health;

    public:
        Organism(std::string name, int id, int health){
           this->name = name;
           this->id= id;
           this->health = health;
        };

        void displayOrganism(){
            std::cout<<"Name: "<<name<<'\n';
            std::cout<<"I.D: "<<id<<'\n';
            std::cout<<"Health: "<<health<<'\n';
        };
};

int main(){
    std::vector<Organism> organisms;

    organisms.push_back(Organism("alpha", 1, 100));
    organisms.push_back(Organism("beta", 2, 100));

    for(Organism organism:organisms){
       organism.displayOrganism();
    };

    return 0;


}
