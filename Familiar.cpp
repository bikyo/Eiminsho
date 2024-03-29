#include "Familiar.h"
#include <cmath>
#include "Define.h"


void Familiar::update_shiki() {
	if (fl > 0) {
		x += spd * cosf(ang) + vx;
		y += spd * sinf(ang) + vy;
		cnt++;
		if (x < -50 || x > Define::OUT_W + 50 ||
			y < -50 || y > Define::OUT_H + 50) {//画面から外れたら
			fl = 0;//消す
		}
	}
}

void Familiar::damage_shiki(BullP *pbul) {
	if (fl >= 10) {
		dmg = 0;
		for (int i = 0; i < BullP::CSHOT_MAX; i++) {
			if (pbul[i].fl > 0) {
				float dx = pbul[i].bx - x;
				float dy = pbul[i].by - y;
				if (dx * dx + dy * dy < ran * ran) {
					pbul[i].fl = 0;
					hp -= pbul[i].power;
					dmg += pbul[i].power;
					if (hp <= 0) fl = 0;
				}
			}
		}
	}
}