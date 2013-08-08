#include "lest.hpp"

#include <anax/anax.hpp>

#include "Systems.hpp"

void createMoveableEntities(int amount, World& world);
void createPlayers(int amount, World& world);
void createNPCs(int amount, World& world);
void createNPCsAndPlayers(int amount, World& world);

const lest::test specification[] =
{
	"MovementSystem" []
	{
		anax::World world;
		MovementSystem movementSystem;
		world.addSystem(movementSystem);
		
		createMoveableEntities(rand() % 100 + 1, world);
		createPlayers(rand() % 100 + 1, world);
		
		for(int i = 0; i < 5; ++i)
		{
			world.refresh();
			movenetSystem.update();
		}
	}
	
	"PlayerSystem" []
	{
		anax::World world;
		PlayerSystem playerSystem;
		world.addSystem(playerSystem);
		
		createNPCsAndPlayers(rand() % 100 + 1, world);
		createPlayers(rand() % 100 + 1, world);
		createNPCs(rand() % 100 + 1, world);
		
		world.refresh();
	}
};

void createMoveableEntities(int amount, World& world)
{
	auto entities = world.createEntities(amount);
	for(auto e : entities)
	{
		e.addComponent<PositionComponent>();
		e.addComponent<VelocityComponent>();
		e.activate();
	}
}
void createPlayers(int amount, World& world)
{
	std::ostringstream temp;
	auto entities = world.createEntities(amount);
	for(std::size_t i = 0; i < entities.size(); ++i)
	{
		temp << "Player " << i;
		entities[i].addComponent<PlayerComponent>().name = temp.str();
		temp.clear();
		
		entities[i].activate();
	}
}
void createNPCs(int amount, World& world)
{
	for(std::size_t i = 0; i < entities.size(); ++i)
	{
		e.addComponent<NPCComponent>();
		e.activate();
	}
}
void createNPCsAndPlayers(int amount, World& world)
{
	std::ostringstream temp;
	auto entities = world.createEntities(amount);
	for(std::size_t i = 0; i < entities.size(); ++i)
	{
		temp << "Player " << i;
		e.addComponent<PlayerComponent>().name = temp.str();
		temp.clear();
		e.addComponent<NPCComponent>();
		
		entities[i].activate();
	}
}