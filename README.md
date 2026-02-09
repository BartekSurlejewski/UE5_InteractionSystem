# UE5_InteractionSystem
A prototype of a simple interaction system in Unreal Engine 5.6

## How To Start
- Clone the repository
- Fetch git LFS
- Start the project using Unreal Engine 5.6
- Ensure the open level is Lvl_InteractionPrototype
- Start game in editor

## Controls
- The prototype supports keyboard + mouse input. Feel free to extend it by modifying IMC_Default mapping context
- W,S,A,D - movement
- Space - jump
- E - interact
- Left Mouse Button - shoot (when weapon is equipped)

## Implementation description
- The prototype is based on Unreal's FPS starter content, which was modified for its purposes
- Movement - walking and jumping
- Interactable objects
- Placeholder HUD that displays current weapon, ammunition count and available interaction info
- Interaction text and key binding info is dynamically adjusted
- Rocket jump!
- Interactables UI feedback - highlighting the interactable objects and playing audio when using them
- All core functionalities were implemented in C++ code
- Blueprints were used for extending UI feedback with highlighting and audio

## Additional Info
- To add a new interactable object, create a blueprint class inheriting from the class that implements IInteractable interface
- BP_Weapon_Pickup_Base - base class for weapon pickups
- BP_Weapon_Base - base class for weapons
- DT_Weapons - data table that connects weapon pickups and weapons, and stores additional weapon info
- Player can only hold one weapon. When another weapon is picked up, a held weapon is dropped