#include "p2Log.h"
#include "CardManager.h"



CardManager::CardManager()
{
	name = "card_manager";
}


CardManager::~CardManager()
{
}

bool CardManager::CleanUp()
{
	//TODO
	return true;
}

bool CardManager::Awake(pugi::xml_node& conf)
{
	pugi::xml_parse_result result = config_file.load_file("cards.xml");

	if (result == NULL)
		LOG("Could not load map xml file config.xml. pugi error: %s", result.description());
	else
		card_configs = config_file.child("config");

	return true;
}
bool CardManager::Start()
{
	CreateCard(G_I);

	return true;
}

Card* CardManager::CreateCard(CardType type)
{
	Card* card = new Card;
	card->type = type;
	card->level = 0;

	//TODO look for info in xml with position same as type.
	pugi::xml_node card_node = card_configs.find_child_by_attribute("type", std::to_string((int)type).c_str());
	card->name = card_node.child("name").child_value();


	return card;
}
