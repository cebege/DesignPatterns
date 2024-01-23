/* 
----------------------------------------------------------------------------------------------------------------------------------------------------------------

Observer Pattern :

Subject (Player): This is the class being observed. It holds the state (score and enemies defeated) and notifies the observers when this state changes.
Observers (HighScoreAchievement, EnemyDefeatAchievement) : These classes watch for changes in the Player. When Player changes(score or enemies defeated),
they react by checking their conditions and potentially unlocking an achievement.

Flow of the Observer Pattern:

1) Initialization:
    A Player object is created. Observer objects (HighScoreAchievement and EnemyDefeatAchievement) are created and attached to the Player.

2) State Change in Player :
    When setScore or setEnemiesDefeated is called, the Player changes its internal state and calls notify().

3) Notification :
    The notify() method in Player iterates over all attached observers and calls their update() method.

4) Observer Reaction :
    Each observer checks if their specific condition to unlock the achievement is met. If it is, they mark the achievement as unlocked and output a message.


----------------------------------------------------------------------------------------------------------------------------------------------------------------

Game System Applications:

1) Game State Management:

Tracking changes in game state (e.g., level up, health change, mana depletion).
Notifying various subsystems (like UI, sound effects, or game logic) to react accordingly.

2) Achievement and Quest Systems:

As demonstrated within, tracking player progress and unlocking achievements or advancing quest stages when certain conditions are met.

3) Event Handling Systems:

Handling events like keyboard inputs, mouse clicks, or touch events.
Different game elements can observe these events and react, such as moving a character, selecting a menu item, or firing a weapon.

4) AI and Enemy Behavior:

NPCs or enemies can observe player actions or environmental changes and change their behavior or strategy accordingly.

5) Multiplayer and Networking:

In multiplayer games, changes in one player’s game state can be observed by the system to update other players in real-time.

6) Environmental Effects:

Elements like weather or day/night cycles can change, with various game elements observing these changes to modify visual effects, game mechanics, or enemy behavior.

7) Inventory Systems:

Observing changes in a player’s inventory (items added or removed) to update the UI, modify player stats, or trigger specific game events.

8) Dynamic Difficulty Adjustment:

Observing player performance and adjusting game difficulty dynamically. For example, reducing enemy strength if the player is losing health too quickly.

9) Game Analytics and User Feedback:

Tracking player actions and choices, then responding with in-game changes, adaptive tutorials, or collecting data for game improvement.

10) Physics and Collision Systems:

Objects in a physics engine can observe collisions and react, like playing a sound effect when two objects collide or triggering a game event upon specific collisions.

*/