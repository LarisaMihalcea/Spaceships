#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Spaceship{
private:
    string  mName;
    int mAttack, mShield;
public:
    Spaceship(): Spaceship{"undefined", 0, 0} {}
    Spaceship(string name, int attack, int shield): mName{name}, mAttack{attack}, mShield{shield} {}
    Spaceship(const Spaceship &other){
        this->mName =other.mName;
        this->mAttack=other.mAttack;
        this->mShield=other.mShield;
    }

    string getName() const{
        return mName;
    }
    int getAttack() const{
        return mAttack;
    }
    int getShield() const{
        return mShield;
    }
    void setName(string name){
        mName=name;
    }
    void setAttack(int attack){
        mAttack=attack;
    }
    void setShield(int shield){
        mShield=shield;
    }

    Spaceship operator = (const Spaceship &other){
        this->mName = other.mName;
        this->mAttack=other.mAttack;
        this->mShield=other.mShield;
        return *this;
    }

    Spaceship operator += (const Spaceship &other){
        this->mAttack+=other.mAttack;
        this->mShield+=other.mShield;
        return *this;
    }

    Spaceship operator -= (const Spaceship &other){
        this->mShield-=other.mAttack;
        return *this;
    }

    Spaceship operator ^ (const Spaceship &other){
        Spaceship x(mName, mAttack, mShield);
        Spaceship y(other.mName, other.mAttack, other.mShield);
        while(x.mShield >0 && y.mShield >0){
            x -=y;
            if(x.mShield>0) {
                y-=x;
            } else return other;
        }
        return *this;
    }

    bool operator < (const Spaceship &other){
        if((this->mAttack+ this->mShield) > (other.mAttack+other.mShield)) return true;
        else return false;
    }
};


    int find_spaceship_position(const string &name, const vector<Spaceship> &v) {
        auto it = find_if(v.begin(),v.end(), [&name](const Spaceship& ship){
            return ship.getName() ==name;
        });
        if(it !=v.end()){
            return distance(v.begin(), it);
        } else return -1;
    }


int main() {

    int n;
    cout<<"Enter the number of spaceships: ";
    cin>>n;
    string name;
    int attack, shield;
    vector<Spaceship> spaceships;
    for(int i=0;i<n;i++){
        cout<<"Enther the ship's name, attack and shield: ";
        cin>>name>>attack>>shield;
        spaceships.push_back(Spaceship(name,attack,shield));
    }
    int k;
    cout<<"Enter the number of commands: ";
    cin>>k;
    string command, spaceshipX_name, spaceshipY_name;
    for(int i=0;i<k;i++){
        cout<<"Enter the command: ";
        cin>>command>>spaceshipX_name>>spaceshipY_name;
        int index1= find_spaceship_position(spaceshipX_name, spaceships);
        int index2= find_spaceship_position(spaceshipY_name,spaceships);
        if(command=="fight"){
            spaceships[index1]=spaceships[index1]^spaceships[index2];
            vector<Spaceship>::iterator it =spaceships.begin()+index2;
            spaceships.erase(it);

        } else if(command=="transfer"){
            spaceships[index1] += spaceships[index2];
            vector<Spaceship>::iterator it =spaceships.begin()+index2;
            spaceships.erase(it);
        } else cout<<"Invalid command";
    }

    sort(spaceships.begin(), spaceships.end(), [](Spaceship &a, Spaceship &b){
        return a < b;
    });

    for(int i=0;i<spaceships.size();i++){
        cout<<spaceships[i].getName()<<endl;
    }


    return 0;
}
