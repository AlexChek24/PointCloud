#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using Point = std::vector<double>;
class PointCloud
{
	std::vector<Point> Points;
	std::vector<double> angle;
public:
	PointCloud(std::string, std::vector<double>);
	void RotateCloud();
	void SaveAs();

};

