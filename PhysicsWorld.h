#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Vector2d.h"

class Particle {
public:
	Vector2d position;
	Vector2d velocity;
	Vector2d acceleration;
	Vector2d forces;

	float mass;

	//Particle(Vector2d position, Vector2d velocity);
	Particle(Vector2d position, float mass = 1);

	void Update(float td);
	void addForce(Vector2d force);
};

class PhysicsWorld {
private:
	std::list<Particle*> particles;
public:
	void AddParticle(Particle* particle);
	void Update(float deltaTime);
};

void PhysicsWorld::AddParticle(Particle* particle) {
	particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime) {
	std::list<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); it++) {
		(**it).Update(deltaTime);
	}
}

//Particle::Particle(Vector2d position, Vector2d velocity) {
//	this->position = position;
//	this->velocity = velocity;
//}

Particle::Particle(Vector2d position, float mass) {
	this->position = position;
	this->mass = mass;
}

void Particle::addForce(Vector2d force) {
	forces += force;
}

void Particle::Update(float dt) {
	acceleration = forces * (1.0f / mass);
	velocity += dt * acceleration;
	position += dt * velocity;
	forces = Vector2d(0, 0);
}

