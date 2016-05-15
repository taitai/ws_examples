#include "ParticleVec2.h"

ParticleVec2::ParticleVec2(){
    position.set(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity.set(0, 0);
    acceleration.set(0, 0);
    mass = 1.0;
    radius = 5.0;
    friction = 0.01;
}

void ParticleVec2::update(){
    acceleration -= velocity * friction;
    velocity += acceleration;
    position += velocity;
    acceleration.set(0, 0);
}

void ParticleVec2::draw(){
    ofDrawCircle(position.x, position.y, radius);
}

void ParticleVec2::addForce(ofVec2f force){
    acceleration += force / mass;
}