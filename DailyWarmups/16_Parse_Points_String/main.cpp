#include <string>
#include <vector>
#include <iostream>

struct Point { int x; int y; };

std::vector<Point> ParsePointString(const std::string& s)
{
	Point buff{ 0, 0 };
	std::vector<Point> v;

	for (auto n : s)
	{
		if (n != ' ') buff += n; else
			if (n == ' ' && buff != "") { v.push_back(buff); buff = ""; }
	}
	if (buff != "") 
		v.push_back(buff);

	return v;
}
int main(int argc, char** argv)
{
	std::string sPoints = "0,0 -3,-214 187,-422 196,-862 -95,-1044 -461,-1219 -732,-1310 -950,-1338 -1213,-1339";
	auto points = ParsePointString(sPoints);
	for (auto& point : points)
	{
		std::cout << point.x << "\t" << point.y << std::endl;
	}
	return 0;
}