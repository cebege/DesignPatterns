#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declaration of Observer
class HealthObserver;

// Player Class (Subject)
class Player {
private:
    int health;
    vector<HealthObserver*> observers;

public:
    Player(int initHealth) : health(initHealth) {}

    void attach(HealthObserver* obs) {
        observers.push_back(obs);
    }

    void setHealth(int newHealth) {
        health = newHealth;
        notify();
    }

    int getHealth() const { return health; }

    void notify();
};

// Observer Abstract Class
class HealthObserver {
private:
    Player& player;

public:
    HealthObserver(Player& plyr) : player(plyr) { player.attach(this); }

    virtual void update(const Player& player) = 0;
};

// Concrete Observers
class UI : public HealthObserver {
public:
    UI(Player& plyr) : HealthObserver(plyr) {}

    void update(const Player& player) override {
        cout << "Updating UI: Player Health = " << player.getHealth() << endl;
    }
};

class SoundManager : public HealthObserver {
public:
    SoundManager(Player& plyr) : HealthObserver(plyr) {};

    void update(const Player& player) override {
        if (player.getHealth() < 20) {
            cout << "Playing low health sound effect" << endl;
        }
    }
};

class GameOverHandler : public HealthObserver {
public:
    GameOverHandler(Player& plyr) : HealthObserver(plyr) {};

    void update(const Player& player) override {
        if (player.getHealth() <= 0) {
            cout << "Game Over!" << endl;
        }
    }
};

void Player::notify()
{
    for (HealthObserver* obs : observers) {
         obs->update(*this);
    }
}

// Main Function
int main() {
    Player player(100);
    UI ui(player);
    SoundManager soundManager(player);
    GameOverHandler gameOverHandler(player);

    player.setHealth(50);  // Triggers UI and SoundManager update
    player.setHealth(10);  // Triggers UI, SoundManager, and potentially GameOverHandler update
    player.setHealth(0);   // Triggers all observers, including Game Over

    return 0;
}