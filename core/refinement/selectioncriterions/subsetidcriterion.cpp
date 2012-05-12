#include "subsetidcriterion.h"

SubSetIdCriterion::SubSetIdCriterion(){}

SubSetIdCriterion::SubSetIdCriterion(QList<int> _acceptedIds) : SelectionCriterion()
{
	acceptedIds = _acceptedIds;
}

SubSetIdCriterion::~SubSetIdCriterion(){}

bool SubSetIdCriterion::isSelected(Triangle *t)
{
	return acceptedIds.contains(t->getId());
}
