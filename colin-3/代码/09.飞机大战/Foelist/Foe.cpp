#include"Foe.h"

random_device Foe::rd;

Foe::Foe() {
	m_x = 0;
	m_y = 0;
	m_blood = 0;
	m_picIndex = 0;
}
Foe::~Foe() {}

void Foe::move(int step) {
	m_y += step;


}