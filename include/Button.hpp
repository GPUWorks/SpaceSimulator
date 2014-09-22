#ifndef BUTTON_H
#define BUTTON_H

#include "../include/TextView.hpp"
#include <string>

class Button: public TextView{
	public:
		/**
		* Creates a button object
		**/
		Button(std::string text);
		
		/**
		*
		**/
		~Button();
		
		/**
		* Called when the view has been clicked on
		**/
		virtual void clicked(int button, int action);
};

#endif