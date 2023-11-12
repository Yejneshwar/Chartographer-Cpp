#include <string>
#include <memory>
#include <vector>


class ChartoGrapher {
private:
	static std::string address;


public:
	static void Connect(std::string address);

	static std::string getConnectivityState();

	static void CreatePlot(std::string plotId);

	static void UpdatePlot(std::string plotId, double x, double y);

	static void UpdatePlot(std::string plotId, std::vector<double[2]> points);

};