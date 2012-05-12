#ifndef SUBSETIDCRITERION_H_
#define SUBSETIDCRITERION_H_

#include "selectioncriterion.h"

class SubSetIdCriterion : public SelectionCriterion
{
protected:
	QList<int> acceptedIds;
public:
	SubSetIdCriterion();
	SubSetIdCriterion(QList<int> _acceptedIds);
	virtual ~SubSetIdCriterion();
	virtual bool isSelected(Triangle *t);
};

#endif /*SUBSETIDCRITERION_H_*/
