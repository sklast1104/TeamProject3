#include "stdafx.h"
#include "DMapUI.h"

#include "DpathUI.h"
#include "DroomUI.h"

void DMapUI::EnableAllIndicator(bool _enable)
{
	for (int i = 0; i < rooms.size(); i++) {
		rooms[i]->EnableIndicator(_enable);
	}

	for (int i = 0; i < paths.size(); i++) {
		paths[i]->EnableIndicator(_enable);
	}
}

void DMapUI::EnableIndibyIdx(int _idx)
{
	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->GetId() == _idx) {
			rooms[i]->EnableIndicator(true);
			return;
		}
	}

	for (int i = 0; i < paths.size(); i++) {
		if (paths[i]->GetId() == _idx) {
			paths[i]->EnableIndicator(true);
			return;
		}
	}
}
