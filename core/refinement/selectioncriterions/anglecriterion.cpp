#include "anglecriterion.h"
#include <cmath>
#include "../../geom/angle.h"

AngleCriterion::AngleCriterion(float topDistance, Mesh *m){
	QMap<int,Triangle*>::iterator t_i;
	for(t_i = m->getTriangles()->begin(); t_i != m->getTriangles()->end(); t_i++){
		if(maximumDistanceTo60Degrees(t_i.value())>topDistance)
			acceptedIds.push_back(t_i.value()->getId());
	}
}

float AngleCriterion::maximumDistanceTo60Degrees(Triangle *t){
	float max = 0;
	for(int i=0;i<3;i++){
		float d = fabs(t->getAngle(i).getInDegrees()-60);
		if(d>max)
			max = d;
	}
	return max;
}
