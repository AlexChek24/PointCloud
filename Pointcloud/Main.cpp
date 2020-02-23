#include "PointCloud.h"

int main(int argc, char** argv) {
	std::cout << argc;
	std::string filename(argv[1]);
	std::vector<double> angle;
	for (int i = 2; i < argc; i++)
		angle.push_back(atof(argv[i]));
	PointCloud p(filename,angle);
	p.RotateCloud();
	p.SaveAs();
	return 0;
}
 