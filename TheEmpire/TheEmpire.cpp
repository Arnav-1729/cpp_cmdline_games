#include<bits/stdc++.h>
using namespace std;

const int Empire_level =1;
const int Gold =1000;
const int Food=1000;
const int Troop_capacity=20;

class Player{
    private:
        string name;
        int empire_level;
        int gold;
        int food;
        int troop_capacity;
        vector<string> troops;
    public:
        Player(string playerName){
            name=playerName;
            empire_level=Empire_level;
            gold=Gold;
            food=Food;
            troop_capacity=Troop_capacity;
            troops=vector<string >();
        }
    void print_resources(){
        cout<<"Gold: " << gold << endl;
        cout<<"Food: " << food << endl;
    }
    void print_troops(){
        cout<<"Troops: " << endl;
        for(const auto& troop: troops){
            cout<<troop<<endl;
        }
    }
    void attack(){
        int enemy_empire_level=rand()%10 +1;
        if(empire_level>enemy_empire_level){
            cout<<"You won the attack!! :)"<<endl;
        }
        else{
            cout<<"You lost the attack!! :("<<endl;
        }
    }
    void train_troop(string troop_name, int troop_cost) {
        int n=troops.size();
        if ( troop_capacity >= n ) {
            cout << "Troop capacity reached. Upgrade your camps to train more troops." <<endl;
        } 
        else {
            if(gold >= troop_cost) {
                gold -= troop_cost;
                troops.push_back(troop_name);
            }
            else{
                cout << "Not enough gold to train the troops. " <<endl;
            }
        }
    }
};
void game_loop(){
    cout<<"Welcome to Empire Battle(command line version)"<<endl;
    cout<<"~Victory stays with the supports the brave~"<<endl;
    string player_name;
    cout <<"Enter - Your Name: ";
    cin >> player_name;
    Player player(player_name);
        
    while (true) {
        cout << "\n[MAIN MENU]" << endl;
        cout << "1. Print Resources" << endl;
        cout << "2. Print Troops" <<  endl;
        cout << "3. Train Troops" << endl;
        cout << "4. Attack" << endl;
        cout << "5. Quit" <<  endl;
        cout << "Enter your choice: ";
        string choice;
        cin >> choice;
        if (choice == "1") {
            player.print_resources();
        }
        else if (choice == "2") {
            player.print_troops();
        }
        else if (choice == "3") {
            string troop_name;
            int troop_cost;
            cout << "Enter the Troop name: ";
            cin >> troop_name;
            cout << "Enter the troop cost: ";
            cin >> troop_cost;
            player.train_troop(troop_name, troop_cost);
        }
        else if (choice == "4") {
            player.attack();
        }
        else if (choice == "5") {
            cout<<"Thanks for playing Empire Battle !";
            break;
        }
        else{    
            cout<<"Invalid Choice. Try Again."<<endl;
        }
    }
}
int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    game_loop();
    return 0;

}
