#ifndef ARMOR_H
#define ARMOR_H
#include "wearable.h"
#include <string>

namespace lab3{
	class Armor: public Wearable{
	public:
		Armor(int protection, int weight, std::string description, std::string name, std::string type);
		int get_protection();
		std::string get_stats()override;
	private:
		int protection;
	};
}
#endif