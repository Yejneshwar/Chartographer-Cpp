#include "Chartographer-Cpp.h"
#include <iostream>


void main(){
	ChartoGrapher::Connect("localhost:50051");
	std::cout << "Channel State : " << ChartoGrapher::getConnectivityState() << std::endl;
	ChartoGrapher::CreatePlot("test", GraphType::LINE);
	std::cout << "Channel State : " << ChartoGrapher::getConnectivityState() << std::endl;
	ChartoGrapher::UpdatePlot("test", 0, 0);
	ChartoGrapher::UpdatePlot("test", 1, 1);
	std::cout << "Channel State : " << ChartoGrapher::getConnectivityState() << std::endl;

	ChartoGrapher::CreatePlot("triangle1", GraphType::TRIANGLE);
	std::cout << "Channel State : " << ChartoGrapher::getConnectivityState() << std::endl;
	
	ChartoGrapher::UpdatePlot("triangle1", {0,0}, {1,1}, {1,0});
	std::cout << "Channel State : " << ChartoGrapher::getConnectivityState() << std::endl;

}