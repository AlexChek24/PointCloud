#define _USE_MATH_DEFINES
#include "PointCloud.h"
#include <cmath>
#include <iterator>
PointCloud::PointCloud(std::string filename, std::vector<double> angle) {
	std::ifstream input;
	this->angle.assign(3,45);
	std::vector<double> tmp(3);
	for (int i = 0; i < angle.size(); i++) {
		if (angle[i] != 0)
			this->angle[i] = angle[i];
	}
	input.open(filename.c_str());
	while (!input.eof()) {
		std::copy_n(std::istream_iterator<double>(input), 3, tmp.begin());
		Points.push_back(tmp);
	}
}

void PointCloud::RotateCloud() {
	double alpha = (angle[0] * M_PI / 180);
	double beta = (angle[1] * M_PI / 180);
	double gamma = (angle[2] *M_PI / 180);
	for (Point &x : Points) { //поворот по оси X
		double tmp = x[1];
		x[1] = x[1] * cos(alpha) + x[2] * sin(alpha);
		x[2] = tmp * (-sin(alpha)) + cos(alpha) * x[2];
	}
	for (Point &x : Points) {// по Y
		double tmp = x[0];
		x[0] = x[0] * cos(beta) + x[2] * (-sin(beta));
		x[2] = tmp * (sin(beta)) + cos(beta) * x[2];
	}
	for (Point &x : Points) {// по Z
		double tmp = x[0];
		x[0] = x[0]*cos(gamma)+x[1]*sin(gamma);
		x[1] = tmp * (-sin(gamma)) + cos(gamma) * x[1];
	}
}

void PointCloud::SaveAs() {
	std::ofstream f("newPoincloud.xyz");
	for (Point x : Points) {
		for (auto i = 0; i < 3; i++) {
			f << x[i] << " ";
		}
		f << std::endl;
	}
	f.close();
}