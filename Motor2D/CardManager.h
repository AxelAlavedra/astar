#ifndef _CARD_MANAGER_H_
#define _CARD_MANAGER_H_

#include "p2Defs.h"
#include "Module.h"
#include "Animation.h"

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

	std::string name;
	uint level;
	bool to_delete = false;
	std::vector<Animation> animations;
};

class CardManager : public Module
{
public:
	CardManager();
	~CardManager();

	bool Awake(pugi::xml_node&);
	bool Start();
	bool CleanUp();
	bool PostUpdate();
	bool Load(pugi::xml_node&) { return true; }
	bool Save(pugi::xml_node&) const { return true; }

	Card* CreateCard(CardType type);
	Card* DeleteCard(Card* card);

private:
	bool to_delete = false;
	pugi::xml_document config_file;
	pugi::xml_node card_configs;
	std::list<Card*> cards;

	Card* test_card;
};

#endif // _CARD_MANAGER_H_


