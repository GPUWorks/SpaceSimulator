#include "../include/ListLayout.hpp"
#include <iostream>

ListLayout::ListLayout(int x, int y, int width, int height, Config *config): Layout(x, y, width, height, config){
	// Debug
	if((debugLevel & 0x10) == 16){		
		std::cout << "ListLayout.cpp\t\tInitializing" << std::endl;
	}
}

ListLayout::~ListLayout(){
	// Debug
	if((debugLevel & 0x10) == 16){	
		std::cout << "ListLayout.cpp\t\tFinalizing" << std::endl;
	}
}

void ListLayout::addChild(View *view){	
	//Super
	Layout::addChild(view);

	int padding = 10;
	size_t childNumber = children->size();
	
	// Find Y coordinate
	int childY = y + padding; // Top padding
	for(size_t i=0; i<childNumber-1; i++){
		childY += (*children)[i]->getHeight() + padding; // 10 is padding
	}
	
	view->relocate(x + padding, childY, width - 2*padding, 30);
}
