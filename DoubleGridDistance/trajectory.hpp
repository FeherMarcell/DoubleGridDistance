#pragma once

#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

namespace meetyouthere{

struct Point{
	Point(double lat, double lon) : latitude(lat), longitude(lon){ };
	Point(const Point& theOther) : latitude(theOther.latitude), longitude(theOther.longitude){ };

	double latitude;
	double longitude;
};

struct BoundingBox{
	BoundingBox(const Point& southWest, const Point& northEast) : 
		southWest(southWest), northEast(northEast) { }
	
	BoundingBox(const BoundingBox& theOther) :
		southWest(theOther.southWest), northEast(theOther.northEast){ }

	const Point &southWest;
	const Point &northEast;
};

struct Trajectory{

	Trajectory(const vector<Point>& points, double averageLatitude, const BoundingBox& boundingBox) :
		points(points), averageLatitude(averageLatitude), boundingBox(boundingBox){ }

	Trajectory(const Trajectory& theOther) : 
		boundingBox(theOther.boundingBox), averageLatitude(theOther.averageLatitude), points(theOther.points) { }

	BoundingBox boundingBox;
	double averageLatitude;
	vector<Point> points;
};

Trajectory trajectoryFromFile(const string& filePath){
	ifstream infile(filePath);
	
	unsigned skipLinesFromBeginning = 6;
	char delimiter = ',';

	vector<Point> points;

	string token;
	double latitude;
	int tokensNum = 0;
	double sumLat = 0;
	while (std::getline(infile, token, delimiter)){
		if (tokensNum % 3 == 0){
			latitude = stod(token);
			sumLat += latitude;
		}
		else if (tokensNum % 3 == 1){
			// longitude
			Point p(latitude, stod(token));
			points.push_back(p);
		}
		else if (tokensNum % 3 == 2){
			// timestamp

		}
		tokensNum++;
	}

	Trajectory t(points, sumLat / (double)points.size(), BB);
	return t;
}

}