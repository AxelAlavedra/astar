#ifndef _CARD_MANAGER_H_
#define _CARD_MANAGER_H_

#include "p2Defs.h"
#include "Module.h"

enum AttackType {
	BASIC,
	AOE,
	PIERCING
};

enum CardType {
	G_I,
	SNIPER,
	NAVY_SEAL,
	GRIZZLY
	//...
};

struct CardScaling {
	uint health_upgrade;
	uint attack_damage_upgrade;
	uint defense_upgrade;
	uint movement_speed_upgrade;
	uint attack_speed_upgrade;
	uint range_upgrade;
};
struct CardInfo {
	AttackType attack_type;
	CardScaling scaling;

	uint life;
	uint defense;
	uint movement_speed;
	uint attack_damage;
	uint attack_speed;
	uint range;
	uint energy_cost;
	uint unit_number;
	bool armored;

	std::string sprite;
};
struct Card {
	CardType type;
	CardInfo info;

	uint level;
	bool to_delete = false;
};

class CardManager : public Module
{
public:
	CardManager();
	~CardManager();

	bool CleanUp();

	Card* CreateCard(CardType type);

private:
	std::vector<CardInfo> library;
	std::list<Card*> created_cards;
};

#endif // _CARD_MANAGER_H_


