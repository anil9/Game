#include "humanoid.h"
#include <iostream>
#include <string>

using namespace lab3;

Humanoid::Humanoid(std::string name, Environment& location): Actor(name,location) {
	set_attack_points(10);
	set_hp(30);
}
void Humanoid::change_gear(Wearable* wearable) {
	if(wearable->get_type() == "weapon"){
		Weapon* weapon = dynamic_cast<Weapon*>(wearable);
		if(gear.at("weapon") == NULL){
			set_attack_points(get_attack_points() + weapon->get_damage());	
		}else{
			auto to_change = gear.at("weapon");
			Weapon* wp = dynamic_cast<Weapon*>(to_change);
			Pickup_able* pp = dynamic_cast<Pickup_able*>(to_change);
			get_container().pick_up(pp);
			set_attack_points(get_attack_points()-wp->get_damage()+weapon->get_damage());
		}
		gear.at("weapon")=wearable;
	}
	else if(wearable->get_type() == "armor"){
		Armor* armor = dynamic_cast<Armor*>(wearable);
		if(gear.at("armor")==NULL){
			set_hp(get_hp() + armor->get_protection());	
		}
		else{
			auto to_change = gear.at("armor");
			Armor* ap = dynamic_cast<Armor*>(to_change);
			Pickup_able* pp = dynamic_cast<Pickup_able*>(to_change);
			get_container().pick_up(pp);
			set_hp(get_hp()-ap->get_protection()+armor->get_protection());	
		}	
		gear.at("armor")=wearable;
	}
	std::cout<<"hp is: " + std::to_string(get_hp()) + " ap is: " + std::to_string(get_attack_points())<<std::endl;
	
		
}
void Humanoid::pick_up(Item* item) {
	
	Pickup_able* pa = dynamic_cast<Pickup_able*>(item);
	if(get_container().pick_up(pa)){
		get_location()->remove_item(item); 
	}

}
		
void Humanoid::drop(Item* dropping_item){
	Pickup_able* pa = dynamic_cast<Pickup_able*>(dropping_item); 
	if(get_container().drop(pa)){
		get_location()->add_item(dropping_item);
	}	
}

std::string Humanoid::get_answer(){
	return answer;
}
void Humanoid::set_answer(std::string new_answer){
	answer = new_answer;
}

