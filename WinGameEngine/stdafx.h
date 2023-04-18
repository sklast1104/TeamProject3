#pragma once

#include <io.h>

#include <locale>
#include <codecvt>

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <random>

using std::shared_ptr;
using std::weak_ptr;

#include <fstream>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;

#include <tchar.h>
#include <malloc.h>
#include <windows.h>
#include <Objbase.h>
#include <gdiplus.h>
#include <wincodec.h>
#pragma comment (lib,"Gdiplus.lib")
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "windowscodecs.lib")

#include <functional>
using std::function;

#include <algorithm>

#include "fmod.h"
#include "fmod.hpp"
#pragma comment(lib, "fmod_vc.lib")

#include <array>
using std::array;

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <list>
using std::list;

#include <map>
using std::map;
using std::make_pair;

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;
using std::wstring;

using std::to_wstring;

#include <fstream>
using std::ifstream;
using std::istringstream;

#include <functional>
using std::function;

#include <math.h>
#include <assert.h>

#include "struct.h"
#include "define.h"
#include "func.h"
#include "Mathf.h"

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")