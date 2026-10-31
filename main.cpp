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

        void loseHealth(int amount){
           health -= amount;
        };
};

class World{
    private:
        std::string worldName;
        std::vector<Organism> organisms;
        int currentStep;


    public:
       World(std::string worldName){
           this->worldName = worldName;
           this->currentStep = 0;
       };

 
        void addOrganism(Organism& organism){
            organisms.push_back(organism);
        };

        void displayOrganisms(){
            for(Organism& organism:organisms){
                organism.displayOrganism();
            };
        };

        void advanceStep(){
            currentStep += 1;
        };

        void displayStep(){
            std::cout<<"Current step: "<<currentStep<<'\n';
        };


        void ageOrganism(){
            for(Organism& organism:organisms){
                organism.loseHealth(1);
            };

        };

        void runSimulation(int steps){
            for(int i=0; i<steps; i++){
                advanceStep();
                
                if(currentStep % 4 == 0){

                    ageOrganism();

                };

                displayStep();
            };
        };



};

int main(){

    World myWorld("myWorld");

    Organism organism1("alpha", 1, 100);

    myWorld.addOrganism(organism1);


    myWorld.displayOrganisms();
    myWorld.runSimulation(8);


    myWorld.displayOrganisms();

    return 0;


}
