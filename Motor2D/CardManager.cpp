#include "CardManager.h"



CardManager::CardManager()
{
}


CardManager::~CardManager()
{
}

bool CardManager::CleanUp()
{
	//TODO
	return true;
}

Card* CardManager::CreateCard(CardType type)
{
	Card* card = new Card;
	card->type = type;
	card->info = library[type];
	card->level = 0;

	return card;
}
