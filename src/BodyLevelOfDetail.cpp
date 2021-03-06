#include "../include/BodyLevelOfDetail.hpp"

BodyLevelOfDetail::BodyLevelOfDetail(std::vector<Body*> *bodies, Config *config){
	// Debug
	this->debugLevel = config->getDebugLevel();
	this->config = config;
	if((debugLevel & 0x10) == 16){
		std::cout << "BodyLevelOfDetail.cpp\tInitializing" << std::endl;
	}
	
	// Init
	this->max = config->getMaxBodyLod();
	this->min = config->getMinBodyLod();
	this->bodies = bodies;
}

BodyLevelOfDetail::~BodyLevelOfDetail(){
	if((debugLevel & 0x10) == 16){
		std::cout << "BodyLevelOfDetail.cpp\tFinalizing" << std::endl;
	}
}

void BodyLevelOfDetail::update(glm::dvec3 cameraPosition){
	if(debugLevel & 128){
		std::cout << "BodyLevelOfDetail.cpp\tupdate()" << std::endl;
	}

	for(size_t i=0; i<bodies->size(); i++){
		Body *body = (*bodies)[i];
	
		float temp = 2*asin(body->getRadius()/glm::length(body->getCenter() - cameraPosition));
		
		size_t lod = temp * 5;
		
		if(lod < min){lod = min;}
		if(lod > max){lod = max;}
		
		if(lod != body->getLOD() && lod >= 0){
			body->setLOD(lod);
			body->generateVertices(lod);
		}
	}
}
