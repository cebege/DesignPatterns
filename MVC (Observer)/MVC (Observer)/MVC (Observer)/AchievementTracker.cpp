//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//// Forward declaration of AchievementObserver
//class AchievementObserver;
//
//// Model Class
//class Player {
//private:
//    int score;
//    int enemiesDefeated;
//    vector<AchievementObserver*> observers;
//
//public:
//
//    Player(int initScore = 0, int initEnemiesDefeated = 0, vector<AchievementObserver*> initObservers = {})
//        : score(initScore), enemiesDefeated(initEnemiesDefeated), observers(initObservers) {}
//
//    void attach(AchievementObserver* obs) {
//        observers.push_back(obs);
//    }
//
//    void setScore(int newScore) {
//        score = newScore;
//        notify();
//    }
//
//    void setEnemiesDefeated(int newEnemiesDefeated) {
//        enemiesDefeated = newEnemiesDefeated;
//        notify();
//    }
//
//    int getScore() const { return score; }
//    int getEnemiesDefeated() const { return enemiesDefeated; }
//
//    void notify();
//};
//
//// Observer Class
//class AchievementObserver {
//
//protected:
//    Player& player;
//    bool isUnlocked;
//
//public:
//    AchievementObserver(Player& plyr) : player(plyr), isUnlocked(false) { player.attach(this); }
//
//    virtual void update() {
//        if (!isUnlocked) {
//            if (checkUnlockCondition()) {
//                isUnlocked = true;
//                unlockAchievement();
//            }
//        }
//    }
//    virtual bool checkUnlockCondition() = 0;
//    virtual void unlockAchievement() = 0;
//};
//
//// Concrete Observers
//class HighScoreAchievement : public AchievementObserver {
//public:
//    HighScoreAchievement(Player& plyr) : AchievementObserver(plyr) {}
//
//    virtual bool checkUnlockCondition() override {
//        return player.getScore() > 1000;
//    }
//
//    virtual void unlockAchievement() override {
//        cout << "Achievement Unlocked: Gold Medal!" << endl;
//    }
//};
//
//class EnemyDefeatAchievement : public AchievementObserver {
//public:
//    EnemyDefeatAchievement(Player& plyr) : AchievementObserver(plyr) {}
//
//    virtual bool checkUnlockCondition() override {
//        return player.getEnemiesDefeated() > 50;
//    }
//
//    virtual void unlockAchievement() override {
//        cout << "Achievement Unlocked: Master Warrior!" << endl;
//    }
//};
//
// Implementing notify method in Player class
//void Player::notify() {
//    for (AchievementObserver* obs : observers) {
//        obs->update();
//    }
//}
//
////Main Function
//int main() {
//    Player player;
//    HighScoreAchievement highScoreAchievement(player);
//    EnemyDefeatAchievement enemyDefeatAchievement(player);
//
//    player.setScore(1500);  // Triggers High Score Achievement
//    player.setEnemiesDefeated(51);  // Triggers Enemy Defeat Achievement
//
//    return 0;
//}

/*
MVC Pattern

Model (Player): Holds the application's data and business logic. In this case, it's the state of the game (score and enemies defeated).
View: Represents the presentation of the model. In this simple program, the console output acts as a rudimentary view, displaying messages when achievements are unlocked.
Controller: Accepts input and converts it to commands for the model or view. The main function plays this role, altering the state of the Player model.

1) Controller Interaction:

The main function (acting as a controller) modifies the Player object by setting its score and enemies defeated.

2) Model Update:

The Player object (the model) updates its state and notifies the observers about these changes.

3) View Update:

The observers, upon being notified of the model's change, potentially trigger a view update (console output) by unlocking achievements.

*/