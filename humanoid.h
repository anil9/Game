#ifndef HUMANOID_H
#define HUMANOID_H
#include "actor.h"
#include "wearable.h"
#include "pickup_able.h"
#include "environment.h"
#include "container.h"
#include <string>
#include <vector>

namespace lab3{
	class Humanoid: public Actor {
	public:
		Humanoid(std::string, Environment&);
		void change_gear(Wearable&);
		void talk_to(Actor&);
		void pick_up(Item*);
		void drop(Item*);
		Container& get_container();

	private:
		Container mybag;
	};
}
#endif