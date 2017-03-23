#pragma once

class Movable {
private:
	// degrees
	float direction;
	float slowdown;
	float speed;

public:
	void setDirection(float deg) {
		this->direction = direction;
	}

	void setSlowdown(float slowdown) {
		this->slowdown = slowdown;
	}

	void setSpeed(float spd) {
		this->speed = spd;
	}

	float getDirection() const{
		return this->direction;
	}

	float getSlowdown() const {
		return this->slowdown;
	}

	float getSpeed() const {
		return this->speed;
	}
};