#pragma once

#include "DivUI.h"

class DroomUI;
class DpathUI;

class DMapUI :
	public DivUI
{

private :

	vector<DroomUI*> rooms;
	vector<DpathUI*> paths;

public :

	void AddRoom(DroomUI* _roomUI) { rooms.push_back(_roomUI); }
	void AddPath(DpathUI* _pathUI) { paths.push_back(_pathUI); }

	void EnableAllIndicator(bool _enable);
	void EnableIndibyIdx(int _idx);
};

