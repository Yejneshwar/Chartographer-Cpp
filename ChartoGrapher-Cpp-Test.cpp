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
	//Triangle(39.572854, -76.559972) (39.586483, -76.564849) (39.600524, -76.568366) | Infected 0
	//Triangle(39.600524, -76.568366) (39.586483, -76.564849) (45.419816, -80.935279) | Infected 0
	//ChartoGrapher::UpdatePlot("triangle1", {39.572854, -76.559972, 0.0}, { 39.586483, -76.564849, 0}, { 39.600524, -76.568366, 0});
	//ChartoGrapher::UpdatePlot("triangle1", {39.600524, -76.568366, 0.0}, { 39.586483, -76.564849, 0}, { 45.419816, -80.935279, 0});


	//Draw cube mesh
	ChartoGrapher::CreatePlot("mesh1", GraphType::TRIANGLE);

	//Front
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, { 1.0,0.0,0.0,1.0 }, { 0.0,1.0,0.0,1.0 }, { 0.0,0.0,1.0,1.0 });
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 0 }, { 1, 1, 0 }, { 0, 1, 0 }, { 0.0,0.0,1.0,1.0 }, { 0.0,1.0,0.0,1.0 }, { 1.0,0.0,0.0,1.0 });

	//Back
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, { 1.0,0.0,1.0,1.0 });
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 1 }, { 1, 1, 1 }, { 0, 1, 1 }, { 1.0,1.0,0.0,1.0 });

	//Top
	ChartoGrapher::UpdatePlot("mesh1", { 0, 1, 0 }, { 1, 1, 0 }, { 1, 1, 1 }, { 1.0,1.0,1.0,1.0 });
	ChartoGrapher::UpdatePlot("mesh1", { 0, 1, 0 }, { 1, 1, 1 }, { 0, 1, 1 }, { 0.0,1.0,1.0,1.0 });

	//Bottom
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 0 }, { 1, 0, 0 }, { 1, 0, 1 }, { 1.0,0.0,0.0,1.0 });
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 0 }, { 1, 0, 1 }, { 0, 0, 1 }, { 1.0,0.0,0.0,1.0 });

	//Left
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 0 }, { 0, 1, 0 }, { 0, 1, 1 }, { 1.0,0.0,0.0,1.0 });
	ChartoGrapher::UpdatePlot("mesh1", { 0, 0, 0 }, { 0, 1, 1 }, { 0, 0, 1 }, { 1.0,0.0,0.0,1.0 });

	//Right
	ChartoGrapher::UpdatePlot("mesh1", { 1, 0, 0 }, { 1, 1, 0 }, { 1, 1, 1 }, { 1.0,0.0,0.0,1.0 });
	ChartoGrapher::UpdatePlot("mesh1", { 1, 0, 0 }, { 1, 1, 1 }, { 1, 0, 1 }, { 1.0,0.0,0.0,1.0 });




	std::cout << "Channel State : " << ChartoGrapher::getConnectivityState() << std::endl;

}