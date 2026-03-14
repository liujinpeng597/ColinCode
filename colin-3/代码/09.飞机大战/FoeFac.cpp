#include"FoeFac.h"
#include"../09.飞机大战/Foelist/FoeSma.h"
#include"../09.飞机大战/Foelist/FoeMid.h"
#include"../09.飞机大战/Foelist/FoeBig.h"
Foe* FoeFac::createFoe(const string& type) {
	if (type == "FOESMA") {
		return new FoeSma;
	}
	else	if (type == "FOEMID") {
		return new FoeSma;
	}
	else	if (type == "FOEBIG") {
		return new FoeSma;
	}

}