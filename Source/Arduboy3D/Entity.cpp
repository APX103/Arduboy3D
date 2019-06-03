#include "Entity.h"
#include "Game.h"
#include "Map.h"

#define COLLISION_SIZE 48
#define ENTITY_SIZE 192

bool Entity::IsWorldColliding() const
{
	return Map::IsBlockedAtWorldPosition(x - COLLISION_SIZE, y - COLLISION_SIZE)
		|| Map::IsBlockedAtWorldPosition(x + COLLISION_SIZE, y - COLLISION_SIZE)
		|| Map::IsBlockedAtWorldPosition(x + COLLISION_SIZE, y + COLLISION_SIZE)
		|| Map::IsBlockedAtWorldPosition(x - COLLISION_SIZE, y + COLLISION_SIZE);
}

bool Entity::IsOverlappingEntity(const Entity& other) const
{
	return (x >= other.x - ENTITY_SIZE && x <= other.x + ENTITY_SIZE
		&& y >= other.y - ENTITY_SIZE && y <= other.y + ENTITY_SIZE);
}

bool Entity::IsOverlappingPoint(int16_t pointX, int16_t pointY) const
{
	return (pointX >= x - ENTITY_SIZE / 2 && pointX <= x + ENTITY_SIZE / 2
		&& pointY >= y - ENTITY_SIZE / 2 && pointY <= y + ENTITY_SIZE / 2);
}
