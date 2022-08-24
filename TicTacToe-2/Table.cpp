#include "Table.h"
void Table::DrawTable()
{
	DrawLineEx({ firstColl, edge }, { firstColl, rbEdge }, thickness, WHITE);
	DrawLineEx({ secondColl, edge }, { secondColl, rbEdge }, thickness, WHITE);
	DrawLineEx({ edge, firstLine }, { rbEdge, firstLine }, thickness, WHITE);
	DrawLineEx({ edge, secondLine }, { rbEdge, secondLine }, thickness, WHITE);
}