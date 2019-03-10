#include "j1App.h"
#include "Render.h"
#include "Textures.h"
#include "Input.h"
#include "Entity.h"
#include "EntityManager.h"



EntityManager::EntityManager()
{
	name = "entity_manager";
}

EntityManager::~EntityManager()
{
}

bool EntityManager::Awake(pugi::xml_node &)
{
	return true;
}

bool EntityManager::Start()
{
	return true;
}

bool EntityManager::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_F9) == KEY_DOWN)
		draw_path = !draw_path;

	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->Update(dt);
	}

	return true;
}

bool EntityManager::PreUpdate()
{
	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->PreUpdate();
	}

	return true;
}

bool EntityManager::PostUpdate()
{
	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->PostUpdate();
	}

	return true;
}

bool EntityManager::CleanUp()
{
	for (std::list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity)
	{
		(*entity)->CleanUp();
	}
	entities.clear();
	id_count = 0;

	return true;
}

bool EntityManager::Load(pugi::xml_node &)
{
	return true;
}

bool EntityManager::Save(pugi::xml_node &) const
{
	return true;
}

bool EntityManager::CreateEntity(EntityType type, fPoint position)
{
	std::string id = std::to_string(id_count);
	switch (type)
	{
	case EntityType::TROOP:
		id += "_TROOP";
		entities.push_back(new Entity()); //here the constructor should be the one for the type
		break;
	}

	return true;
}

bool EntityManager::DeleteEntity(Entity * entity)
{
	return true;
}
