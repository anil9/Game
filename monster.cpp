#include "monster.h"
#include <iostream>

using namespace lab3;


Monster::Monster(std::string noice): Actor(){

	this->noice = noice;
}
std::string Monster::make_noice(){
	return noice;
}

/*
int main() {

	Monster last_boss("MUAHAHAHAH");
	Monster dragon("FCHHH");
	std::cout << last_boss.make_noice() << std::endl;

	last_boss.set_attack_points(7);
	last_boss.set_hp(10);
	dragon.set_attack_points(5);
	dragon.set_hp(7);

	last_boss.fight(dragon);
	std::cout << "health of dragon after being hit: " << dragon.get_hp() << std::endl;

	return 0;
}
*/