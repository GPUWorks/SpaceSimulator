#ifndef ABSTRACT_CAMERA_H
#define ABSTRACT_CAMERA_H

#include <stdlib.h>
#include <iostream>

#include "../include/common.hpp"
#include "../include/Config.hpp"
#include "../include/Renderable.hpp"
#include "../include/Shader.hpp"

// Function prototypes
class AbstractCamera: public Renderable{
	protected:
		// Camera
		glm::mat4 projection;
		glm::mat4 model;
		glm::mat4 view;

		glm::dvec3 position;
		glm::dvec3 direction;
		glm::dvec3 up;
		
		size_t debugLevel;
		bool active;
		
		// Camera visualization
		Shader *shader;
		GLuint vertexBuffer;
		GLuint colorBuffer;
		
		// Local buffer
		float *vertices;
		float *colors;
	public:
		/**
		* Creates the camera and initializes it in vec3(0, 0, 0)
		**/
		AbstractCamera(Config *config);
		
		/**
		* Finalizes the camera
		**/
		virtual ~AbstractCamera(void) = 0;
		
		/**
		* Returns the Model View Projection matrix
		**/
		glm::mat4 getMVP(void);
		
		/**
		* This is called from the Simulator
		**/
		virtual void checkUserInput(void) = 0;
		
		/**
		* Called when the camera is actived
		**/
		virtual void setActive(bool active);
		
		/**
		* Render camera data
		**/
		void render(const GLfloat *mvp);
		
};
#endif
