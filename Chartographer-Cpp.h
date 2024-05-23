#include <string>
#include <memory>
#include <vector>
#include <array>


enum GraphType {
	BAR = 0,
	LINE = 1,
	PIE = 2,
	SCATTER = 3,
	TRIANGLE = 4,
};

class ChartoGrapher {
private:
	static std::string address;


public:
	static void Connect(std::string address);

	static std::string getConnectivityState();

	static void CreatePlot(std::string plotId, GraphType type);

	static void UpdatePlot(std::string plotId, double x, double y);

	static void UpdatePlot(std::string plotId, std::vector<double[2]> points);

	static void UpdatePlot(std::string plotId, std::array<double,3> p1, std::array<double, 3> p2, std::array<double, 3> p3, std::array<float, 4> color = { 1.0,1.0,1.0,1.0 });

	static void UpdatePlot(std::string plotId, std::array<double, 3> p1, std::array<double, 3> p2, std::array<double, 3> p3, std::array<float, 4> c1, std::array<float, 4> c2, std::array<float, 4> c3);

};