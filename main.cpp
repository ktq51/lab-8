#include "character.h"

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();
void Level1Up();


int monsterhp = 0;
int monsterxp = 0;
int monsterlevel = 0;

std:: string monstername[] = {"Goblin", "Dwarf", "Ogre", "Witch", "Demon", "Wizard"};
int currentmonsternames = 5;
std:: string currentmonster = " ";

int counter = 0;

Character character;

int main() {

    character.characterCreation();

    HUD();
    Moving();

    return 0;

}
void HUD() { 
    system("sleep 2");
    system("clear");
    std::cout<< "Name: "<< character.name <<"       Health: "<< character.health << "\nRace: " << character.race 
       <<"\nSex: "<< character.sex<< "\nLevel: "<< character.level <<"\nXP: " <<character.current_xp << "\nXP to next level: "<< character.xp_to_level << std::endl;
    Moving();
}

void CombatHUD(){
    system("sleep 2");
    system("clear");
    std::cout<< "Name: "<<character.name<<"       |       Monater name: "<<
        currentmonster<<"\nHealth: "<< character.health<<"       |       Monster health: "<<
        monsterhp << "\nLevel: "<< character.level<< "        |       Monster Level: "<< monsterlevel<< std::endl;
}

void Combat(){ 
    CombatHUD();
    int playerAttack;
    int playerDamage = 8*character.level/2;
    int monsterAttack = 6* monsterlevel/2; 

    if(character.health>=0 && monsterhp>=1){
        std::cout<<"\n";
        std::cout<<"1. Attack\n";
        std::cout<<"2. Block\n";
        std::cout<<"3. RUN!\n";
        std::cout<<"\n";
        std::cin>> playerAttack;

        if(playerAttack ==1){
            std::cout<<"Attacking... you did "<< playerDamage<<" to the "<< currentmonster<< std::endl;
            monsterhp = (monsterhp-playerDamage<=0)? 0 : monsterhp-playerDamage;
            system("sleep 2");
            CombatHUD();
            
            if(monsterhp > 1){
                std::cout<<"\n";
                std::cout<<"Monster is attacking..\n";
                character.health = (character.health - monsterAttack <= 0) ? 0 : character.health - monsterAttack;
                std::cout<<"You suffered "<<monsterAttack<< " hp "<< character.health <<std::endl;

                if(character.health <= 0){
                    system("clear");
                    std::cout<< "You died! \nYou were level: "<<character.level<< " you got killed by: "<<currentmonster<<std::endl;
                    system("sleep 2");
                    exit(0);
                }
            }

            else if(monsterhp <= 0){
                monsterhp= 0;
                std::cout<<"\n";
                std::cout<< "You defeated "<< currentmonster<<" you are rewarded with "<< monsterxp << " xp.\nWell done!\n";
                
                if(character.level != character.maxlevel){
                    character.current_xp += monsterxp;
                    Level1Up();
                }
                system("sleep 2");
                  HUD();
            }
            system("sleep 2");
            Combat();
        }
        else if(playerAttack == 2){

            std::cout<<"Blocking\n";
            int i = rand() % 100 +1;
            if (i>= 50){
                std::cout<< "You blocked the incoming attack\n";
                character.heal = character.level * 10/2;
                std::cout<<"You have been healed for "<< character.heal << std::endl;
                character.health = (character.health + character.heal > character.totalhealth) ? character.totalhealth : character.health + character.heal;
                system("sleep 2");
                Combat();
            }
            else{
                std::cout<< "You failed to block the savage attack\n";
                character.health-= monsterAttack;
                character.health = (character.health - monsterAttack <= 0) ? 0 : character.health - monsterAttack;
                std::cout<<"You were stabbed in the back for "<<monsterAttack<< " current hp "<<character.health<<std::endl;
                system("sleep 2");
                if(character.health <= 0){
                    system("clear");
                    std::cout<< "You died! \nYou were level: "<<character.level<< " you got killed by: "<<currentmonster<<std::endl;
                    system("sleep 2");
                    exit(0);
                }
                Combat();
            }
        }
        else if(playerAttack == 3){
            std::cout<<"You try to run\n";
            int x = rand() % 100 +1;
            if(x >= 50){
                std::cout << "You run away\n";
                HUD();
            }
            else{
                std::cout<<"You failed to run away\n";
                std::cout<< "Monster does a savage attack on you!\n";
                character.health = (character.health - (monsterAttack+10) <= 0) ? 0 : character.health - (monsterAttack+10);
                std:: cout<< "You suffered "<<monsterAttack +10 << "Your current health is "<< character.health<<std::endl;
                system("sleep 2");
                if(character.health <= 0){
                    system("clear");
                    std::cout<< "You died! \nYou were level: "<<character.level<< " you got killed by: "<<currentmonster<<std::endl;
                    system("sleep 2");
                    exit(0);
                }
                Combat();
            }
        }
        else{
            std::cout<< "Invalid number\n";
            system("sleep 2");
            Combat();
        }
    }
}

void Moving(){ 

    int choice;

    std:: cout<< "\n\n";
    std:: cout<< "1. Moving forward\n";
    std:: cout<< "2. Relax\n";
    std:: cout<< "3. Moving backward\n";
    std:: cout<< "\n";

    std:: cin>> choice;

    if(choice == 1){
        int temp = rand() %100 + 1 ;
        std::cout<< "You begin moving forward...\n";
        if(temp>= 50){
            //encounter monster
            CreateMonster();
            std:: string tempName = monstername[rand() % currentmonsternames];
            std::cout<<"A "<< tempName << "! prepare to fight!\n";
            currentmonster = tempName;
            system("sleep 2");
            Combat();
        }
        std::cout<<"You find nothing of interest\n";
        system("sleep 2");
        HUD();
    }
    else if(choice == 2){
        std:: cout<< "You want to set up camp for the evening\n";
        if(character.health <= character.totalhealth){
            character.health = (character.health + 10*character.level>character.totalhealth)?character.totalhealth:character.health+10*character.level;
        }
        std:: cout<< "You healed by resting, Health is now "<< character.health << std::endl;
        system("sleep 2");
        HUD();
    }
    else if(choice == 3){
        int temp = rand() %100 + 1 ;
        std::cout<< "You begin moving backward...\n";
        if(temp>= 50){
            //encounter monster
            CreateMonster();
            std:: string tempName = monstername[rand() % currentmonsternames];
            std::cout<<"A "<< tempName << "! prepare to fight!\n";
            currentmonster = tempName;
            system("sleep 2");
            Combat();
        }
        std::cout<<"You find nothing of interest\n";
        system("sleep 2");
        HUD();
    }
    else{
        std::cout<<"Invalid number\n";
        system("sleep 2");
        Moving();
    }
}

void Level1Up(){

    if(character.current_xp >= character.xp_to_level){
        character.xp_to_level += floor(character.level+25 *pow(2, character.level/7));
        character.totalhealth = floor(character.totalhealth + 13 * pow(2, character.level/8));

        if(character.level >= character.min_level && character.level <= character.maxlevel){
            character.level++;
        }
        else{
            character.level = 60;
        }

        character.health = character.totalhealth;
        std:: cout<< "Wait what's this? A level up? You are now level "<< character.level<< std::endl;
        std:: cout<< " Your total health increasded. Now your health is "<< character.totalhealth<< std::endl;
        std::cout<<"\n";
        system("sleep 2");
        Level1Up();
    }
    system("sleep 2");
    HUD();
}


void CreateMonster(){
    monsterlevel = (rand() % 3)+ character.level;

    monsterhp = (rand() % 30)+ monsterlevel;


    monsterxp = monsterhp;

    if(monsterhp == 0){
        CreateMonster();
    }
    if(monsterlevel == 0){
        CreateMonster();
    }
}













