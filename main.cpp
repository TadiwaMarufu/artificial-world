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

class World{
    private:
        std::string worldName;
        std::vector<Organism> organisms;

    public:
       World(std::string worldName){
           this->worldName = worldName;
       };


        void createOrganism(Organism& organism){
            organisms.push_back(organism);
        };
};

int main(){

    World myWorld("myWorld");

    return 0;


}
