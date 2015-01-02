#include "game.h"
#include <iostream>
#include <string>

using namespace lab3;


Game::Game(){

	Indoors my_cabin("This is my cabin");
	Outdoors forest1("The forest. If I look around I might find items.", {Unwearable("I see no use of this item", 4, "Just a regular coin.")})
	Outdoors demon_cave("The demon cave. Scary and stuff.");
	Outdoors winning_place("Goal!");

	my_cabin.setDirection("east", forest1);
	forest1.setDirection("west", my_cabin);
	forest1.setDirection("east", demon_cave);
	demon_cave.setDirection("west", forest1);
	demon_cave.setDirection("east", winning_place);
	winning_place.setDirection("west", demon_cave);

	Humanoid player(my_cabin);

	Monster demon(demon_cave, "YOU WILL DIE HERE");

	setRealPlayer(player);

	run();

}
void Game::set_real_player(Humanoid& real_player){
	this->real_player = &real_player;	// Can use address for equivalence check.
}

void Game::run(){

	while(!game_finished) {
		for(actor*:actors) {
			if(actor != &real_player){
				actor->action();
			} 
			else {
				std::cout << "your turn\n";
				next_turn = false;
				while(!next_turn){
					std::string command = "";
					std::cin.getline(command, 256);	// maximum number of characters
					execute_command(command);
				}
			}

		}

	}
}

void Game::execute_command(std::string command){
	//TODO
	// if command should end the player's turn set next_turn = true.
}

int main(){
	Game game;


	return 0;
}