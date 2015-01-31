#pragma once

#include <vector>

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


}